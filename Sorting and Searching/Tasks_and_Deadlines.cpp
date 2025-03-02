#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool compare(pair<ll, ll> a, pair<ll, ll> b) { return a.first < b.first; }

int main() {
  ll n;
  cin >> n;

  vector<pair<ll, ll>> tasks(n);
  for (ll i = 0; i < n; i++)
    cin >> tasks[i].first >> tasks[i].second;

  sort(tasks.begin(), tasks.end(), compare);

  ll time = 0;
  ll reward = 0;
  for (auto [d, f] : tasks) {
    time += d;
    reward += f - time;
  }

  cout << reward << "\n";
}
