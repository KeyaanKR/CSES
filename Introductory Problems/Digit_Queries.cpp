#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll solve(ll query, ll len, vector<ll> &pow10) {
  if (query <= 9 * pow10[len - 1] * len) {
    ll num = pow10[len - 1] + (ll)(query / len);
    num += query % len == 0 ? -1 : 0;

    ll index = query % len;
    if (index == 0)
      index = len;

    vector<int> digits;
    while (num > 0) {
      digits.push_back(num % 10);
      num = num / 10;
    }

    return digits[len - index];
  } else {
    return solve(query - (9 * pow10[len - 1] * len), len + 1, pow10);
  }
}

int main() {
  ll n;
  cin >> n;

  vector<ll> pow10;
  ll expo = 0;
  ll base = 1;
  while (expo <= 18) {
    pow10.push_back(base);
    base *= 10;
    expo += 1;
  }

  vector<int> digit;
  for (ll i = 0; i < n; i++) {
    ll query;
    cin >> query;
    digit.push_back(solve(query, 1, pow10));
  }

  for (auto i : digit)
    cout << i << "\n";
}
