
# Parallel BFS using Adjacency List Representation

## Overview

This project demonstrates the implementation of Breadth-First Search (BFS) using both serial and parallel approaches. The parallel version utilizes OpenMP to achieve parallelism. The graph is represented using an adjacency list, which efficiently stores sparse graphs.

## Project Structure

- **main.cpp**: Contains the main function and demonstrates the usage of serial and parallel BFS implementations.
- **adj_list_repr.cpp**: Contains the implementation of BFS functions, `serialBFSAdjList` and `parallelBFSAdjList`.
- **CMakeLists.txt**: CMake configuration file for building the project.

## Requirements

- **C++11 or later**: The project uses modern C++ features.
- **OpenMP**: Required for the parallel implementation of BFS. Ensure you have a compiler that supports OpenMP (e.g., GCC).
- **CMake**: To build the project.

## Setup and Compilation

### Prerequisites

1. **GCC**: Install GCC if not already installed. You can use Homebrew on macOS:
   ```bash
   brew install gcc
   ```

2. **CMake**: Ensure CMake is installed on your system. You can also install it via Homebrew:
   ```bash
   brew install cmake
   ```

### Building the Project

1. Clone the repository (if it's hosted somewhere like GitHub):
   ```bash
   git clone https://github.com/Kamran151199/parallel-bsf
   cd parallel-bfs
   ```

2. Configure the project using CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   ```

3. Build the project:
   ```bash
   make
   ```

4. Run the executable:
   ```bash
   ./parallel-bfs
   ```

## How to Use

- The program runs both the serial and parallel BFS algorithms on a sample graph defined in `main.cpp`.
- Modify the graph in `main.cpp` to test different scenarios.

## Files and Key Functions

### main.cpp

- **main()**: The entry point of the program, which initializes a sample graph and calls the BFS functions.

### adj_list_repr.cpp

- **serialBFSAdjList(const std::vector<std::vector<int>>& graph, int start)**: Performs a BFS traversal in serial mode.
- **parallelBFSAdjList(const std::vector<std::vector<int>>& graph, int start)**: Performs a BFS traversal using OpenMP for parallelism.

### CMakeLists.txt

- Configures the build process, including setting the C++ standard and finding the OpenMP package.

## Issues and Contributions

If you encounter any issues or have suggestions for improvements, please open an issue or submit a pull request.

