#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll calculateProduce(ll time, vector<ll> &k) {
  ll produce = 0;
  for (auto timeTaken : k)
    produce += time / timeTaken;
  return produce;
}

int main() {
  ll n, t;
  cin >> n >> t;

  vector<ll> k(n);
  ll minTimeTaken = INT_MAX;
  for (ll i = 0; i < n; i++) {
    cin >> k[i];
    if (k[i] < minTimeTaken)
      minTimeTaken = k[i];
  }

  ll minCount = 0;
  for (ll i = 0; i < n; i++) {
    if (k[i] == minTimeTaken)
      minCount++;
  }

  ll s = 1;
  ll e = ceil((double)t / minCount) * minTimeTaken;
  while (e >= s) {
    ll time = (e + s) / 2;
    ll produce = calculateProduce(time, k);
    if (produce >= t) {
      ll p = calculateProduce(time - 1, k);
      if (p < t) {
        e = time;
        break;
      } else
        e = time - 1;
    } else
      s = time + 1;
  }

  cout << e << endl;
}
