#include <bits/stdc++.h>
using namespace std;

void DFS(int u, vector<vector<int>> &adj, vector<int> &path) {
  while (!adj[u].empty()) {
    auto v = adj[u].back();
    adj[u].pop_back();
    DFS(v, adj, path);
  }
  path.push_back(u + 1);
}

int main() {
  int n, m, u, v;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  vector<int> in(n, 0), out(n, 0);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    in[v]++, out[u]++;
  }

  int S = 0, M = 0, E = 0;
  u = -1, v = -1;
  for (int i = 0; i < n; i++) {
    if (in[i] == out[i]) {
      M++;
    } else if (in[i] - out[i] == +1) {
      E++;
      v = i;
    } else if (in[i] - out[i] == -1) {
      S++;
      u = i;
    }
  }

  if (M != n - 2 || S != 1 || E != 1 || u != 0 || v != n - 1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  vector<int> path;
  DFS(0, adj, path);

  if (path.size() != m + 1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  for (auto it = path.rbegin(); it != path.rend(); ++it)
    cout << *it << " ";
  cout << endl;
  return 0;
}
