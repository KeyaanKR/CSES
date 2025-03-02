#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

string g;
vector<vector<int>> grid(7, vector<int>(7, 0));
int paths = 0;

void getPaths(int index = 0, int x = 0, int y = 0) {
  if (index == 48) {
    if (x == 0 && y == 6) {
      paths++;
    }
    return;
  }

  char move = g[index];

  // Possible movements (dx, dy)
  vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  char moveChars[4] = {'R', 'L', 'D', 'U'};

  for (int i = 0; i < 4; i++) {
    if (move != '?' && move != moveChars[i]) continue; // Skip invalid moves

    int nx = x + moves[i].first, ny = y + moves[i].second;
    
    if (nx >= 0 && nx < 7 && ny >= 0 && ny < 7 && grid[nx][ny] == 0) {
      grid[nx][ny] = 1;
      getPaths(index + 1, nx, ny);
      grid[nx][ny] = 0;
    }
  }
}

int main() {
  cin >> g;
  grid[0][0] = 1;
  getPaths();
  cout << paths << endl;
}
