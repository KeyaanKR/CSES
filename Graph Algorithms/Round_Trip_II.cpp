#include <bits/stdc++.h>
using namespace std;

bool DFS(int u, int n, vector<vector<int>> &adj, vector<int> &visited,
         vector<int> &inRecStack, vector<int> &stack) {
  if (inRecStack[u]) {
    vector<int> path;
    path.push_back(u);
    for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
      path.push_back(*it);
      if (*it == u)
        break;
    }
    cout << path.size() << endl;
    for (auto it = path.rbegin(); it != path.rend(); ++it)
      cout << *it + 1 << " ";
    cout << endl;
    return true;
  }

  if (visited[u])
    return false;

  visited[u] = 1;
  inRecStack[u] = 1;
  stack.push_back(u);

  for (auto &v : adj[u]) {
    if (DFS(v, n, adj, visited, inRecStack, stack))
      return true;
  }

  stack.pop_back();
  inRecStack[u] = 0;
  return false;
}

int main() {
  int n, m, u, v;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  vector<int> indegree(n, 0);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    if (u != v) {
      u--, v--;
      adj[u].push_back(v);
      indegree[v]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0)
      q.push(i);
  }

  vector<int> visited(n, 0);
  int nodesVisited = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    visited[u] = 1;
    nodesVisited++;
    for (auto &v : adj[u]) {
      if (--indegree[v] == 0)
        q.push(v);
    }
  }

  if (nodesVisited == n) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  vector<int> inRecStack(n, 0), stack;
  for (int i = 0; i < n; i++) {
    if (!visited[i] && DFS(i, n, adj, visited, inRecStack, stack))
      break;
  }
  return 0;
}
