#include <bits/stdc++.h>
using namespace std;

int n;
using ll = long long;

ll BFS(vector<unordered_map<int, ll>> &adj) {
  int n = adj.size();

  vector<int> parent(n, -2);
  parent[0] = -1;
  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto &[v, cap] : adj[u]) {
      if (parent[v] == -2 && cap > 0) {
        parent[v] = u;
        if (v == n - 1)
          break;
        q.push(v);
      }
    }
  }

  if (parent[n - 1] == -2)
    return 0;

  ll flow = LLONG_MAX;
  for (int v = n - 1; v != 0; v = parent[v]) {
    if (flow > adj[parent[v]][v])
      flow = adj[parent[v]][v];
  }

  for (int v = n - 1; v != 0; v = parent[v]) {
    adj[parent[v]][v] -= flow;
    adj[v][parent[v]] += flow;
  }
  return flow;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);

  int m;
  cin >> n >> m;

  vector<unordered_map<int, ll>> adj(n);
  int u, v, wt;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> wt;
    u--, v--;
    adj[u][v] += wt;
  }

  ll totalFlow = 0, flow;
  while ((flow = BFS(adj)))
    totalFlow += flow;
  cout << totalFlow << "\n";
  return 0;
}
