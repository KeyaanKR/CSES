#include <bits/stdc++.h>

typedef long long int ll;

void output(ll n, ll l, ll m, ll r) {
  if (n == 1)
    std::cout << l << " " << r << std::endl;
  else {
    output(n - 1, l, r, m);
    std::cout << l << " " << r << std::endl;
    output(n - 1, m, l, r);
  }
}

int main() {
  ll n;
  std::cin >> n;

  std::cout << std::pow(2, n) - 1 << std::endl;
  output(n, 1, 2, 3);
}
