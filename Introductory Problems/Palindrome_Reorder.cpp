#include <bits/stdc++.h>

typedef long long int ll;

int main() {
  std::string s;
  std::cin >> s;

  std::vector<ll> count(26, 0), avail;
  for (ll i = 0; i < s.length(); i++) {
    ll index = int(s[i]) - 65;
    count[index]++;
    if (count[index] == 1)
      avail.push_back(index);
  }

  ll odd = 0;
  for (auto index : avail) {
    if (count[index] % 2 != 0)
      odd++;
  }

  if ((s.length() % 2 == 0 && odd == 0) || (s.length() % 2 == 1 && odd == 1)) {
    ll i = 0;
    for (auto index : avail) {
      while (count[index] > 1) {
        s[i] = char(index + 65);
        s[s.length() - i - 1] = char(index + 65);
        count[index] -= 2;
        i++;
      }
      if (count[index] == 1)
        s[s.length() / 2] = char(index + 65);
    }
    std::cout << s << std::endl;
  } else {
    std::cout << "NO SOLUTION" << std::endl;
  }
}
