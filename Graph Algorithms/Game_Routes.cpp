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
  queue<int> q;
  q.push(0);

  int MOD = 1e9 + 7;
  vector<int> ways(n, 0);
  ways[0] = 1;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    if (u == n - 1)
      break;

    for (auto &v : temp[u]) {
      ways[v] = (ways[v] + ways[u]) % MOD;
      if (--indegree[v] == 0)
        q.push(v);
    }
  }

  cout << ways[n - 1] << endl;
  return 0;
}
