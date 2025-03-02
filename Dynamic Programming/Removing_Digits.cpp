#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<ll> digits(ll n) {
  vector<ll> d;
  while (n > 0) {
    d.push_back(n % 10);
    n /= 10;
  }
  return d;
}

int main() {
  ll n;
  cin >> n;

  vector<ll> dp(n + 1, pow(10, 9));
  for (ll i = 0; i <= n; i++) {
    if (i == 0) {
      dp[i] = 0;
    } else {
      vector<ll> d = digits(i);
      for (auto digit : d)
        dp[i] = min(dp[i], dp[i - digit] + 1);
    }
  }

  cout << dp[n] << "\n";
}
