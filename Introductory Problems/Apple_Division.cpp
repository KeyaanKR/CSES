#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll solve(ll index, vector<ll> &vec, ll sum1, ll sum2) {
  if (index == vec.size())
    return abs(sum1 - sum2);
  else
    return min(solve(index + 1, vec, sum1 + vec[index], sum2),
               solve(index + 1, vec, sum1, sum2 + vec[index]));
}

int main() {
  ll n;
  cin >> n;

  vector<ll> vec(n);
  for (ll i = 0; i < n; i++)
    cin >> vec[i];

  cout << solve(0, vec, 0, 0) << "\n";
}
