#include <bits/stdc++.h>
using namespace std;

void DFS(int u, vector<vector<pair<int, int>>> &adj, vector<int> visited,
         vector<int> &path) {
  while (!adj[u].empty()) {
    auto edge = adj[u].back(); // safe copy
    adj[u].pop_back();
    if (!visited[edge.second]) {
      visited[edge.second] = 1;
      DFS(edge.first, adj, visited, path);
    }
  }
  path.push_back(u + 1);
}

int main() {
  int n, m, u, v;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n);
  vector<int> degree(n, 0);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
    degree[u]++, degree[v]++;
  }

  for (int i = 0; i < n; i++) {
    if (degree[i] % 2 != 0) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }

  vector<int> visited(m, 0), path;
  DFS(0, adj, visited, path);

  if (path.size() != m + 1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  for (auto &node : path)
    cout << node << " ";
  cout << endl;
  return 0;
}
