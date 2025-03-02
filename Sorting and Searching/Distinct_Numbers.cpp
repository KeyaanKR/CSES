#include <bits/stdc++.h>

typedef long long int ll;

int main() {
  ll n;
  std::cin >> n;

  std::vector<ll> a(n);
  for (ll i = 0; i < n; i++)
    std::cin >> a[i];

  std::sort(a.begin(), a.end());

  ll o = 1;
  for (ll i = 1; i < n; i++) {
    if (a[i] != a[i - 1])
      o++;
  }
  std::cout << o << std::endl;
}
