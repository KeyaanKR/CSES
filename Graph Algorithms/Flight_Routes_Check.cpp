#include <bits/stdc++.h>
using namespace std;

void DFS(int u, vector<vector<int>> &adj, vector<bool> &visited) {
  visited[u] = true;
  for (auto &v : adj[u]) {
    if (!visited[v])
      DFS(v, adj, visited);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adjF(n), adjB(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adjF[u].push_back(v);
    adjB[v].push_back(u);
  }

  vector<bool> visitedF(n, false), visitedB(n, false);
  DFS(0, adjF, visitedF);
  DFS(0, adjB, visitedB);

  for (int i = 0; i < n; i++) {
    if (!visitedF[i] || !visitedB[i]) {
      cout << "NO" << endl;
      if (!visitedF[i]) {
        cout << "1 " << i + 1 << endl;
      } else {
        cout << i + 1 << " 1" << endl;
      }
      return 0;
    }
  }

  cout << "YES" << endl;
}
