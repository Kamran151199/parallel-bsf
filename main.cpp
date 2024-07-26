#include <iostream>
#include <vector>
#include <chrono>
#include "adj_list_repr.cpp"

// Function to measure execution time
template<typename Func, typename... Args>
double measureTime(Func func, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    func(std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    return elapsed.count();
}

int main() {
    // Example graph data
    std::vector<std::vector<int>> adjList = {
            {1, 2},       // Node 0
            {0, 3, 4},    // Node 1
            {0, 4},       // Node 2
            {1, 5},       // Node 3
            {1, 2, 5},    // Node 4
            {3, 4}        // Node 5
    };

    int start_node = 0;

    std::cout << "Starting performance comparison...\n\n";

    // Adjacency List
    std::cout << "Adjacency List Representation:\n";
    double serialTime = measureTime(serialBFSAdjList, adjList, start_node);
    double parallelTime = measureTime(parallelBFSAdjList, adjList, start_node);
    std::cout << "Serial BFS Time: " << serialTime << " seconds\n";
    std::cout << "Parallel BFS Time: " << parallelTime << " seconds\n\n";

    std::cout << "Performance comparison completed.\n";

    return 0;
}
