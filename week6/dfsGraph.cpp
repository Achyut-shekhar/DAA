#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Graph
{
  map<int, vector<int>> adj; // adjacency list using map

public:
  // Add an undirected edge
  void addEdge(int u, int v)
  {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // DFS utility function
  bool dfs(int src, int dest, map<int, bool> &visited)
  {
    if (src == dest)
      return true;

    visited[src] = true;

    for (int neighbor : adj[src])
    {
      if (!visited[neighbor])
      {
        if (dfs(neighbor, dest, visited))
          return true;
      }
    }

    return false;
  }

  // Check if path exists
  bool isPathExists(int src, int dest)
  {
    map<int, bool> visited;
    return dfs(src, dest, visited);
  }
};

int main()
{
  Graph g;

  // Sample edges
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 4);
  g.addEdge(3, 5);
  g.addEdge(5, 6);

  int src = 1, dest = 6;

  if (g.isPathExists(src, dest))
    cout << "Yes Path Exists" << endl;
  else
    cout << "No Such Path Exists" << endl;

  return 0;
}
