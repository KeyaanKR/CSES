#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll n;
  cin >> n;

  vector<ll> k(n);
  for (ll i = 0; i < n; i++)
    cin >> k[i];

  ll maxCount = -1, start = 0, end = 0;
  map<ll, ll> indexCurrSeq;
  for (ll i = 0; i < n; i++) {
    ll id = k[i];

    if (indexCurrSeq.find(id) != indexCurrSeq.end() &&
        indexCurrSeq[id] >= start) {
      maxCount = max(maxCount, end - start);

      while (1) {
        if (k[start] == id) {
          start++;
          break;
        }
        start++;
      }
    }

    indexCurrSeq[id] = i;
    end++;
  }

  maxCount = max(maxCount, end - start);
  cout << maxCount << "\n";
}
