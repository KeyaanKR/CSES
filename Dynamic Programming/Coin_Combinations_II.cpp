#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// this type of dp calculates from bottom to top
void solve(int n, int x) {
  int min = INT_MAX;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    min = c[i] < min ? c[i] : min;
  }

  vector<vector<int>> dp(x + 1, vector<int>(n + 1, 0));

  for (int i = min; i <= x; i++) {
    for (int j = 0; j < n; j++) {
      int count = 0;
      if (i == c[j] || (j == 0 && i % c[j] == 0))
        count++;

      if (j != 0 && i - c[j] >= 0)
        count = (count + dp[i - c[j]][j + 1]) % MOD;

      dp[i][j + 1] = (count + dp[i][j]) % MOD;
    }
  }

  cout << dp[x][n] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x;
  cin >> n >> x;

  vector<int> c(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];

  vector<int> dp(x + 1, 0);
  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = c[i]; j <= x; j++) {
      if (j - c[i] >= 0)
        dp[j] = (dp[j] + dp[j - c[i]]) % MOD;
    }
  }

  cout << dp[x] << "\n";
}
