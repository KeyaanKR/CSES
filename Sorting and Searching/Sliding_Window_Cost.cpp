#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n, k;
  cin >> n >> k;

  vector<ll> nums(n);
  for (ll i = 0; i < n; i++)
    cin >> nums[i];

  multiset<pair<ll, ll>, greater<pair<ll, ll>>> max_heap;
  ll max_heap_cost = 0;
  multiset<pair<ll, ll>> min_heap;
  ll min_heap_cost = 0;
  vector<ll> medians;
  vector<ll> costs;

  for (ll i = 0; i < n; i++) {
    if (i >= k) {
      if (max_heap.find({nums[i - k], i - k}) != max_heap.end()) {
        max_heap.erase(max_heap.find({nums[i - k], i - k}));
        max_heap_cost -= nums[i - k];
      } else {
        min_heap.erase(min_heap.find({nums[i - k], i - k}));
        min_heap_cost -= nums[i - k];
      }
    }

    max_heap.insert({nums[i], i});
    max_heap_cost += nums[i];
    min_heap.insert(*max_heap.begin());
    min_heap_cost += max_heap.begin()->first;
    max_heap_cost -= max_heap.begin()->first;
    max_heap.erase(*max_heap.begin());

    while (max_heap.size() < min_heap.size()) {
      max_heap.insert(*min_heap.begin());
      max_heap_cost += min_heap.begin()->first;
      min_heap_cost -= min_heap.begin()->first;
      min_heap.erase(*min_heap.begin());
    }

    if (i >= k - 1) {
      medians.push_back(max_heap.begin()->first);
      costs.push_back(min_heap_cost +
                      (max_heap.size() - min_heap.size()) * medians.back() -
                      max_heap_cost);
    }
  }

  for (auto cost : costs)
    cout << cost << " ";
  cout << "\n";
}
