#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS
void dfs(int currentNode, vector<vector<int>>& adjList, vector<bool>& visited) {
    // Mark the current node as visited
    visited[currentNode] = true;
    cout << currentNode << " ";  // Process the current node

    // Recursively visit all unvisited neighbors
    for (int neighbor : adjList[currentNode]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<vector<int>> adjList(vertices);  // Adjacency list representation of the graph

    cout << "Enter the edges (u v) (0-based indexing):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Uncomment this for an undirected graph
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    vector<bool> visited(vertices, false);  // To keep track of visited nodes

    // Perform DFS
    cout << "DFS Traversal: ";
    dfs(startNode, adjList, visited);
    cout << endl;

    return 0;
}
