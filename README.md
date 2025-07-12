# RTOS Task Scheduler Simulation

This is a C++ simulation of a basic Real-Time Operating System (RTOS) task scheduler, designed to mimic cooperative multitasking behavior in embedded systems. The project focuses on simulating key RTOS concepts such as task states, priority-based scheduling, blocking/unblocking, and tick-based execution.

## Overview

The scheduler runs a fixed set of tasks, each with a defined priority and behavior. Tasks can be in one of several states (`READY`, `BLOCKED`, or `COMPLETED`). On each tick, the scheduler selects the highest-priority task that is in the `READY` state and runs its `workFunction()` once. Tasks can block themselves for a specific number of ticks, after which they are automatically returned to the `READY` state.

The system does not use preemption or real threading per task. Instead, it uses cooperative scheduling where the main scheduler loop drives execution in a controlled, simulated environment.

## Features

- Cooperative multitasking with priority-based scheduling
- Simulated task states: `READY`, `BLOCKED`, `COMPLETED`
- Tick-based execution model
- Task blocking and automatic unblocking after N ticks
- Console output for debugging and state transitions

## File Structure

```
rtos_sim/
├── main.cpp             # Entry point and task definitions
├── task.hpp             # Task class with state management and execution logic
├── scheduler.hpp        # Scheduler that manages and runs tasks
```

## Example Output

```
[Scheduler] Tick 1
[Task B] Running...
[Scheduler] Tick 2
[Task B] Running...
[Scheduler] Tick 3
[Task B] Running...
[Task B] Blocked for 3 ticks.
[Scheduler] Tick 4
[Task A] Running...
[Scheduler] Tick 5
[Task A] Running...
[Scheduler] Tick 6
[Task B] Unblocked and READY.
[Task B] Running...
```

## How to Run

1. Make sure you have a modern C++ compiler with thread support (e.g. g++ 9+).
2. Compile with the following command (tested on MSYS2 MinGW64):

   ```bash
   g++ main.cpp -o rtos_sim -pthread
   ```

3. Run the executable:

   ```bash
   ./rtos_sim
   ```

## Concepts Practiced

- RTOS scheduling fundamentals
- Cooperative multitasking
- State-driven task execution
- Simulating real-time constraints without external libraries
- Writing modular C++ for embedded system modeling

## Future Improvements

- Add semaphore or mutex simulation
- Support task completion and removal
- Simulate timer interrupts
- Log execution history to a file

## Author

Developed by Sarab Aulakh as a firmware simulation project to practice real-time systems, task scheduling, and embedded development principles using C++.
