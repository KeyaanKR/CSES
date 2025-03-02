#include <bits/stdc++.h>

typedef long long int ll;

int main() {
  ll n;
  std::cin >> n;

  if (n % 4 == 3 || n % 4 == 0) {
    std::cout << "YES" << std::endl;
    std::cout << n / 2 << std::endl;

    ll r = n % 4;

    std::vector<ll> t;
    for (ll i = 1; i <= n; i++) {
      if ((i - r) % 4 == 0 || (i - r) % 4 == 1)
        std::cout << i << " ";
      else
        t.push_back(i);
    }
    std::cout << std::endl;

    std::cout << t.size() << std::endl;
    for (auto i : t) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
}
