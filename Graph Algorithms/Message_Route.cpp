#include <bits/stdc++.h>
using namespace std;

void BFS(int u, vector<vector<int>> &adj, vector<int> &prev) {
  queue<int> q;
  q.push(u);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto &v : adj[u]) {
      if (prev[v] == -1) {
        prev[v] = u;
        q.push(v);
      }
    }
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

  vector<int> prev(n + 1, -1);
  prev[1] = 0;
  BFS(1, adj, prev);

  if (prev[n] == -1) {
    cout << "IMPOSSIBLE\n";
  } else {
    vector<int> path;
    int curr = n;
    while (curr != 0) {
      path.push_back(curr);
      curr = prev[curr];
    }

    cout << path.size() << "\n";
    for (auto it = path.rbegin(); it != path.rend(); it++)
      cout << *it << " ";
    cout << "\n";
  }
  return 0;
}
