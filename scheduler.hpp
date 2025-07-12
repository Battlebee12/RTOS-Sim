#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include "task.hpp"
#include <vector>
#include <memory>
#include <algorithm>
#include <chrono>
#include <thread>

class Scheduler
{
private:
    std::vector<std::shared_ptr<Task>> taskList;
    bool running = false;

public:
    void addTask(std::shared_ptr<Task> task)
    {
        taskList.push_back(task);
    }

    void start(int ticks = 10)
    {
        std::cout << "[Scheduler] Starting cooperative scheduler...\n";
        running = true;

        for (int i = 0; i < ticks && running; ++i)
        {
            std::cout << "[Scheduler] Tick " << i + 1 << "\n";

            // Let all tasks update their internal timers
            for (auto &task : taskList)
            {
                task->tick(); // <-- NEW
            }

            std::sort(taskList.begin(), taskList.end(), [](const auto &a, const auto &b)
                      { return a->getPriority() > b->getPriority(); });

            for (auto &task : taskList)
            {
                if (task->getState() == TaskState::READY)
                {
                    task->runOnce();
                    break;
                }
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

        std::cout << "[Scheduler] Stopped.\n";
    }

    void stop()
    {
        running = false;
    }
};

#endif // SCHEDULER_HPP
