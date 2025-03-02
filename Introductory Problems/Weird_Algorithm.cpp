#include <bits/stdc++.h>

typedef long long int ll;

int main() {
  ll n;
  std::cin >> n;

  while (n != 1) {
    std::cout << n << " ";
    if (n % 2 == 0)
      n = n / 2;
    else
      n = 3 * n + 1;
  }

  std::cout << "1" << std::endl;
}
