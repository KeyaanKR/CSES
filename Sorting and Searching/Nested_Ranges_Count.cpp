#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool compare(pair<ll, ll> a, pair<ll, ll> b) {
  if (a.second == b.second)
    return a.first > b.first;
  return a.second < b.second;
}

int main() {
  ll n;
  cin >> n;

  vector<pair<ll, ll>> ranges(n);
  for (ll i = 0; i < n; i++)
    cin >> ranges[i].first >> ranges[i].second;

  vector<pair<ll, ll>> r = ranges;
  sort(r.begin(), r.end(), compare);

  for (auto [s, e] : r)
    cout << s << " " << e << "\n";

  map<pair<ll, ll>, ll> contains;
  ll maxS = -1;
  for (auto [s, e] : r) {
    if (s <= maxS)
      contains[{s, e}] = 1;
    else {
      contains[{s, e}] = 0;
      maxS = s;
    }
  }

  pair<ll, ll> r1 = r[0];
  pair<ll, ll> r2 = r[1];

  if (r1.second == r2.second && r1.first == r2.first)
    contains[r1] = 1;

  for (ll i = 0; i < n; i++) {
    pair<ll, ll> range = ranges[i];
    if (contains[range])
      cout << "1 ";
    else
      cout << "0 ";
  }
  cout << "\n";

  map<pair<ll, ll>, ll> contained;
  int minS = INT_MAX;
  for (int i = n - 1; i >= 0; i--) {
    int s = r[i].first;
    if (s >= minS)
      contained[r[i]] = 1;
    else {
      contained[r[i]] = 0;
      minS = s;
    }
  }

  r1 = r[n - 1];
  r2 = r[n - 2];

  if (r1.second == r2.second && r1.first == r2.first)
    contained[r1] = 1;

  for (ll i = 0; i < n; i++) {
    pair<ll, ll> range = ranges[i];
    if (contained[range])
      cout << "1 ";
    else
      cout << "0 ";
  }
  cout << "\n";
}
