#include <bits/stdc++.h>

typedef long long int ll;

int main() {
  ll n;
  std::cin >> n;

  ll o = (n * (n + 1)) / 2;

  for (ll i = 0; i < n - 1; i++) {
    ll t;
    std::cin >> t;
    o -= t;
  }

  std::cout << o << std::endl;
}
