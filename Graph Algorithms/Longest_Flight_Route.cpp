#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, u, v;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
  }

  vector<vector<int>> temp(n);
  queue<int> bfs;
  vector<int> visited(n, 0), indegree(n, 0);
  visited[0] = 1;
  bfs.push(0);

  while (!bfs.empty()) {
    int u = bfs.front();
    bfs.pop();

    for (auto &v : adj[u]) {
      temp[u].push_back(v);
      indegree[v]++;
      if (!visited[v]) {
        visited[v] = 1;
        bfs.push(v);
      }
    }
  }
  if (!visited[n - 1]) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  queue<int> q;
  q.push(0);
  vector<int> dist(n, INT_MIN);
  dist[0] = 0;

  vector<int> parent(n, -1);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    if (u == n - 1)
      break;

    for (auto &v : temp[u]) {
      if (dist[v] < dist[u] + 1) {
        dist[v] = dist[u] + 1;
        parent[v] = u;
      }
      if (--indegree[v] == 0)
        q.push(v);
    }
  }

  int cur = n - 1;
  vector<int> path;
  while (cur != -1) {
    path.push_back(cur + 1);
    cur = parent[cur];
  }
  cout << dist[n - 1] + 1 << endl;
  for (auto it = path.rbegin(); it != path.rend(); ++it)
    cout << *it << " ";
  cout << endl;
  return 0;
}
