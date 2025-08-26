#pragma once

#include <string>
#include <chrono>
#include <iostream>

enum class Priority {
    LOW,
    MEDIUM,
    HIGH
};

class Task {
public:
    Task(const std::string& description, Priority priority = Priority::MEDIUM);
    
    int getId() const;
    const std::string& getDescription() const;
    Priority getPriority() const;
    bool isCompleted() const;
    const std::chrono::system_clock::time_point& getCreationTime() const;
    
    void setDescription(const std::string& description);
    void setPriority(Priority priority);
    void setCompleted(bool completed);
    void setCreationTime(std::chrono::system_clock::time_point creationTime);
    
    std::string priorityToString() const;
    static Priority stringToPriority(const std::string& priorityStr);
    
    void display() const;
    
private:
    static int nextId;
    int id;
    std::string description;
    Priority priority;
    bool completed;
    std::chrono::system_clock::time_point creationTime;
};