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

  void DFS(int u, vector<vector<int>> &adj, vector<int> &parent) {
    disc[u] = low[u] = time++;
    inRecStack[u] = 1;
    stack.push_back(u);

    for (auto &v : adj[u]) {
      if (disc[v] == -1) {
        DFS(v, adj, parent);
        low[u] = min(low[u], low[v]);
      } else if (inRecStack[v]) {
        low[u] = min(low[u], disc[v]);
      }
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

int main() {
  int n, m, u, v;
  cin >> n >> m;

  vector<int> coins(n);
  for (auto &coin : coins)
    cin >> coin;

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
  }

  vector<int> parent(n);
  SCC graph(n);

  for (int i = 0; i < n; i++) {
    if (!graph.visited(i))
      graph.DFS(i, adj, parent);
  }

  vector<vector<int>> adjF(n);
  long long maxCoins = 0;
  vector<long long> value(n, 0), indegree(n, 0);
  for (int u = 0; u < n; u++) {
    value[parent[u]] += 1LL * coins[u];
    maxCoins = max(maxCoins, 1LL * coins[u]);
    for (auto &v : adj[u]) {
      if (parent[u] != parent[v]) {
        adjF[parent[u]].push_back(parent[v]);
        indegree[parent[v]]++;
      }
    }
  }

  queue<int> q;
  vector<long long> loot(n, LLONG_MIN);
  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0 && !adjF[i].empty()) {
      q.push(i);
      loot[i] = value[i];
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    maxCoins = max(maxCoins, loot[u]);
    for (auto &v : adjF[u]) {
      loot[v] = max(loot[v], loot[u] + value[v]);
      if (--indegree[v] == 0)
        q.push(v);
    }
  }

  cout << maxCoins << endl;
  return 0;
}
