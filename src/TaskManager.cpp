#include "TaskManager.hpp"
#include <iostream>

auto TaskManager::findTaskIteratorById(int id) {
    return std::find_if(tasks.begin(), tasks.end(),
        [id](const auto& task) { return task->getId() == id; });
}

void TaskManager::addTask(const std::string& description, Priority priority) {
    tasks.push_back(std::make_unique<Task>(description, priority));
    std::cout << "Task added successfully!\n";
}

void TaskManager::removeTask(int id) {
    auto it = findTaskIteratorById(id);
    if (it != tasks.end()) {
        tasks.erase(it);
        std::cout << "Task removed successfully!\n";
    } else {
        std::cout << "Task with ID " << id << " not found.\n";
    }
}

void TaskManager::updateTask(int id, const std::string& newDescription, Priority newPriority) {
    auto it = findTaskIteratorById(id);
    if (it != tasks.end()) {
        (*it)->setDescription(newDescription);
        (*it)->setPriority(newPriority);
        std::cout << "Task updated successfully!\n";
    } else {
        std::cout << "Task with ID " << id << " not found.\n";
    }
}

void TaskManager::markTaskCompleted(int id) {
    auto it = findTaskIteratorById(id);
    if (it != tasks.end()) {
        (*it)->setCompleted(true);
        std::cout << "Task marked as completed!\n";
    } else {
        std::cout << "Task with ID " << id << " not found.\n";
    }
}

std::vector<std::unique_ptr<Task>>& TaskManager::getTasks() {
    return tasks;
}

Task* TaskManager::getTaskById(int id) const {
    auto it = std::find_if(tasks.begin(), tasks.end(), 
        [id](const auto& task) { return task->getId() == id; });
    
    return (it != tasks.end()) ? it->get() : nullptr;
}

std::vector<Task*> TaskManager::getTasksByPriority(Priority priority) const {
    std::vector<Task*> result;
    for (const auto& task : tasks) {
        if (task->getPriority() == priority) {
            result.push_back(task.get());
        }
    }
    return result;
}

std::vector<Task*> TaskManager::getPendingTasks() const {
    std::vector<Task*> result;
    for (const auto& task : tasks) {
        if (!task->isCompleted()) {
            result.push_back(task.get());
        }
    }
    return result;
}

std::vector<Task*> TaskManager::getCompletedTasks() const {
    std::vector<Task*> result;
    for (const auto& task : tasks) {
        if (task->isCompleted()) {
            result.push_back(task.get());
        }
    }
    return result;
}

void TaskManager::displayAllTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }
    
    for (const auto& task : tasks) {
        task->display();
    }
}

void TaskManager::displayTasksByPriority(Priority priority) const {
    auto filteredTasks = getTasksByPriority(priority);
    if (filteredTasks.empty()) {
        std::cout << "No tasks with this priority.\n";
        return;
    }
    
    for (const auto& task : filteredTasks) {
        task->display();
    }
}

void TaskManager::displayPendingTasks() const {
    auto pendingTasks = getPendingTasks();
    if (pendingTasks.empty()) {
        std::cout << "No pending tasks.\n";
        return;
    }
    
    for (const auto& task : pendingTasks) {
        task->display();
    }
}

void TaskManager::displayCompletedTasks() const {
    auto completedTasks = getCompletedTasks();
    if (completedTasks.empty()) {
        std::cout << "No completed tasks.\n";
        return;
    }
    
    for (const auto& task : completedTasks) {
        task->display();
    }
}

void TaskManager::sortByPriority() {
    std::sort(tasks.begin(), tasks.end(), 
        [](const auto& a, const auto& b) {
            return static_cast<int>(a->getPriority()) > static_cast<int>(b->getPriority());
        });
}

void TaskManager::sortByCreationTime() {
    std::sort(tasks.begin(), tasks.end(), 
        [](const auto& a, const auto& b) {
            return a->getCreationTime() < b->getCreationTime();
        });
}

void TaskManager::sortByCompletionStatus() {
    std::sort(tasks.begin(), tasks.end(), 
        [](const auto& a, const auto& b) {
            return a->isCompleted() < b->isCompleted();
        });
}