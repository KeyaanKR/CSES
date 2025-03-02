#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll n;
  cin >> n;

  ll count = 0;
  ll maxEntry = -INFINITY;
  vector<ll> x(n), prefixSum(n + 1, 0);
  for (ll i = 0; i < n; i++) {
    cin >> x[i];

    if (x[i] < 0)
      count++;
    maxEntry = maxEntry > x[i] ? maxEntry : x[i];

    prefixSum[i + 1] = x[i] + prefixSum[i];
  }

  ll maxSum = -INFINITY;
  ll minPrefixSum = INFINITY;
  for (ll i = 0; i <= n; i++) {
    if (prefixSum[i] < minPrefixSum)
      minPrefixSum = prefixSum[i];
    else
      maxSum = max(maxSum, prefixSum[i] - minPrefixSum);
  }

  if (count == n)
    maxSum = maxEntry;
  cout << maxSum << "\n";
}
