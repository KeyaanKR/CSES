#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MOD 1000000007

ll solve(ll x, ll y, vector<string> &grid, vector<vector<ll>> &dp) {
  if (dp[x][y] != -1)
    return dp[x][y];

  if (x < 0 || y < 0 || grid[x][y] == '*') {
    dp[x][y] = 0;
    return 0;
  }

  if (x == 0 && y == 0) {
    dp[x][y] = 1;
    return 1;
  } else {
    dp[x][y] = 0;
    vector<pair<ll, ll>> moves = {{x, y - 1}, {x - 1, y}};
    for (auto [nx, ny] : moves) {
      if (nx >= 0 && ny >= 0 && grid[nx][ny] != '*')
        dp[x][y] = (dp[x][y] + solve(nx, ny, grid, dp)) % MOD;
    }
  }

  return dp[x][y];
}

int main() {
  ll n;
  cin >> n;

  vector<string> grid(n);
  for (ll i = 0; i < 1000; i++)
    cin >> grid[i];

  vector<vector<ll>> dp(n, vector<ll>(n, -1));
  ll ways = solve(n - 1, n - 1, grid, dp);

  cout << ways << "\n";
}
