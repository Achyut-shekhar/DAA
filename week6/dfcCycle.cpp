#include <iostream>
#include <vector>
using namespace std;

// DFS function to detect cycle
bool dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &recStack)
{
  visited[node] = true;
  recStack[node] = true;

  for (int neighbor : graph[node])
  {
    if (!visited[neighbor])
    {
      if (dfs(neighbor, graph, visited, recStack))
        return true;
    }
    else if (recStack[neighbor])
    {
      return true; // Found a cycle
    }
  }

  recStack[node] = false; // backtrack
  return false;
}

// Cycle check for entire graph
bool hasCycle(int V, vector<vector<int>> &graph)
{
  vector<bool> visited(V, false);
  vector<bool> recStack(V, false);

  for (int i = 0; i < V; i++)
  {
    if (!visited[i])
    {
      if (dfs(i, graph, visited, recStack))
        return true;
    }
  }
  return false;
}

int main()
{
  int V, E;
  cout << "Enter number of vertices and edges: ";
  cin >> V >> E;

  vector<vector<int>> graph(V);
  cout << "Enter " << E << " directed edges (u v):\n";
  for (int i = 0; i < E; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v); // Directed edge
  }

  if (hasCycle(V, graph))
  {
    cout << "Yes Cycle Exists\n";
  }
  else
  {
    cout << "No Cycle\n";
  }

  return 0;
}
