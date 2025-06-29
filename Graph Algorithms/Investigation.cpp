#include <bits/stdc++.h>
#include <climits>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
using P = pair<long long, int>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].emplace_back(v, w);
  }

  vector<ll> dist(n, LLONG_MAX);
  dist[0] = 0;
  priority_queue<P, vector<P>, greater<>> pq;
  pq.push({dist[0], 0});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (d > dist[u])
      continue;

    if (u == n - 1)
      break;

    for (auto &[v, w] : adj[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }

  vector<int> indegree(n, 0);
  for (int u = 0; u < n; u++) {
    for (auto &[v, wt] : adj[u]) {
      if (dist[u] + wt == dist[v])
        indegree[v]++;
    }
  }

  vector<int> pathCount(n, 0), minPath(n, INT_MAX), maxPath(n, INT_MIN);
  pathCount[0] = 1;
  minPath[0] = 0;
  maxPath[0] = 0;

  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto &[v, wt] : adj[u]) {
      if (dist[u] + wt == dist[v]) {
        pathCount[v] = (pathCount[v] + pathCount[u]) % MOD;
        minPath[v] = min(minPath[v], minPath[u] + 1);
        maxPath[v] = max(maxPath[v], maxPath[u] + 1);
        if (--indegree[v] == 0)
          q.push(v);
      }
    }
  }

  cout << dist[n - 1] << " " << pathCount[n - 1] << " " << minPath[n - 1] << " "
       << maxPath[n - 1] << endl;

  return 0;
}
