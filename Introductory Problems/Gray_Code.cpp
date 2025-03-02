#include <bits/stdc++.h>

typedef long long int ll;

void output(std::vector<std::string> &bits) {
  for (auto str : bits)
    std::cout << str << std::endl;
}

std::vector<std::string> update(std::vector<std::string> &bits) {
  std::vector<std::string> BITS;
  for (ll i = 0; i < bits.size(); i++)
    BITS.push_back("0" + bits[i]);
  for (ll i = bits.size() - 1; i >= 0; i--)
    BITS.push_back("1" + bits[i]);
  return BITS;
}

int main() {
  ll n;
  std::cin >> n;

  std::vector<std::string> bits;
  bits.push_back("0");
  bits.push_back("1");

  for (ll i = 1; i < n; i++)
    bits = update(bits);

  output(bits);
}
