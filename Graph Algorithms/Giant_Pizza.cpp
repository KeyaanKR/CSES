#include <bits/stdc++.h>
using namespace std;

class SCC {
private:
  int time, compNum;
  vector<int> disc, low;
  vector<int> inRecStack, stack;

public:
  SCC(int n) {
    time = 0;
    compNum = 0;
    disc.resize(n, -1);
    low.resize(n, -1);
    inRecStack.resize(n, 0);
    stack.clear();
  }

  bool visited(int u) { return disc[u] != -1; }

  void DFS(int u, vector<vector<int>> &adj, vector<int> &group) {
    disc[u] = low[u] = time++;
    inRecStack[u] = 1;
    stack.push_back(u);

    for (int v : adj[u]) {
      if (disc[v] == -1) {
        DFS(v, adj, group);
        low[u] = min(low[u], low[v]);
      } else if (inRecStack[v]) {
        low[u] = min(low[u], disc[v]);
      }
    }

    if (disc[u] == low[u]) {
      int cur;
      do {
        cur = stack.back();
        group[cur] = compNum;
        inRecStack[cur] = 0;
        stack.pop_back();
      } while (cur != u);
      compNum++;
    }
  }
};

int n, m;

int getNode(int i) { return i < 0 ? m + abs(i) : i; }
int invNode(int i) { return i <= m ? m + i : i - m; }

int main() {
  string s1, u, s2, v;
  cin >> n >> m;

  vector<vector<int>> adj(2 * m + 1);
  for (int i = 0; i < n; i++) {
    cin >> s1 >> u >> s2 >> v;
    int a = (s1 == "+") ? stoi(u) : -stoi(u);
    int b = (s2 == "+") ? stoi(v) : -stoi(v);
    int A = getNode(a), negA = invNode(A);
    int B = getNode(b), negB = invNode(B);
    adj[negA].push_back(B);
    adj[negB].push_back(A);
  }

  SCC graph(2 * m + 1);
  vector<int> group(2 * m + 1, -1);
  for (int i = 1; i <= 2 * m; i++) {
    if (!adj[i].empty() && !graph.visited(i))
      graph.DFS(i, adj, group);
  }

  vector<char> val(m + 1, '+');
  for (int i = 1; i <= m; i++) {
    if (!adj[i].empty() && group[i] == group[m + i]) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }

    if (group[i] >= group[i + m])
      val[i] = '-';
  }

  for (int i = 1; i <= m; i++)
    cout << val[i] << " ";
  cout << endl;
  return 0;
}
