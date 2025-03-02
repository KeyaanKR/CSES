#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MOD 1000000007;

int main() {
  ll n;
  cin >> n;

  vector<ll> c(n + 1, 0);
  for (ll i = 1; i <= n; i++) {
    if (i == 1)
      c[i] = 1;
    else if (i == 2)
      c[i] = 1 + c[i - 1];
    else if (i == 3)
      c[i] = 1 + c[i - 1] + c[i - 2];
    else if (i == 4)
      c[i] = 1 + c[i - 1] + c[i - 2] + c[i - 3];
    else if (i == 5)
      c[i] = 1 + c[i - 1] + c[i - 2] + c[i - 3] + c[i - 4];
    else if (i == 6)
      c[i] = 1 + c[i - 1] + c[i - 2] + c[i - 3] + c[i - 4] + c[i - 5];
    else
      c[i] = (c[i - 1] + c[i - 2] + c[i - 3] + c[i - 4] + c[i - 5] + c[i - 6]) %
             MOD;
  }

  cout << c[n] << "\n";
}
