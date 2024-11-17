#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function to perform BFS
void bfs(int startNode, vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;  // Queue to keep track of nodes to visit
    q.push(startNode);  // Start from the source node
    visited[startNode] = true;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int currentNode = q.front();  // Get the front node in the queue
        q.pop();
        cout << currentNode << " ";  // Visit the current node

        // Explore all adjacent nodes
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);  // Add unvisited neighbor to the queue
            }
        }
    }
    cout << endl;
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

    // Perform BFS
    bfs(startNode, adjList, visited);

    return 0;
}
