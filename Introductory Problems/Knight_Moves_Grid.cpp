#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n, -1));
  vector<pair<int, int>> moves = {{1, 2}, {1, -2}, {-1, -2}, {-1, 2},
                                  {2, 1}, {2, -1}, {-2, -1}, {-2, 1}};

  grid[0][0] = 0;
  queue<pair<int, int>> q;
  q.push({0, 0});

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (auto &[dx, dy] : moves) {
      int nx = x + dx, ny = y + dy;
      if (0 <= nx && nx < n && 0 <= ny && ny < n && grid[nx][ny] == -1) {
        grid[nx][ny] = grid[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }

  for (auto &row : grid) {
    for (auto &val : row) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}
