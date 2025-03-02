#include <bits/stdc++.h>

typedef long long int ll;

int main() {
  ll t;
  std::cin >> t;

  for (int n = 1; n <= t; n++) {
    ll total = (std::pow(n, 4) - std::pow(n, 2)) / 2;
    ll sides = 0;
    ll mid = n - 4 > 0 ? 8 * std::pow(n - 4, 2) : 0;
    ll corner = 0;

    std::vector<std::pair<ll, ll>> pos{{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                                       {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    std::vector<ll> posx{0, 1, n - 2, n - 1};

    for (auto x : posx) {
      ll y = n / 2;
      for (auto [dx, dy] : pos) {
        ll X = x + dx;
        ll Y = y + dy;
        if (X >= 0 && X < n && Y >= 0 && Y < n)
          sides++;
      }
    }
    sides *= n - 4 > 0 ? n - 4 : 0;

    std::vector<std::pair<ll, ll>> cor;
    for (auto x : posx) {
      for (auto y : posx) {
        cor.push_back({x, y});
      }
    }

    std::sort(cor.begin(), cor.end());
    auto it = unique(cor.begin(), cor.end());
    cor.erase(it, cor.end());

    for (auto [x, y] : cor) {
      for (auto [dx, dy] : pos) {
        ll X = x + dx;
        ll Y = y + dy;
        if (X >= 0 && X < n && Y >= 0 && Y < n)
          corner++;
      }
    }

    std::cout << total - ((mid + corner) / 2) - sides << std::endl;
  }
}
