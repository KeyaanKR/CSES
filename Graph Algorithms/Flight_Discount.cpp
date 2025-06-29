#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n);
  int u, v, wt;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> wt;
    u--, v--;
    adj[u].emplace_back(v, wt);
  }

  vector<vector<long long>> dist(2, vector<long long>(n, LLONG_MAX));
  dist[0][0] = 0, dist[1][0] = 0;

  using T = tuple<long long, int, int>;
  priority_queue<T, vector<T>, greater<T>> pq;
  pq.push({dist[0][0], 0, 0});
  pq.push({dist[1][0], 0, 1});

  while (!pq.empty()) {
    auto [d, u, type] = pq.top();
    pq.pop();

    if (dist[type][u] < d)
      continue;

    if (u == n - 1) {
      cout << d << endl;
      return 0;
    }

    for (auto &[v, wt] : adj[u]) {
      if (!type) {
        if (dist[0][v] > d + wt) {
          dist[0][v] = d + wt;
          pq.push({dist[0][v], v, 0});
        }
        if (dist[1][v] > d + wt / 2) {
          dist[1][v] = d + wt / 2;
          pq.push({dist[1][v], v, 1});
        }
      } else if (dist[1][v] > d + wt) {
        dist[1][v] = d + wt;
        pq.push({dist[1][v], v, 1});
      }
    }
  }

  return 0;
}
