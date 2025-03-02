#include <bits/stdc++.h>

typedef long long int ll;

int main() {
  ll n;
  std::cin >> n;

  if (n != 2 && n != 3) {
    for (ll i = 1; i <= n / 2; i++)
      std::cout << 2 * i << " ";
    ll bound = n % 2 == 0 ? n / 2 - 1 : n / 2;
    for (ll i = 0; i <= bound; i++)
      std::cout << 2 * i + 1 << " ";
    std::cout << std::endl;
  } else
    std::cout << "NO SOLUTION" << std::endl;
}
