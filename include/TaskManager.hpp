#pragma once

#include "Task.hpp"
#include <vector>
#include <memory>
#include <algorithm>

class TaskManager {
public:
    TaskManager() = default;
    
    // CRUD operations
    void addTask(const std::string& description, Priority priority = Priority::MEDIUM);
    void removeTask(int id);
    void updateTask(int id, const std::string& newDescription, Priority newPriority);
    void markTaskCompleted(int id);
    
    // Task retrieval
    std::vector<std::unique_ptr<Task>>& getTasks();
    Task* getTaskById(int id) const;
    std::vector<Task*> getTasksByPriority(Priority priority) const;
    std::vector<Task*> getPendingTasks() const;
    std::vector<Task*> getCompletedTasks() const;
    
    // Utility methods
    void displayAllTasks() const;
    void displayTasksByPriority(Priority priority) const;
    void displayPendingTasks() const;
    void displayCompletedTasks() const;
    
    // Sorting
    void sortByPriority();
    void sortByCreationTime();
    void sortByCompletionStatus();
    
private:
    std::vector<std::unique_ptr<Task>> tasks;
    
    // Helper method to find task iterator by ID
    auto findTaskIteratorById(int id);
};