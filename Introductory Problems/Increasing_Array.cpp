#include <bits/stdc++.h>

typedef long long int ll;

int main() {
  ll n;
  std::cin >> n;

  ll output = 0;
  ll prev_max = -1;

  std::vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    std::cin >> a[i];
    if (i >= 1) {
      if (a[i] >= prev_max)
        prev_max = a[i];
      else
        output += prev_max - a[i];
    } else
      prev_max = a[0];
  }

  std::cout << output << std::endl;
}
