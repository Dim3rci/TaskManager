#include "TaskManager.hpp"
#include "FileHandler.hpp"
#include <iostream>
#include <limits>

void clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

void displayMenu() {
    std::cout << "\n=== Task Manager ===\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Remove Task\n";
    std::cout << "3. Update Task\n";
    std::cout << "4. Mark Task as Completed\n";
    std::cout << "5. Display All Tasks\n";
    std::cout << "6. Display Tasks by Priority\n";
    std::cout << "7. Display Pending Tasks\n";
    std::cout << "8. Display Completed Tasks\n";
    std::cout << "9. Sort Tasks\n";
    std::cout << "10. Save Tasks to File\n";
    std::cout << "11. Load Tasks from File\n";
    std::cout << "12. Clear the Screen\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option: ";
}

void displayMenu(TaskManager& taskManager) {
    std::cout << "List of tasks: \n";
    taskManager.displayAllTasks();
    std::cout << "Press 0 to cancel\n";
}

Priority getPriorityFromUser() {
    std::cout << "Select priority (1 - Low, 2 - Medium, 3 - High): ";
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    switch (choice) {
        case 1: return Priority::LOW;
        case 2: return Priority::MEDIUM;
        case 3: return Priority::HIGH;
        default: 
            std::cout << "Invalid choice. Using Medium priority.\n";
            return Priority::MEDIUM;
    }
}

void addTask(TaskManager& taskManager) {
    std::string description;
    std::cout << "Enter task description: ";
    std::getline(std::cin, description);
    
    Priority priority = getPriorityFromUser();

    taskManager.addTask(description, priority);
}

void removeTask(TaskManager& taskManager) {
    int id;
    displayMenu(taskManager);
    std::cout << "Enter task ID to remove: ";   
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (id != 0) {
        taskManager.removeTask(id);
    }
}

void updateTask(TaskManager& taskManager) {
    int id;
    displayMenu(taskManager);
    std::cout << "Enter task ID to update: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (id != 0) {
        std::string newDescription;
        std::cout << "Enter new description: ";
        std::getline(std::cin, newDescription);
        
        Priority newPriority = getPriorityFromUser();
        taskManager.updateTask(id, newDescription, newPriority);
    }
}

void markTaskCompleted(TaskManager& taskManager) {
    int id;
    displayMenu(taskManager);
    std::cout << "Enter task ID to mark as completed: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (id != 0) {
        taskManager.markTaskCompleted(id);
    }
}

void displayTasksByPriority(TaskManager& taskManager) {
    Priority priority = getPriorityFromUser();
    taskManager.displayTasksByPriority(priority);
}

void sortTasks(TaskManager& taskManager) {
    std::cout << "Sort by:\n";
    std::cout << "1. Priority\n";
    std::cout << "2. Creation Time\n";
    std::cout << "3. Completion Status\n";
    std::cout << "0 Cancel\n";
    std::cout << "Choose an option: ";
    
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    switch (choice) {
        case 1: taskManager.sortByPriority(); break;
        case 2: taskManager.sortByCreationTime(); break;
        case 3: taskManager.sortByCompletionStatus(); break;
        case 0: break;
        default: std::cout << "Invalid choice.\n";
    }
}

void saveTasks(TaskManager& taskManager) {
    std::string filename;
    std::cout << "Enter filename to save: ";
    std::getline(std::cin, filename);
    
    FileHandler::saveToFile(taskManager, filename);
}

void loadTasks(TaskManager& taskManager) {
    std::string filename;
    std::cout << "Enter filename to load: ";
    std::getline(std::cin, filename);
   
    FileHandler::loadFromFile(taskManager, filename);
}

int main() {
    TaskManager taskManager;
    int choice;
    
    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1: addTask(taskManager); break;
            case 2: removeTask(taskManager); break;
            case 3: updateTask(taskManager); break;
            case 4: markTaskCompleted(taskManager); break;
            case 5: taskManager.displayAllTasks(); break;
            case 6: displayTasksByPriority(taskManager); break;
            case 7: taskManager.displayPendingTasks(); break;
            case 8: taskManager.displayCompletedTasks(); break;
            case 9: sortTasks(taskManager); break;
            case 10: saveTasks(taskManager); break;
            case 11: loadTasks(taskManager); break;
            case 12: clearScreen(); break;
            case 0: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 0);
    
    return 0;
}