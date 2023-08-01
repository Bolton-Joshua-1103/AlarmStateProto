#pragma once
#include <iostream>
#include <semaphore>
#include <functional>
#include <deque>
#include <thread>
#include <mutex>
#include <cstdint>
#include <cstdio>
#include <atomic>
#include <memory>
#include <conio.h>
class Framework {
public:

	inline static void startFramework() {
		done = false;
		keyboard_thread_ptr = std::make_shared<std::thread>(keyboardProcessor);
		heartbeat_thread_ptr = std::make_shared<std::thread>(heartbeatProcessor);
		///////////////// Consumer Code
		while (!Framework::done) {
			Framework::event_semaphore.acquire();
			std::function<void()> front_event;
			{
				const std::lock_guard<std::mutex> lock(Framework::event_mutex); //RAII mutex manager
				front_event = Framework::event_que.front();
				Framework::event_que.pop_front();
			}
			front_event();
		}
	}

	inline static void stopFramework() {
		setDone();
		keyboard_thread_ptr->join();
		heartbeat_thread_ptr->join();
		keyboard_thread_ptr.reset();
		heartbeat_thread_ptr.reset();
	}

	inline static void setHeartBeatHandler(std::function<void()> handler) {
		client_heartbeat_handler = handler;
	}

	inline static void setKeyHandler(std::function<void(char)> handler) {
		client_key_handler = handler;
	}
	inline static void setDone() {
		done = true;
	}
private:
	static std::deque<std::function<void()>> event_que;
	static std::mutex event_mutex;
	static std::counting_semaphore<INT32_MAX> event_semaphore;
	static std::function<void()> client_heartbeat_handler;
	static std::function<void(char)> client_key_handler;
	static std::atomic<bool> done;


	static std::shared_ptr<std::thread> keyboard_thread_ptr;
	static std::shared_ptr<std::thread> heartbeat_thread_ptr;



	inline static void addEvent(const std::function<void()>& event) {
		{
			const std::lock_guard<std::mutex> lock(event_mutex); //RAII mutex manager
			event_que.push_back(event);
		}
		event_semaphore.release();
	}

	inline static void keyboardProcessor() {
		using namespace std::chrono_literals;
		char cmd{};
		while (!done) {
			if (_kbhit()) {
				cmd = _getch();

				addEvent([cmd]() {
					if (client_key_handler != nullptr)
						client_key_handler(cmd);
					});
			}
			std::this_thread::sleep_for(100ms); //

		}
	}

	inline static void heartbeatProcessor() {
		using namespace std::chrono_literals;
		while (!Framework::done) {
			std::this_thread::sleep_for(1000ms); //
			Framework::addEvent([]()
				{
					if (client_heartbeat_handler != nullptr) {
						client_heartbeat_handler();
					}
				});
		}
	}

};



