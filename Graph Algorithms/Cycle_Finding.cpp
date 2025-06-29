#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<array<int, 3>> edges(m);
  for (auto &edge : edges) {
    cin >> edge[0] >> edge[1] >> edge[2];
    edge[0]--;
    edge[1]--;
  }

  vector<long long> dist(n, 1e16);
  vector<int> parent(n, -1);
  dist[0] = 0;

  int x = -1;
  for (int i = 0; i < n; i++) {
    x = -1;
    for (auto &edge : edges) {
      auto &[u, v, wt] = edge;
      if (dist[v] > dist[u] + wt) {
        dist[v] = dist[u] + wt;
        parent[v] = u;
        x = v;
      }
    }
  }

  if (x == -1) {
    cout << "NO" << endl;
    return 0;
  }

  for (int i = 0; i < n; i++, x = parent[x])
    ;

  cout << "YES" << endl;
  vector<int> cycle;
  int cur = x;
  do {
    cycle.push_back(cur + 1);
    cur = parent[cur];
  } while (cur != x);
  cycle.push_back(cur + 1);

  for (auto it = cycle.rbegin(); it != cycle.rend(); ++it)
    cout << *it << " ";
  cout << endl;
  return 0;
}
