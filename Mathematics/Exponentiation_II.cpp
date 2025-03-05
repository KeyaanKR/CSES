#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MOD 1000000007

ll power(ll x, ll y, ll mod) {
  if (x == 0) {
    if (y == 0)
      return 1;
    else
      return 0;
  } else {
    if (y == 0)
      return 1;
    else {
      ll temp = power(x, y / 2, mod);
      if (y % 2 == 0)
        return (temp * temp) % mod;
      else
        return (((temp * temp) % mod) * x) % mod;
    }
  }
}

int main() {
  ll n;
  cin >> n;

  for (ll i = 0; i < n; i++) {
    ll x, y, z;
    cin >> x >> y >> z;
    cout << power(x, power(y, z, MOD - 1), MOD) << "\n";
  }
}
