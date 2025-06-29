#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m));
  pair<int, int> start, end, null = {-1, -1};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A')
        start = {i, j};
      if (grid[i][j] == 'B')
        end = {i, j};
    }
  }

  queue<pair<int, int>> q;
  q.push(start);

  vector<pair<int, int>> directions = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};
  map<pair<int, int>, char> moves = {
      {{+1, 0}, 'D'}, {{-1, 0}, 'U'}, {{0, +1}, 'R'}, {{0, -1}, 'L'}};
  vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, null));

  parent[start.first][start.second] = start; // Mark as visited

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    if (make_pair(x, y) == end) {
      string path = "";
      while (make_pair(x, y) != start) {
        auto [px, py] = parent[x][y];
        pair<int, int> move = {x - px, y - py};
        path += moves[move];
        x = px;
        y = py;
      }
      reverse(path.begin(), path.end());
      cout << "YES\n";
      cout << path.size() << "\n";
      cout << path << "\n";
      return 0;
    }

    for (auto &[dx, dy] : directions) {
      int nx = x + dx, ny = y + dy;
      if (0 <= nx && nx < n && 0 <= ny && ny < m && grid[nx][ny] != '#' &&
          parent[nx][ny] == null) {
        parent[nx][ny] = {x, y};
        q.push({nx, ny});
      }
    }
  }

  cout << "NO\n";
  return 0;
}
