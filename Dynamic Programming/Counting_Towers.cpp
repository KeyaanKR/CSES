#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7, maxN = 1e6;

int solve(int n, int m, unordered_map<long long, int> &dp) {
  if (n == 0 || m == 0)
    return 0;

  long long key = (long long)n * maxN + m;
  if (dp.find(key) != dp.end())
    return dp[key];

  for (int i = 1; i <= m; i++) {
    dp[key] = (dp[key] + 1 + solve(n, m - j, dp)) % mod;
  }

  return dp[key];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);

  int t;
  cin >> t;

  unordered_map<long long, int> dp;

  while (t--) {
    int n;
    cin >> n;

    cout << solve(n, n, dp) << endl;
  }
  return 0;
}
