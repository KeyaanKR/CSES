#include <bits/stdc++.h>
using namespace std;

int found = 0;

bool DFS(int u, int p, vector<vector<int>> &adj, vector<bool> &visited,
         vector<bool> &inStack, vector<int> &s) {
  if (found)
    return false;

  if (inStack[u]) {
    found = 1;
    vector<int> cycle;
    cycle.push_back(u);
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
      cycle.push_back(*it);
      if (*it == u)
        break;
    }

    cout << cycle.size() << endl;
    for (int &val : cycle)
      cout << val << " ";
    cout << endl;
    return true;
  }

  if (visited[u])
    return false;

  visited[u] = true;
  inStack[u] = true;
  s.push_back(u);

  for (int &v : adj[u]) {
    if (v != p)
      DFS(v, u, adj, visited, inStack, s);
  }

  s.pop_back();
  inStack[u] = false;

  return false;
}

int main() {
  int n, m, u, v;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> visited(n + 1, false), inStack(n + 1, false);
  vector<int> s;
  for (int i = 1; i <= n; i++) {
    if (!visited[i] && DFS(i, -1, adj, visited, inStack, s))
      break;
  }

  if (!found)
    cout << "IMPOSSIBLE\n";
  return 0;
}
