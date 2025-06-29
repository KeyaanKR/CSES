#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;

void DFS(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || grid[x][y] == '#')
    return;

  visited[x][y] = true;

  DFS(x + 1, y);
  DFS(x - 1, y);
  DFS(x, y + 1);
  DFS(x, y - 1);
}

int main() {
  cin >> n >> m;

  grid = vector<vector<char>>(n, vector<char>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> grid[i][j];

  visited = vector<vector<bool>>(n, vector<bool>(m, false));
  int roomCount = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!visited[i][j] && grid[i][j] == '.') {
        DFS(i, j);
        roomCount++;
      }
    }
  }

  cout << roomCount << endl;
  return 0;
}
