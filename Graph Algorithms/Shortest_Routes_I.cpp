#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a - 1].push_back({b - 1, c});
  }

  using P = pair<long long, int>;
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({0, 0}); // {distance, node}

  vector<long long> dist(n, LONG_LONG_MAX);
  dist[0] = 0;

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (d > dist[u])
      continue;

    for (auto &[v, w] : adj[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }

  for (auto &d : dist)
    cout << d << " ";
  cout << "\n";
  return 0;
}
