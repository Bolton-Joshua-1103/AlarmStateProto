# AlarmStateProto
5 State, State Machine simulating an alarm system that responds to ON/OFF commands, simulated motion, and timed events.

This project uses a Framework to queue up keyboard and timed events that a Controller then processes and behaves according.

This project utilizes concurrent 'producer' threads that queue up different types of events that are then 'consumed' by a seperate thread. The controller then responds to the events to have the correct behavior, according to the state diagram.

The entire system follows a state diagram where each event correctly responds to three inputs (Password entered (keyboard input), Motion detected (keyboard input), or time expiring(timed event).

This project utilizes many programming features to increase efficiency and robustness, examples are:
- Concurrent threads that have a 'producer\consumer' relationship with a common container.
- By using lock guards, mutexes, and RAII principles, concurrent threads are able to perform operations on a common container.
- Counting Semaphores are used to stop busy waiting conditions
- All states are user defined types that inherit from a state_base_handler. This state_base_handler has virtual methods that allow each state is able to handle all inputs (even if no affect is desired from a particular state)
- Utilizes a design pattern of CALL BACKS, by using these call backs each state is able to request/access Controller level services like, sounding the alarm if a state requires it, or accessing a stopwatch for timed events. This allows each state to provide features without decentralizing services.
- The controller uses an encapsulated Stopwatch class that was developed for this application. This class uses the std::chrono library inorder to provide services similar to stop watch. You can stop and start the stop watch as well as view the duration and reset the duration.
