#include <bits/stdc++.h>

typedef long long int ll;
#define mod 1000000007;
#define input std::cin >> n;
#define output std::cout << o << std::endl;
#define newline std::cout << std::endl;

int main() {
  ll n;
  input;

  ll o = 0;
  while (n >= 1) {
    n /= 5;
    o += n;
  }
  output;
}
