#include <bits/stdc++.h>

typedef long long int ll;

int main() {
  ll n;
  std::cin >> n;

  for (ll i = 0; i < n; i++) {
    ll a, b;
    std::cin >> a >> b;
    if ((a + b) % 3 == 0 && std::max(a, b) <= 2 * std::min(a, b))
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }
}
