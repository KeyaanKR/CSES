#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll n;
  cin >> n;

  vector<ll> x(n);
  for (ll i = 0; i < n; i++)
    cin >> x[i];
  sort(x.begin(), x.end());

  ll sum = 1;
  for (ll i = 0; i < n; i++) {
    if (sum < x[i])
      break;
    sum += x[i];
  }

  cout << sum << "\n";
}
