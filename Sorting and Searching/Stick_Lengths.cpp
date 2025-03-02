#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll n;
  cin >> n;

  vector<ll> p(n);
  for (ll i = 0; i < n; i++)
    cin >> p[i];
  sort(p.begin(), p.end());

  ll cost1 = 0;
  ll cost2 = 0;
  for (ll i = 0; i < n; i++) {
    cost1 += abs(p[i] - p[n / 2]);
    cost2 += abs(p[i] - p[(int)(n / 2) + 1]);
  }

  cout << min(cost1, cost2) << "\n";
}
