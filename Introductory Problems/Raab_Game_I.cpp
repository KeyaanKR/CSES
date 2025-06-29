#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;

    int draws = n - a - b, maxScore = a + b - 1;
    if ((max(a, b) > maxScore && (a || b)) || draws < 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = 1; i <= n; i++)
        cout << i << " ";
      cout << "\n";
      for (int i = 1; i <= b; i++)
        cout << a + i << " ";
      for (int i = 1; i <= a; i++)
        cout << i << " ";
      for (int i = 1; i <= draws; i++)
        cout << a + b + i << " ";
      cout << "\n";
    }
  }

  return 0;
}
