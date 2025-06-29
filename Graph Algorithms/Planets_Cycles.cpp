#include <bits/stdc++.h>
using namespace std;

class SCC {
private:
  int time;
  vector<int> disc, low;
  vector<int> inRecStack, stack;

public:
  SCC(int n) {
    time = 0;
    disc.resize(n, -1);
    low.resize(n, -1);
    inRecStack.resize(n, 0);
    stack.clear();
  }

  bool visited(int u) { return disc[u] != -1; }

  void DFS(int u, vector<int> &adj, vector<int> &parent) {
    disc[u] = low[u] = time++;
    inRecStack[u] = 1;
    stack.push_back(u);

    int v = adj[u];
    if (disc[v] == -1) {
      DFS(v, adj, parent);
      low[u] = min(low[u], low[v]);
    } else if (inRecStack[v]) {
      low[u] = min(low[u], disc[v]);
    }

    if (disc[u] == low[u]) {
      int cur;
      do {
        cur = stack.back();
        parent[cur] = u;
        inRecStack[cur] = 0;
        stack.pop_back();
      } while (cur != u);
    }
  }
};

int DFS(int u, vector<int> &adj, vector<int> &distToCyc, vector<int> &parent,
        vector<int> &cycleSZ) {
  if (distToCyc[u] != -2)
    return distToCyc[u];

  int p = parent[u];

  if (cycleSZ[p] > 1)
    return distToCyc[u] = cycleSZ[p];

  if (adj[p] == -1)
    return distToCyc[u] = -1;

  int len = DFS(adj[p], adj, distToCyc, parent, cycleSZ);
  if (len == -1)
    return distToCyc[u] = -1;

  return distToCyc[u] = 1 + len;
}

int main() {
  int n;
  cin >> n;

  vector<int> adj(n);
  for (int i = 0; i < n; i++) {
    cin >> adj[i];
    adj[i]--;
  }

  vector<int> parent(n);
  SCC graph(n);

  for (int i = 0; i < n; i++) {
    if (!graph.visited(i))
      graph.DFS(i, adj, parent);
  }

  vector<int> adjF(n, -1), cycleSZ(n, 0), distToCyc(n, -2);
  for (int u = 0; u < n; u++) {
    cycleSZ[parent[u]]++;
    int v = adj[u];
    if (parent[u] != parent[v])
      adjF[parent[u]] = parent[v];
    if (adj[u] == u)
      distToCyc[u] = 1;
  }

  for (int i = 0; i < n; i++) {
    DFS(i, adjF, distToCyc, parent, cycleSZ);
    cout << distToCyc[i] << " ";
  }
  cout << endl;
  return 0;
}
