#include <bits/stdc++.h>
using namespace std;

vector<bool> DFS(int u, vector<vector<pair<int, int>>> &adj) {
  vector<bool> isUseful(adj.size(), false);
  vector<int> s;
  s.push_back(u);
  isUseful[u] = true;

  while (!s.empty()) {
    int node = s.back();
    s.pop_back();

    for (auto &[v, wt] : adj[node]) {
      if (!isUseful[v]) {
        isUseful[v] = true;
        s.push_back(v);
      }
    }
  }

  return isUseful;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  int a, b, c;
  vector<vector<pair<int, int>>> adjF(n), adjB(n);
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    a--, b--;
    adjF[a].emplace_back(b, c);
    adjB[b].emplace_back(a, c);
  }

  vector<bool> isUsefulF = DFS(0, adjF), isUsefulB = DFS(n - 1, adjB);
  vector<bool> isUseful(n);
  for (int i = 0; i < n; i++)
    isUseful[i] = isUsefulF[i] && isUsefulB[i];

  using T = tuple<long long, int>;
  priority_queue<T, vector<T>, greater<>> pq;
  pq.push({0, 0});

  vector<vector<long long>> dist(n);

  while (dist[n - 1].size() < k) {
    auto [d, u] = pq.top();
    pq.pop();

    if (dist[u].size() >= k)
      continue;
    dist[u].push_back(d);

    for (auto &[v, wt] : adjF[u]) {
      if (isUseful[v])
        pq.push({d + wt, v});
    }
  }

  for (auto &cost : dist[n - 1])
    cout << cost << " ";
  cout << endl;
  return 0;
}
