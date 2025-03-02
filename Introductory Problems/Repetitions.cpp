#include <bits/stdc++.h>

typedef long long int ll;

int main() {
  std::string s;
  std::cin >> s;

  ll n = 1;
  ll o = 1;
  ll i = 1;

  while (i < s.length()) {
    if (s[i] == s[i - 1])
      n += 1;
    else {
      if (o < n)
        o = n;
      n = 1;
    }
    i++;
  }

  o = o > n ? o : n;

  std::cout << o << std::endl;
}
