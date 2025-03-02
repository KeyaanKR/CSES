#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// O(n*m) --> due to deletion
void method1() {
  ll n, m;
  cin >> n >> m;

  vector<ll> h(n), t(m), tAlloc(m, -1);
  map<ll, ll> hAvail;

  for (ll i = 0; i < n; i++) {
    cin >> h[i];
    if (hAvail.find(h[i]) == hAvail.end())
      hAvail.insert(pair<ll, ll>(h[i], 1));
    else
      hAvail[h[i]]++;
  }
  sort(h.begin(), h.end());
  auto it = unique(h.begin(), h.end());
  h.erase(it, h.end());

  for (ll i = 0; i < m; i++) {
    cin >> t[i];

    ll index = lower_bound(h.begin(), h.end(), t[i]) - h.begin();
    if (h[index] != t[i])
      index--;

    if (hAvail[h[index]]) {
      tAlloc[i] = h[index];
      hAvail[h[index]]--;

      if (!hAvail[h[index]])
        h.erase(h.begin() + index);
    }
  }

  for (ll i = 0; i < m; i++)
    cout << tAlloc[i] << "\n";
}

// O(n*logn)
void method2() {
  int n, m;
  cin >> n >> m;

  multiset<int> hAvail;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    // O(logn)
    hAvail.insert(h);
  }

  for (ll i = 0; i < m; i++) {
    ll t;
    cin >> t;

    // O(logn)
    auto it = hAvail.upper_bound(t);
    if (it != hAvail.begin()) {
      --it;
      cout << *it << "\n";
      hAvail.erase(it);
    } else {
      cout << "-1\n";
    }
  }
}

int main() {
  // method1();
  method2();
}
