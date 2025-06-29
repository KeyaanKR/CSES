#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
  vector<int> parent, rank;

public:
  DSU(int n) {
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    rank.resize(n, 1);
  }

  int find(int i) {
    if (parent[i] != i)
      return parent[i] = find(parent[i]);
    return i;
  }

  void unite(int i, int j) {
    int rootI = parent[i], rootJ = parent[j];
    if (rootI == rootJ)
      return;
    if (rank[rootJ] > rank[rootI])
      swap(rootI, rootJ);
    rank[rootI] += rank[rootJ];
    parent[rootJ] = rootI;
  }

  int sz(int i) { return rank[find(i)]; }
};

int main() {
  int n, m;
  cin >> n >> m;

  int u, v, numComps = n, maxCompSz = 1;
  DSU dsu(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    if (dsu.find(u) != dsu.find(v)) {
      dsu.unite(u, v);
      numComps--;
      maxCompSz = max(maxCompSz, dsu.sz(u));
    }
    cout << numComps << " " << maxCompSz << endl;
  }
}
