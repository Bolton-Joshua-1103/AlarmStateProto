#include "Framework.hpp"


std::deque<std::function<void()>> Framework::event_que;
std::mutex Framework::event_mutex;
std::counting_semaphore<INT32_MAX> Framework::event_semaphore{ 0 };
std::atomic<bool> Framework::done{ false };
std::function<void(char)> Framework::client_key_handler{};
std::function<void()> Framework::client_heartbeat_handler{};
std::shared_ptr<std::thread> Framework::keyboard_thread_ptr{}; //RAII shenanigans
std::shared_ptr<std::thread> Framework::heartbeat_thread_ptr{};
