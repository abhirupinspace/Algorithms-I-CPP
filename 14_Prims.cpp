#include <iostream>
#include <climits>
using namespace std;

#define MAX 100  // Maximum number of vertices

// Function to find the vertex with the smallest key value that is not yet included in the MST
int findMinKey(int key[], bool mstSet[], int vertices) {
    int minKey = INT_MAX;
    int minIndex;

    for (int v = 0; v < vertices; v++) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the constructed MST
void printMST(int parent[], int graph[MAX][MAX], int vertices) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < vertices; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

// Prim's Algorithm to find the MST
void primMST(int graph[MAX][MAX], int vertices) {
    int parent[MAX];  // To store the MST
    int key[MAX];     // Key values to pick the minimum weight edge
    bool mstSet[MAX]; // To represent vertices included in the MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Start from the first vertex
    key[0] = 0;      // First node is picked first
    parent[0] = -1;  // Root node has no parent

    // The MST will have `vertices` vertices
    for (int count = 0; count < vertices - 1; count++) {
        // Pick the minimum key vertex not yet included in the MST
        int u = findMinKey(key, mstSet, vertices);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update key and parent for the adjacent vertices
        for (int v = 0; v < vertices; v++) {
            // Update the key only if the graph[u][v] is non-zero, vertex `v` is not in MST,
            // and the new key value is smaller than the current key value
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    printMST(parent, graph, vertices);
}

int main() {
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    int graph[MAX][MAX];
    cout << "Enter the adjacency matrix of the graph (use 0 for no edge):\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cin >> graph[i][j];
        }
    }

    // Run Prim's Algorithm
    primMST(graph, vertices);

    return 0;
}
