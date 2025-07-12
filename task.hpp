#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <functional>
#include <iostream>

enum class TaskState {
    READY,
    BLOCKED,
    COMPLETED
};

class Task {
private:
    std::string name;
    int priority;
    TaskState state;
    std::function<void()> workFunction;
    int blockTicks = 0;

public:
    Task(std::string name, int priority, std::function<void()> work)
        : name(name), priority(priority), state(TaskState::READY), workFunction(work) {}

    void runOnce() {
        if (state == TaskState::READY) {
            std::cout << "[" << name << "] Running...\n";
            workFunction();
        }
    }

    void block(int ticks) {
        blockTicks = ticks;
        state = TaskState::BLOCKED;
        std::cout << "[" << name << "] Blocked for " << ticks << " ticks.\n";
    }

    void tick() {
        if (state == TaskState::BLOCKED && blockTicks > 0) {
            blockTicks--;
            if (blockTicks == 0) {
                state = TaskState::READY;
                std::cout << "[" << name << "] Unblocked and READY.\n";
            }
        }
    }

    std::string getName() const { return name; }
    int getPriority() const { return priority; }
    TaskState getState() const { return state; }

    void setState(TaskState newState) { state = newState; }
};

#endif // TASK_HPP
