#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MOD 1000000007

ll power(ll x, ll y) {
  if (x == 0) {
    if (y == 0)
      return 1;
    else
      return 0;
  } else {
    if (y == 0)
      return 1;
    else if (y == 1)
      return x;
    else {
      ll temp = power(x, y / 2);
      if (y % 2 == 0)
        return (temp * temp) % MOD;
      else
        return (((temp * temp) % MOD) * x) % MOD;
    }
  }
}

int main() {
  ll n;
  cin >> n;

  for (ll i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    cout << power(x, y) << "\n";
  }
}
