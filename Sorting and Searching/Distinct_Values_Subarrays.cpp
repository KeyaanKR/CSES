#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  long long count = 0;
  queue<int> q;
  set<int> s;

  for (auto &val : arr) {
    if (s.count(val)) {
      count += 1LL * q.size() * (q.size() + 1) / 2;
      while (s.count(val)) {
        s.erase(q.front());
        q.pop();
      }
      count -= 1LL * q.size() * (q.size() + 1) / 2;
    }
    s.insert(val);
    q.push(val);
  }
  count += 1LL * q.size() * (q.size() + 1) / 2;

  cout << count << endl;
  return 0;
}
