#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll n, x;
  cin >> n >> x;

  vector<ll> a(n), pref(n + 1, 0);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    pref[i + 1] = pref[i] + a[i];
  }

  map<ll, ll> freq;
  for (auto prefSum : pref)
    freq[prefSum]++;

  ll total = 0;
  for (auto prefSum : pref) {
    total += freq[prefSum + x];
    if (freq.find(prefSum) != freq.end())
      freq[prefSum]--;
    if (prefSum + x == prefSum)
      total--;
  }

  cout << total << "\n";
}
