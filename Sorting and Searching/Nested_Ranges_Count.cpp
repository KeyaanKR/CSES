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

  vector<pair<ll, ll>> temp = ranges;
  sort(ranges.begin(), ranges.end(), compare);

  multiset<pair<ll, ll>> r;
  map<pair<ll, ll>, ll> contains;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      r.insert(ranges[i]);
      contains[ranges[i]] = 0;
    } else {
      auto it = r.begin();
      while (it != r.end()) {
        if (it->first >= ranges[i].first) {
          auto current = it++;
          contains[ranges[i]] += 1 + contains[*current];
          r.erase(current);
        } else {
          ++it;
        }
      }
      r.insert(ranges[i]);
    }
  }

  for (auto range : temp)
    cout << contains[range] << " ";
  cout << "\n";

  multiset<pair<ll, ll>> l;
  map<pair<ll, ll>, ll> contained;
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      l.insert(ranges[i]);
      contained[ranges[i]] = 0;
    } else {
      auto it = l.begin();
      while (it != l.end()) {
        if (it->first <= ranges[i].first) {
          auto current = it++;
          contained[ranges[i]] += 1 + contained[*current];
        } else {
          ++it;
        }
      }
      if (!contained[ranges[i]])
        l.insert(ranges[i]);
    }
  }

  for (auto range : temp)
    cout << contained[range] << " ";
  cout << "\n";
}
