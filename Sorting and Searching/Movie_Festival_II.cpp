#include <bits/stdc++.h>
#include <set>
using namespace std;
typedef long long int ll;

bool custom_sort(pair<ll, ll> a, pair<ll, ll> b) {
  if (a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}

int main() {
  ll n, k;
  cin >> n >> k;

  vector<pair<ll, ll>> intervals(n);
  for (ll i = 0; i < n; i++)
    cin >> intervals[i].first >> intervals[i].second;

  sort(intervals.begin(), intervals.end(), custom_sort);

  multiset<ll> endTimes;
  ll maxAllotment = 0;

  for (auto interval : intervals) {
    auto it = endTimes.upper_bound(interval.first);
    if (it != endTimes.begin()) {
      --it;
      if (*it <= interval.first) {
        endTimes.erase(it);
        endTimes.insert(interval.second);
        maxAllotment++;
        continue;
      }
    }

    if (endTimes.size() < k) {
      endTimes.insert(interval.second);
      maxAllotment++;
    }
  }

  cout << maxAllotment << "\n";
  return 0;
}
