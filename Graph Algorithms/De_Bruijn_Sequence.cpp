#include <bits/stdc++.h>
using namespace std;

int MOD, found = 0;

void deBruijn(int i, vector<vector<int>> &adj, vector<int> &visited,
              vector<int> &path) {
  if (found)
    return;

  visited[i] = 1;
  path.push_back(i);

  if (path.size() == 2 * MOD) {
    found = 1;
    return;
  }

  for (auto &v : adj[i]) {
    if (!visited[v])
      deBruijn(v, adj, visited, path);
    if (found)
      return;
  }

  path.pop_back();
  visited[i] = 0;
}

int main() {
  int n;
  cin >> n;

  MOD = pow(2, n - 1);
  vector<vector<int>> adj(2 * MOD);
  for (int i = 0; i < 2 * MOD; i++) {
    adj[i].push_back(2 * (i % MOD));
    adj[i].push_back(adj[i].back() + 1);
  }

  vector<int> path, visited(2 * MOD, 0);
  deBruijn(0, adj, visited, path);

  string sequence(n - 1, '0');
  for (auto &node : path)
    sequence.push_back('0' + (node % 2));
  cout << sequence << endl;
  return 0;
}
