#include <bits/stdc++.h>
using namespace std;

void BFS(int u, vector<vector<int>> &adj, vector<int> &team) {
  queue<int> q;
  q.push(u);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto &v : adj[u]) {
      if (!team[v]) {
        team[v] = team[u] == 1 ? 2 : 1;
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

  vector<int> team(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (!team[i]) {
      team[i] = 1;
      BFS(i, adj, team);
    }
  }

  bool flag = true;
  for (int u = 1; u <= n && flag; u++) {
    for (auto &v : adj[u]) {
      if (team[u] == team[v]) {
        flag = false;
        break;
      }
    }
  }

  if (!flag) {
    cout << "IMPOSSIBLE\n";
  } else {
    for (int i = 1; i <= n; i++)
      cout << team[i] << " ";
    cout << "\n";
  }

  return 0;
}
