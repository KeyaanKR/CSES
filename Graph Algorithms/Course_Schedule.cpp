#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  vector<int> indegree(n, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    indegree[v]++;
  }

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0)
      q.push(i);
  }

  vector<int> order;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    order.push_back(u + 1);

    for (auto &v : adj[u]) {
      if (--indegree[v] == 0)
        q.push(v);
    }
  }

  if (order.size() < n) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  for (auto &u : order)
    cout << u << " ";
  cout << endl;
  return 0;
}
