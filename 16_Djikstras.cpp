#include <iostream>
#include <climits>
using namespace std;

#define MAX 100  // Maximum number of vertices

// Function to find the vertex with the minimum distance value that is not yet processed
int minDistance(int dist[], bool sptSet[], int vertices) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < vertices; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to implement Dijkstra's Algorithm
void dijkstra(int graph[MAX][MAX], int vertices, int source) {
    int dist[MAX];      // Array to store the shortest distance from source
    bool sptSet[MAX];   // Boolean array to track the vertices included in the shortest path tree

    // Initialize distances as infinite and sptSet[] as false
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance to the source is always 0
    dist[source] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < vertices - 1; count++) {
        // Pick the vertex with the minimum distance value from the set of vertices not yet processed
        int u = minDistance(dist, sptSet, vertices);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update the distance value of the adjacent vertices of the picked vertex
        for (int v = 0; v < vertices; v++) {
            if (!sptSet[v] && graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INT_MAX) {
            cout << i << " \t " << "INF" << endl;
        } else {
            cout << i << " \t " << dist[i] << endl;
        }
    }
}

int main() {
    int vertices, source;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    int graph[MAX][MAX];
    cout << "Enter the adjacency matrix of the graph (use 0 for no edge):\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the source vertex: ";
    cin >> source;

    // Run Dijkstra's Algorithm
    dijkstra(graph, vertices, source);

    return 0;
}
