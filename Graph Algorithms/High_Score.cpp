#include <bits/stdc++.h>
using namespace std;

bool path(int u, int v, vector<vector<int>> &adj) {
  vector<bool> visited(adj.size(), false);
  stack<int> s;
  s.push(u);

  while (!s.empty()) {
    int node = s.top();
    s.pop();

    if (node == v)
      return true;
    if (visited[node])
      continue;

    visited[node] = true;
    for (int neighbor : adj[node]) {
      if (!visited[neighbor]) {
        s.push(neighbor);
      }
    }
  }

  return false;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<array<int, 3>> edges(m);
  vector<vector<int>> adj(n);
  vector<int> inCycle(n, 0);

  for (auto &edge : edges) {
    cin >> edge[0] >> edge[1] >> edge[2];
    edge[0]--;
    edge[1]--;
    adj[edge[0]].push_back(edge[1]);
  }

  vector<long long> dist(n, -1e16);
  dist[0] = 0;

  for (int i = 0; i < n; i++) {
    for (auto &edge : edges) {
      auto &[u, v, wt] = edge;
      if (dist[v] < dist[u] + wt) {
        dist[v] = dist[u] + wt;
        if (i == n - 1)
          inCycle[v] = 1;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (inCycle[i] && path(0, i, adj) && path(i, n - 1, adj)) {
      cout << "-1" << endl;
      return 0;
    }
  }

  cout << dist[n - 1] << endl;
  return 0;
}
