#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n, x;
  cin >> n >> x;

  vector<ll> a(n);
  map<ll, vector<ll>> index;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    index[a[i]].push_back(i);
  }

  sort(a.begin(), a.end());

  int flag = 0;
  for (ll i = 0; i < n; i++) {
    for (ll j = i + 1; j < n; j++) {
      ll left = x - a[i] - a[j];
      ll s = j + 1;
      ll e = n - 1;
      while (a[s] + a[e] != left && e > s) {
        if (a[s] + a[e] > left)
          e--;
        else
          s++;
      }

      if (a[s] + a[e] == left && e > s) {
        int index1 = index[a[i]].back();
        index[a[i]].pop_back();
        int index2 = index[a[j]].back();
        index[a[j]].pop_back();
        int index3 = index[a[s]].back();
        index[a[s]].pop_back();
        int index4 = index[a[e]].back();
        index[a[e]].pop_back();
        cout << index1 + 1 << " " << index2 + 1 << " " << index3 + 1 << " "
             << index4 + 1 << "\n";
        flag = 1;
        return 0;
      }
    }
  }

  if (flag == 0)
    cout << "IMPOSSIBLE\n";
}
