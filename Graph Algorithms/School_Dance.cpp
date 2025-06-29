#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;

int BFS(vector<unordered_set<int>> &adj) {
  vector<int> parent(t + 1, -2);
  parent[s] = -1;
  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    if (u == t)
      break;

    for (auto &v : adj[u]) {
      if (parent[v] == -2) {
        parent[v] = u;
        q.push(v);
      }
    }
  }

  if (parent[t] == -2)
    return 0;

  for (int v = t; v != s; v = parent[v]) {
    adj[parent[v]].erase(v);
    adj[v].insert(parent[v]);
  }
  return 1;
}

int main() {
  int k;
  cin >> n >> m >> k;

  vector<unordered_set<int>> adj(n + m + 2);
  set<pair<int, int>> couples;
  int u, v;
  for (int i = 0; i < k; i++) {
    cin >> u >> v;
    adj[u].insert(n + v);
    couples.insert({u, n + v});
  }

  s = 0, t = n + m + 1;
  for (int i = 1; i <= n; i++)
    adj[s].insert(i);
  for (int i = 1; i <= m; i++)
    adj[n + i].insert(t);

  int totalFlow = 0, flow;
  while ((flow = BFS(adj)))
    totalFlow += flow;
  cout << totalFlow << "\n";

  for (auto &[b, g] : couples) {
    if (adj[b].count(0) && adj[g].count(b) && adj[t].count(g))
      cout << b << " " << g - n << endl;
  }
  return 0;
}
