#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll findIndex(vector<ll> &b, ll &num) {
  ll count = 0;
  for (ll j = 0; j < b.size(); j++) {
    if (b[j] == num) {
      if (count == 0)
        count++;
      else {
        return j + 1;
      }
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, x;
  cin >> n >> x;

  vector<ll> a(n);
  map<ll, ll> index;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    // map num to indice
    index.insert({a[i], i + 1});
  }

  bool flag = false;
  for (ll i = 0; i < n; i++) {
    if (index[x - a[i]]) {
      flag = true;
      if (2 * a[i] != x) {
        cout << index[a[i]] << " " << index[x - a[i]] << "\n";
        break;
      } else if (2 * a[i] == x && findIndex(a, a[i])) {
        cout << index[a[i]] << " " << findIndex(a, a[i]) << "\n";
        break;
      } else {
        flag = false;
        continue;
      }
    }
  }

  if (!flag)
    cout << "IMPOSSIBLE\n" << endl;
}
