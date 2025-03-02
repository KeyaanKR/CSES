#include <bits/stdc++.h>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  int l = max(s1.length(), s2.length());
  string N, M;
  if (l == s1.length())
    N = s1, M = s2;
  else
    N = s2, M = s1;

  vector<vector<int>> dp(3, vector<int>(M.length() + 1));
  for (int i = 0; i <= M.length(); i++)
    dp[0][i] = i;
}
