#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> parent;

int BFS(vector<unordered_map<int, int>> &adj) {
  parent = vector<int>(n, -2);
  parent[0] = -1;
  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    if (u == n - 1)
      break;

    for (auto &[v, cap] : adj[u]) {
      if (parent[v] == -2 && cap > 0) {
        parent[v] = u;
        q.push(v);
      }
    }
  }

  if (parent[n - 1] == -2)
    return 0;

  int flow = INT_MAX;
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

  vector<unordered_map<int, int>> adj(n);
  vector<pair<int, int>> edges;
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    adj[u][v] += 1;
    adj[v][u] += 1;
    edges.push_back({u, v});
  }

  int totalFlow = 0, flow;
  while ((flow = BFS(adj)))
    totalFlow += flow;
  cout << totalFlow << "\n";

  for (auto &[u, v] : edges) {
    if ((parent[u] != -2 && parent[v] == -2 && !adj[u][v] && adj[v][u]) ||
        (parent[v] != -2 && parent[u] == -2 && !adj[v][u] && adj[u][v]))
      cout << u + 1 << " " << v + 1 << endl;
  }

  return 0;
}
