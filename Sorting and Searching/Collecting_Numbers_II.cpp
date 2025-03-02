#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, m;
  cin >> n >> m;

  vector<ll> x(n), index(n + 1, 0);
  for (ll i = 0; i < n; i++) {
    cin >> x[i];
    index[x[i]] = i;
  }

  ll moves = 1;
  for (ll i = 0; i < n; i++) {
    if (x[i] != n && index[x[i] + 1] < index[x[i]])
      moves++;
  }

  vector<pair<ll, ll>> swap(m);
  for (ll i = 0; i < m; i++)
    cin >> swap[i].first >> swap[i].second;

  for (auto [index1, index2] : swap) {
    index1 = index1 - 1;
    index2 = index2 - 1;

    // get the prev num, curr num for both indices
    // as swapping can change the inversion count at these indices
    vector<ll> nums = {x[index1], x[index1] - 1, x[index2], x[index2] - 1};

    // process the nums -- remove duplicates and invalid entries
    vector<ll> valid_nums;
    for (ll num : nums) {
      if (num > 0)
        valid_nums.push_back(num);
    }
    sort(valid_nums.begin(), valid_nums.end());
    auto iter = unique(valid_nums.begin(), valid_nums.end());
    valid_nums.erase(iter, valid_nums.end());

    ll prevMoves = 0;
    for (auto num : valid_nums) {
      if (num != n && index[num + 1] < index[num])
        prevMoves++;
    }

    index[x[index1]] = index2;
    index[x[index2]] = index1;

    ll temp = x[index1];
    x[index1] = x[index2];
    x[index2] = temp;

    ll currMoves = 0;
    for (auto num : valid_nums) {
      if (num != n && index[num + 1] < index[num])
        currMoves++;
    }

    moves = moves - prevMoves + currMoves;
    cout << moves << "\n";
  }
}
