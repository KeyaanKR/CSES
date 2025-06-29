#include <bits/stdc++.h>
using namespace std;

void DFS(int u, vector<int> &disc, vector<int> &low, vector<int> &SCC,
         vector<vector<int>> &adj, vector<int> &inRecStack, vector<int> &stack,
         int &time, int &count) {
  disc[u] = low[u] = time++;
  inRecStack[u] = 1;
  stack.push_back(u);

  for (auto &v : adj[u]) {
    if (disc[v] == -1) {
      DFS(v, disc, low, SCC, adj, inRecStack, stack, time, count);
      low[u] = min(low[u], low[v]);
    } else if (inRecStack[v]) {
      low[u] = min(low[u], low[v]);
    }
  }

  if (disc[u] == low[u]) {
    count++;
    while (stack.back() != u) {
      SCC[stack.back()] = count;
      inRecStack[stack.back()] = 0;
      stack.pop_back();
    }
    SCC[stack.back()] = count;
    inRecStack[stack.back()] = 0;
    stack.pop_back();
  }
}

int main() {
  int n, m, u, v;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
  }

  int time = 0, count = 0;
  vector<int> disc(n, -1), low(n, -1), SCC(n, -1), inRecStack(n, 0), stack;
  for (int i = 0; i < n; i++) {
    if (disc[i] == -1)
      DFS(i, disc, low, SCC, adj, inRecStack, stack, time, count);
  }

  cout << count << endl;
  for (int i = 0; i < n; i++)
    cout << SCC[i] << " ";
  cout << endl;
  return 0;
}
