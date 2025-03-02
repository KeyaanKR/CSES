#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll n;
  cin >> n;

  vector<ll> k(n);
  for (ll i = 0; i < n; i++)
    cin >> k[i];

  vector<ll> towers;
  for (auto cube : k) {
    ll index = upper_bound(towers.begin(), towers.end(), cube) - towers.begin();
    if (index == towers.size())
      towers.push_back(cube);
    else
      towers[index] = cube;
  }

  cout << towers.size() << "\n";
}
