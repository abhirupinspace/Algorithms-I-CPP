#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100  // Maximum number of vertices

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Find the parent of a node using path compression
int find(int parent[], int i) {
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = find(parent, parent[i]);  // Path compression
}

// Union of two subsets using union by rank
void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Comparator function to sort edges by weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to implement Kruskal's Algorithm
void kruskalMST(int graph[MAX][MAX], int vertices) {
    vector<Edge> edges;
    int parent[MAX], rank[MAX];

    // Initialize disjoint set
    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Convert adjacency matrix to edge list
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            if (graph[i][j] != 0) {
                Edge edge;
                edge.u = i;
                edge.v = j;
                edge.weight = graph[i][j];
                edges.push_back(edge);
            }
        }
    }

    // Sort the edges in ascending order by weight
    sort(edges.begin(), edges.end(), compare);

    cout << "Edge \tWeight\n";

    // Iterate through all edges and add to MST if no cycle is formed
    for (Edge e : edges) {
        int u = e.u;
        int v = e.v;

        // Check if the selected edge forms a cycle
        if (find(parent, u) != find(parent, v)) {
            cout << u << " - " << v << "\t" << e.weight << "\n";
            unionSets(parent, rank, u, v);  // Include this edge in MST
        }
    }
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

    // Run Kruskal's Algorithm
    kruskalMST(graph, vertices);

    return 0;
}
