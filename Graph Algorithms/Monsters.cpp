#include <bits/stdc++.h>
using namespace std;

void BFS(const vector<pair<int, int>> &startPoints, vector<vector<int>> &dist,
         vector<vector<pair<int, int>>> &prev, const vector<vector<char>> &grid,
         const vector<pair<int, int>> &directions) {

  queue<pair<int, int>> q;
  int flag, n = grid.size(), m = grid[0].size();
  for (const auto &point : startPoints) {
    q.push(point);
    dist[point.first][point.second] = 0;
    flag = grid[point.first][point.second] == 'A';
  }

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (const auto &[dx, dy] : directions) {
      int nx = x + dx, ny = y + dy;

      if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == INT_MAX) {
        int extra = flag && grid[nx][ny] == 'M' ? 1 : 0;
        if (grid[nx][ny] != '#' && !extra) {
          dist[nx][ny] = dist[x][y] + 1;
          prev[nx][ny] = {x, y};
          q.push({nx, ny});
        }
      }
    }
  }
}

string getPath(const vector<vector<pair<int, int>>> &prev, pair<int, int> start,
               pair<int, int> end) {
  string path;
  while (end != start) {
    auto [x, y] = end;
    auto [px, py] = prev[x][y];
    if (px == x - 1)
      path += 'D'; // down
    else if (px == x + 1)
      path += 'U'; // up
    else if (py == y - 1)
      path += 'R'; // right
    else if (py == y + 1)
      path += 'L'; // left
    end = {px, py};
  }
  reverse(path.begin(), path.end());
  return path;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m));
  vector<pair<int, int>> monsters;
  pair<int, int> start, null = {-1, -1};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A') {
        start = {i, j};
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
          cout << "YES" << endl;
          cout << 0 << endl;
          cout << "" << endl;
          return 0;
        }
      } else if (grid[i][j] == 'M')
        monsters.push_back({i, j});
    }
  }

  vector<vector<int>> distA(n, vector<int>(m, INT_MAX));
  vector<vector<int>> distM(n, vector<int>(m, INT_MAX));
  vector<vector<pair<int, int>>> prevA(n, vector<pair<int, int>>(m, null));
  vector<vector<pair<int, int>>> prevM(n, vector<pair<int, int>>(m, null));

  vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  vector<pair<int, int>> A = {start};
  BFS(A, distA, prevA, grid, directions);
  BFS(monsters, distM, prevM, grid, directions);

  // check if the player can reach the exit
  for (int i = 0; i < n; i++) {
    if (distA[i][0] < distM[i][0]) {
      cout << "YES" << endl;
      string path = getPath(prevA, start, {i, 0});
      cout << path.length() << endl;
      cout << path << endl;
      return 0;
    } else if (distA[i][m - 1] < distM[i][m - 1]) {
      cout << "YES" << endl;
      string path = getPath(prevA, start, {i, m - 1});
      cout << path.length() << endl;
      cout << path << endl;
      return 0;
    }
  }

  for (int j = 0; j < m; j++) {
    if (distA[0][j] < distM[0][j]) {
      cout << "YES" << endl;
      string path = getPath(prevA, start, {0, j});
      cout << path.length() << endl;
      cout << path << endl;
      return 0;
    } else if (distA[n - 1][j] < distM[n - 1][j]) {
      cout << "YES" << endl;
      string path = getPath(prevA, start, {n - 1, j});
      cout << path.length() << endl;
      cout << path << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}
