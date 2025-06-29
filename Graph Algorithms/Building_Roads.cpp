#include <bits/stdc++.h>
using namespace std;

void DFS(int u, vector<vector<int>> &adj, vector<int> &visited) {
  visited[u] = 1;
  for (auto &v : adj[u]) {
    if (!visited[v])
      DFS(v, adj, visited);
  }
  return;
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

  vector<int> visited(n + 1, 0), parents;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      DFS(i, adj, visited);
      parents.push_back(i);
    }
  }

  int sz = parents.size() - 1;
  cout << sz << "\n";
  for (int i = 0; i < sz; i++)
    cout << parents[i] << " " << parents[i + 1] << "\n";
  return 0;
}
