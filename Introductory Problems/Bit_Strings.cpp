#include <bits/stdc++.h>

typedef long long int ll;
#define mod 1000000007;
#define newline std::cout << std::endl;

int main() {
  ll n;
  std::cin >> n;

  ll output = 1;
  for (ll i = 1; i <= n; i++)
    output = (output * 2) % mod;

  std::cout << output << std::endl;
}
