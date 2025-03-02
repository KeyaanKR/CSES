#include <bits/stdc++.h>
using namespace std;

int solve(int index, vector<pair<int, int>> &books, int budget,
          vector<vector<int>> &dp) {

  if (index < 0 || budget < 0) {
    return 0;
  }

  if (dp[index][budget] != -1)
    return dp[index][budget];

  if (books[index].first > budget)
    dp[index][budget] = solve(index - 1, books, budget, dp);
  else {
    int pages1 = books[index].second +
                 solve(index - 1, books, budget - books[index].first, dp);
    int pages2 = solve(index - 1, books, budget, dp);

    dp[index][budget] = pages1 > pages2 ? pages1 : pages2;
  }

  return dp[index][budget];
}

int main() {
  int n, budget;
  cin >> n >> budget;

  vector<pair<int, int>> books(n);
  for (int i = 0; i < n; i++)
    cin >> books[i].first;
  for (int i = 0; i < n; i++)
    cin >> books[i].second;

  vector<vector<int>> dp(n + 1, vector<int>(budget + 1, -1));
  // cout << solve(n - 1, books, budget, dp) << "\n";

  for (int i = 0; i <= n; i++) {
    for (int left = 0; left <= budget; left++) {
      if (i == 0 || left == 0)
        dp[i][left] = 0;
      else if (books[i - 1].first > left)
        dp[i][left] = dp[i - 1][left];
      else
        dp[i][left] =
            max(dp[i - 1][left],
                books[i - 1].second + dp[i - 1][left - books[i - 1].first]);
    }
  }

  cout << dp[n][budget] << "\n";
}
