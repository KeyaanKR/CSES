#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// O(n*k) --> next is O(k);
vector<ll> solve(ll &n, ll &k, vector<ll> &nums) {
  multiset<ll> window(nums.begin(), nums.begin() + k);
  vector<ll> medians;
  ll index = (k + 1) / 2;

  for (ll i = 0; i <= n - k; i++) {
    auto iter = next(window.begin(), index - 1);
    medians.push_back(*iter);
    window.erase(window.find(nums[i]));
    window.insert(nums[i + k]);
  }

  return medians;
}

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
  multiset<pair<ll, ll>> min_heap;
  vector<ll> medians;

  for (ll i = 0; i < n; i++) {
    if (i >= k) {
      if (max_heap.find({nums[i - k], i - k}) != max_heap.end())
        max_heap.erase(max_heap.find({nums[i - k], i - k}));
      else
        min_heap.erase(min_heap.find({nums[i - k], i - k}));
    }

    max_heap.insert({nums[i], i});
    min_heap.insert(*max_heap.begin());
    max_heap.erase(max_heap.find(*max_heap.begin()));

    while (max_heap.size() < min_heap.size()) {
      max_heap.insert(*min_heap.begin());
      min_heap.erase(min_heap.find(*min_heap.begin()));
    }

    if (i >= k - 1)
      medians.push_back(max_heap.begin()->first);
  }

  for (auto median : medians)
    cout << median << " ";
  cout << "\n";
}
