#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> applicants(n), apartments(m);
  multiset<ll> apartmentSet;

  for (ll i = 0; i < n; i++)
    cin >> applicants[i];

  sort(applicants.begin(), applicants.end());

  for (ll i = 0; i < m; i++) {
    cin >> apartments[i];
    apartmentSet.insert(apartments[i]);
  }

  sort(apartments.begin(), apartments.end());
  auto it = unique(apartments.begin(), apartments.end());
  apartments.erase(it, apartments.end());

  int allocated = 0;
  for (auto applicant : applicants) {
    auto it1 = apartmentSet.lower_bound(applicant - k);
    auto it2 = apartmentSet.upper_bound(applicant + k);
    for (auto it = it1; it != it2; it++) {
      apartmentSet.erase(it);
      allocated++;
      break;
    }
  }

  cout << allocated << endl;
}
