#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>

void serialBFSAdjList(const std::vector<std::vector<int>>& graph, int start) {
    int n = graph.size();
    std::vector<bool> visited(n, false);
    std::queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        std::cout << "Visited (Serial, Adj List): " << node << std::endl;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void parallelBFSAdjList(const std::vector<std::vector<int>>& graph, int start) {
    int n = graph.size();
    std::vector<bool> visited(n, false);
    std::queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current_level_size = q.size();
        std::vector<int> nodes_to_process;

        // Extract nodes to process from the queue
#pragma omp critical
        {
            for (int i = 0; i < current_level_size; ++i) {
                if (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    nodes_to_process.push_back(node);
                }
            }
        }

        // Process nodes in parallel
#pragma omp parallel for
        for (int i = 0; i < nodes_to_process.size(); ++i) {
            int node = nodes_to_process[i];

            // Print the node being visited
#pragma omp critical
            {
                std::cout << "Visited (Parallel, Adj List): " << node << std::endl;
            }

            // Add neighbors to the queue
            for (int j = 0; j < graph[node].size(); ++j) {
                int neighbor = graph[node][j];
#pragma omp critical
                {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }
}
