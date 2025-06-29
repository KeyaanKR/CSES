#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n, 0));
  vector<vector<vector<int>>> rowInfo(
      n, vector<vector<int>>(n, vector<int>(2 * n - 1, 0)));
  vector<vector<vector<int>>> colInfo(
      n, vector<vector<int>>(n, vector<int>(2 * n - 1, 0)));

  for (int i = 0; i < n; i++) {
    grid[0][i] = i;
    colInfo[0][i][i] = 1;
    grid[i][0] = i;
    rowInfo[i][0][i] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      int min = i + j;
      for (int k = 0; k < i + j; k++) {
        int present = colInfo[i - 1][j][k] | rowInfo[i][j - 1][k];
        if (min == i + j && !present)
          min = k;
      }
      grid[i][j] = min;
      rowInfo[i][j] = rowInfo[i][j - 1];
      rowInfo[i][j][min] = 1;
      colInfo[i][j] = colInfo[i - 1][j];
      colInfo[i][j][min] = 1;
    }
  }

  for (auto &row : grid) {
    for (auto &val : row)
      cout << val << " ";
    cout << endl;
  }

  return 0;
}
