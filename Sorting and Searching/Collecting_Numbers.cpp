#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll n;
  cin >> n;

  vector<ll> x(n), index(n + 1, 0);
  for (ll i = 0; i < n; i++) {
    cin >> x[i];
    index[x[i]] = i;
  }

  ll moves = 1;

  for (ll i = 0; i < n; i++) {
    if (x[i] != n && index[x[i] + 1] < index[x[i]])
      moves++;
  }

  cout << moves << "\n";
}
