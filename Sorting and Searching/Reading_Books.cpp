#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll n;
  cin >> n;

  vector<ll> t(n);
  ll totalTime = 0;
  for (ll i = 0; i < n; i++) {
    cin >> t[i];
    totalTime += t[i];
  }

  if (n == 1) {
    cout << 2 * t[0] << "\n";
    return 0;
  }

  sort(t.begin(), t.end());

  vector<ll> prefixSum;
  prefixSum.push_back(0);
  vector<ll> readTill(n);
  for (ll i = 0; i < n; i++) {
    auto it = upper_bound(prefixSum.begin(), prefixSum.end(), t[i]);
    if (it == prefixSum.end()) {
      readTill[i] = prefixSum.size() - 1;
    } else {
      readTill[i] = it - prefixSum.begin() - 1;
    }
    prefixSum.push_back(prefixSum[i] + t[i]);
  }

  ll index;
  for (ll i = 1; i < n; i++) {
    if (readTill[i] == i)
      index = i;
  }

  ll rK = prefixSum[n] - prefixSum[index];
  ll rJ = prefixSum[n - 1];

  ll timeTaken;
  if (rJ >= t[n - 1]) {
    timeTaken = rJ + t[n - 1];
  } else {
    timeTaken = rK + t[n - 1];
  }

  cout << timeTaken << "\n";
  return 0;
}
