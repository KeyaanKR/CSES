#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll n;
  cin >> n;

  vector<ll> x(n), nearestPos;
  for (ll i = 0; i < n; i++) {
    cin >> x[i];
    if (i == 0) {
      nearestPos.push_back(0);
    } else {
      ll index = i - 1;
      while (x[index] >= x[i] && index != -1)
        index = nearestPos[index] - 1;

      nearestPos.push_back(index + 1);
    }
  }

  for (auto pos : nearestPos)
    cout << pos << " ";
  cout << "\n";
}
