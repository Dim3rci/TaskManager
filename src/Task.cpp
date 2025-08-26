#include "Task.hpp"
#include <map>

int Task::nextId = 1;

Task::Task(const std::string& description, Priority priority)
    : id(nextId++), description(description), priority(priority), 
      completed(false), creationTime(std::chrono::system_clock::now()) {}

int Task::getId() const {
    return id;
}

const std::string& Task::getDescription() const {
    return description;
}

Priority Task::getPriority() const {
    return priority;
}

bool Task::isCompleted() const {
    return completed;
}

const std::chrono::system_clock::time_point& Task::getCreationTime() const {
    return creationTime;
}

void Task::setDescription(const std::string& description) {
    this->description = description;
}

void Task::setPriority(Priority priority) {
    this->priority = priority;
}

void Task::setCompleted(bool completed) {
    this->completed = completed;
}

void Task::setCreationTime(std::chrono::system_clock::time_point creationTime) {
    this->creationTime = creationTime;
}

std::string Task::priorityToString() const {
    static const std::map<Priority, std::string> priorityMap = {
        {Priority::LOW, "Low"},
        {Priority::MEDIUM, "Medium"},
        {Priority::HIGH, "High"}
    };
    
    return priorityMap.at(priority);
}

Priority Task::stringToPriority(const std::string& priorityStr) {
    static const std::map<std::string, Priority> priorityMap = {
        {"low", Priority::LOW},
        {"medium", Priority::MEDIUM},
        {"high", Priority::HIGH}
    };
    
    auto it = priorityMap.find(priorityStr);
    if (it != priorityMap.end()) {
        return it->second;
    }
    return Priority::MEDIUM;
}

void Task::display() const {
    std::time_t creationTimeT = std::chrono::system_clock::to_time_t(creationTime);
    std::cout << "ID: " << id 
              << " | Description: " << description 
              << " | Priority: " << priorityToString()
              << " | Status: " << (completed ? "Completed" : "Pending")
              << " | Created: " << std::ctime(&creationTimeT);
}