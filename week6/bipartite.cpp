#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS function to check one connected component
bool bfsCheck(int start, vector<vector<int>>& graph, vector<int>& color) {
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[node]; // Assign opposite color
                q.push(neighbor);
            } else if (color[neighbor] == color[node]) {
                return false; // Same color on both ends -> not bipartite
            }
        }
    }
    return true;
}

// Main function to check bipartiteness of the whole graph
bool isBipartite(int V, vector<vector<int>>& graph) {
    vector<int> color(V, -1); // -1 means unvisited

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!bfsCheck(i, graph, color)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> graph(V);
    cout << "Enter " << E << " edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Because it's undirected
    }

    cout << (isBipartite(V, graph) ? "Yes Bipartite\n" : "Not Bipartite\n");
    return 0;
}
