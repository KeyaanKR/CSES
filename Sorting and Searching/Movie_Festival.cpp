#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool customComparator(pair<ll, ll> x1, pair<ll, ll> x2) {
  return x1.second < x2.second;
}

int main() {
  ll n;
  cin >> n;

  vector<pair<ll, ll>> ab(n);
  for (ll i = 0; i < n; i++)
    cin >> ab[i].first >> ab[i].second;

  sort(ab.begin(), ab.end(), customComparator);

  ll count = 0;
  ll maxExitTime = -1;
  for (ll i = 0; i < n; i++) {
    if (ab[i].first >= maxExitTime) {
      count++;
      maxExitTime = ab[i].second;
    }
  }

  cout << count << "\n";
}
