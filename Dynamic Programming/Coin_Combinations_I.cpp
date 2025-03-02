#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll n, x;
  cin >> n >> x;

  vector<ll> c(n);
  for (ll i = 0; i < n; i++)
    cin >> c[i];
  sort(c.begin(), c.end());

  vector<ll> s(x + 1, 1);
  for (ll i = 1; i <= x; i++) {
    vector<ll> sDiff;
    for (auto coin : c) {
      if (i - coin >= 0)
        sDiff.push_back(i - coin);
    }

    ll count = 0;
    for (auto prev : sDiff) {
      if (s[prev] != 0)
        count += s[prev] % 1000000007;
    }
    s[i] = count % 1000000007;
  }

  cout << s[x] << "\n";
}
