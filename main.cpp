#include "scheduler.hpp"

int main() {
    Scheduler scheduler;

    int taskB_runs = 0;

    std::shared_ptr<Task> taskA = std::make_shared<Task>("Task A", 1, []() {
        std::cout << "  Task A is doing light work.\n";
    });

    std::shared_ptr<Task> taskB;

    taskB = std::make_shared<Task>("Task B", 2, [&]() {
        std::cout << "  Task B is handling critical task!\n";
        taskB_runs++;

        if (taskB_runs == 3) {
            taskB->block(3);
            std::cout << "  [Logic] Blocking Task B for 3 ticks\n";
        }
    });

    scheduler.addTask(taskA);
    scheduler.addTask(taskB);

    scheduler.start();

    return 0;
}
