#include "FileHandler.hpp"
#include <fstream>
#include <iostream>

bool FileHandler::saveToFile(TaskManager& taskManager, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error: Cannot open file " << filename << " for writing.\n";
        return false;
    }
    
    for (const auto& task : taskManager.getTasks()) {
        outFile << task->getId() << ","
                << task->getDescription() << ","
                << static_cast<int>(task->getPriority()) << ","
                << task->isCompleted() << ","
                << std::chrono::system_clock::to_time_t(task->getCreationTime()) << "\n";
    }
    
    outFile.close();
    std::cout << "Tasks saved to " << filename << " successfully!\n";
    return true;
}

bool FileHandler::loadFromFile(TaskManager& taskManager, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error: Cannot open file " << filename << " for reading.\n";
        return false;
    }
    TaskManager newTaskManager;
    
    std::string line;

    // Parse through CSV file
    while (std::getline(inFile, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);
        size_t pos4 = line.find(',', pos3 + 1);
        
        if (pos1 == std::string::npos || pos2 == std::string::npos || 
            pos3 == std::string::npos || pos4 == std::string::npos) {
            continue;
        }
        
        try {
            // Extract fields
            std::string description = line.substr(pos1 + 1, pos2 - pos1 - 1);
            Priority priority = static_cast<Priority>(std::stoi(line.substr(pos2 + 1, pos3 - pos2 - 1)));
            bool completed = std::stoi(line.substr(pos3 + 1, pos4 - pos3 - 1)) != 0;
            time_t creationTime = std::stol(line.substr(pos4 + 1));
            
            // Create task
            auto task = std::make_unique<Task>(description, priority);
            task->setCompleted(completed);
            task->setCreationTime(std::chrono::system_clock::from_time_t(creationTime));
             
            // Add to task manager
            newTaskManager.getTasks().push_back(std::move(task));
        } catch (const std::exception& e) {
            std::cerr << "Error parsing line: " << line << " - " << e.what() << "\n";
        }
    }
    
    inFile.close();
    taskManager = std::move(newTaskManager);
    std::cout << "Tasks loaded from " << filename << " successfully!\n";
    return true;
}