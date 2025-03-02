#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll n;
  cin >> n;

  vector<ll> line;
  for (ll i = 0; i < n; i++)
    line.push_back(i + 1);

  ll index = 0;
  while (index < line.size()) {
    if (index % 2 == 0)
      line.push_back(line[index]);
    else
      cout << line[index] << " ";
    index++;
  }
  cout << "\n";
}
