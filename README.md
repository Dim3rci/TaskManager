# 📋 Task Manager - Console Application

A modern console-based task management system built with C++17, featuring clean architecture and adherence to modern C++ best practices.

## ✨ Features

- **Complete CRUD Operations**: Create, read, update, and delete tasks
- **Priority System**: Three priority levels (Low, Medium, High)
- **File Persistence**: Save and load tasks from CSV files
- **Advanced Filtering**: View tasks by priority or completion status
- **Multiple Sorting Options**: Sort by priority, creation time, or completion status
- **Intuitive Console Interface**: User-friendly menu system

## 🚀 Getting Started

### Prerequisites

- C++17 Compiler: GCC, Clang, or MSVC
- Make (for Makefile build) or CMake (for CMake build)
- Git (for cloning repository)

### Installation

1. Clone the repository
```bash
   git clone https://github.com/yourusername/task-manager.git
   cd task-manager
```
2. Build with Make
   ```bash
     make
   ```
3. Run the application

   ```bash
     ./task_manager.exe
   ```

## 🎮 Usage

### Main Menu Options

<img width="272" height="346" alt="image" src="https://github.com/user-attachments/assets/a900c467-cca3-4499-a281-f4948a2042e6" />

To interract with the Task Manager, type a number corresponding with one of the showed action.

### Example

#### Adding a task:

<img width="535" height="404" alt="image" src="https://github.com/user-attachments/assets/23152571-4c84-4252-909f-de4785968a85" />

#### Saving tasks:

<img width="391" height="71" alt="image" src="https://github.com/user-attachments/assets/8c0c8f73-2096-4705-b18a-08ac1c6e3d74" />

## 📁 File Format:

Tasks are saved in CSV format:

<img width="498" height="79" alt="image" src="https://github.com/user-attachments/assets/7b4bd6c6-f542-4fc2-b22e-5638a62f8944" />

## 📋 Documentaion

A full documentation can be generate with the help of Doxygen;

### To do so:

1. Install Doxygen
2. At the root of the project, execute `doxygen Doxyfile`
3. Go to the folder `docs/html`
4. `open index.html` for MacOs, `start index.html` for Windows and `xdg-open` for Linux


## 🔧 Development

### Code Structure

- **Task Class**: Represents individual tasks with properties and methods
- **TaskManager Class**: Manages collection of tasks with CRUD operations
- **FileHandler Class**: Handles file I/O operations for persistence
- **Main Application**: Provides user interface and menu system

### Adding New Features

- Follow the existing architecture patterns
- Add new header files to include/ directory
- Implement new functionality in src/ directory
- Update the main menu in main.cpp if needed
- Rebuild and test thoroughly
