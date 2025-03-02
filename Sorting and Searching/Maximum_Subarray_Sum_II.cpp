#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  vector<ll> nums(n);
  for (ll i = 0; i < n; i++)
    cin >> nums[i];

  vector<ll> prefix_sum(n + 1);
  prefix_sum[0] = 0;
  for (ll i = 1; i <= n; i++)
    prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
}
