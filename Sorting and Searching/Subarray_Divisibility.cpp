#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll mod(ll n, ll M) {
  ll r = n % M;
  if (n < 0)
    r += M;
  return r;
}

int main() {
  ll n;
  cin >> n;

  vector<ll> a(n), prefixSums(n + 1, 0);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = mod(a[i], n);
    prefixSums[i + 1] = mod(prefixSums[i] + a[i], n);
  }

  vector<ll> count(n, 0);
  for (auto prefixSum : prefixSums)
    count[prefixSum]++;

  ll ways = 0;
  for (auto n : count) {
    if (n > 1)
      ways += (ll)((n * (n - 1)) / 2);
  }

  cout << ways << "\n";
}
