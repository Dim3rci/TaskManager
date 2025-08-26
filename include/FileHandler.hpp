#pragma once

#include "TaskManager.hpp"
#include <string>

class FileHandler {
public:
    static bool saveToFile(TaskManager& taskManager, const std::string& filename);
    static bool loadFromFile(TaskManager& taskManager, const std::string& filename);
};