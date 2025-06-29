#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  long long max = 1LL * n * n * 1e9;

  vector<vector<pair<int, int>>> adj(n);
  vector<vector<long long>> dist(n, vector<long long>(n, max));
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a - 1].push_back({b - 1, c});
    dist[a - 1][b - 1] = min(dist[a - 1][b - 1], 1LL * c);
    adj[b - 1].push_back({a - 1, c});
    dist[b - 1][a - 1] = min(dist[b - 1][a - 1], 1LL * c);
  }

  for (int i = 0; i < n; i++)
    dist[i][i] = 0;

  for (int mid = 0; mid < n; mid++)
    for (int src = 0; src < n; src++)
      for (int dst = 0; dst < n; dst++)
        dist[src][dst] = min(dist[src][dst], dist[src][mid] + dist[mid][dst]);

  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    cout << (dist[a - 1][b - 1] == max ? -1 : dist[a - 1][b - 1]) << " ";
  }
  cout << "\n";

  return 0;
}
