#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> x(n);
  for (int i = 0; i < n; i++)
    cin >> x[i];

  vector<vector<int>> dp(n, vector<int>(m + 1, 0));

  if (x[0] == 0) {
    for (int i = 1; i <= m; i++)
      dp[0][i] = 1;
  } else {
    dp[0][x[0]] = 1;
  }

  for (int i = 1; i < n; i++) {
    int val = x[i];
    for (int j = 1; j <= m; j++) {
      if (val != 0) {
        if (abs(val - j) <= 1)
          dp[i][val] = (dp[i][val] + dp[i - 1][j]) % MOD;
      } else {
        for (int k = j - 1; k <= j + 1; k++) {
          if (k >= 1 && k <= m)
            dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= m; i++)
    ans = (ans + dp[n - 1][i]) % MOD;

  cout << ans << "\n";
}
