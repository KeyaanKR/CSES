#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
  vector<int> parent, rank;

public:
  DSU(int n) {
    parent.resize(n);
    rank.resize(n, 1);
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int i) {
    if (parent[i] != i)
      return parent[i] = find(parent[i]);
    return i;
  }

  void unite(int i, int j) {
    int I = parent[i], J = parent[j];
    if (rank[J] > rank[I])
      swap(I, J);
    if (rank[I] == rank[J])
      rank[I]++;
    parent[J] = I;
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  int u, v, wt;
  vector<array<int, 3>> edges;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> wt;
    u--, v--;
    edges.push_back({wt, u, v});
  }

  sort(edges.begin(), edges.end());

  long long totalCost = 0, connectedComponents = 0;
  DSU dsu(n);
  for (auto &edge : edges) {
    auto &[wt, u, v] = edge;
    if (dsu.find(u) != dsu.find(v)) {
      dsu.unite(u, v);
      totalCost += wt;
      if (++connectedComponents == n - 1)
        break;
    }
  }

  if (connectedComponents < n - 1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cout << totalCost << endl;
  return 0;
}
