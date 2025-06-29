#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  map<int, int> freq;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    freq[arr[i]]++;
  }

  int count = 1, MOD = 1e9 + 7;
  for (auto &[num, f] : freq)
    count = (1LL * count * (f + 1)) % MOD;
  count--;

  cout << count << endl;
  return 0;
}
