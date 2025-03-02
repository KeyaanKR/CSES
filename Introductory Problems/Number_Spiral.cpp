#include <bits/stdc++.h>

typedef long long int ll;

int main() {
  ll n;
  std::cin >> n;

  for (ll k = 0; k < n; k++) {
    ll i, j;
    std::cin >> i >> j;

    if (i <= j) {
      if (j % 2 == 0)
        std::cout << (j - 1) * (j - 1) + i << std::endl;
      else
        std::cout << j * j + 1 - i << std::endl;
    } else {
      if (i % 2 == 0)
        std::cout << i * i + 1 - j << std::endl;
      else
        std::cout << (i - 1) * (i - 1) + j << std::endl;
    }
  }
}
