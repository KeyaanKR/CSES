#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll n, x;
  cin >> n >> x;

  vector<ll> p(n);
  for (ll i = 0; i < n; i++)
    cin >> p[i];

  sort(p.begin(), p.end());

  ll s = 0;
  ll e = n - 1;
  ll count = 0;

  while (s <= e) {
    if (p[e] + p[s] <= x)
      s++;
    e--;
    count++;
  }

  cout << count << "\n";
}
