#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll n, x;
  cin >> n >> x;

  vector<ll> a(n), prefixSums(n + 1, 0);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    prefixSums[i + 1] = prefixSums[i] + a[i];
  }

  ll count = 0;
  for (auto prefixSum : prefixSums) {
    ll index =
        lower_bound(prefixSums.begin(), prefixSums.end(), prefixSum + x) -
        prefixSums.begin();
    if (index != n + 1 && prefixSums[index] == prefixSum + x)
      count++;
  }

  cout << count << "\n";
}
