#include <bits/stdc++.h>
using namespace std;

// exceeds memory usage
void solve() {
  int n;
  cin >> n;

  vector<pair<int, int>> customers(n);
  int minStartTime = pow(10, 9) + 1;
  int maxStartTime = -1;
  for (int i = 0; i < n; i++) {
    cin >> customers[i].first >> customers[i].second;
    minStartTime = min(minStartTime, customers[i].first);
    maxStartTime = max(maxStartTime, customers[i].first);
  }

  vector<int> timeline(maxStartTime + 1, 0);
  for (int i = 0; i < n; i++) {
    timeline[customers[i].first]++;
    if (customers[i].second < maxStartTime)
      timeline[customers[i].second + 1]--;
  }

  int maxCount = -1;
  int count = 0;
  for (int i = minStartTime; i <= maxStartTime; i++) {
    count += timeline[i];
    maxCount = max(count, maxCount);
  }

  cout << maxCount << "\n";
}

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> customers(n);
  for (int i = 0; i < n; i++)
    cin >> customers[i].first >> customers[i].second;

  vector<pair<int, int>> timeline;
  for (int i = 0; i < n; i++) {
    timeline.push_back({customers[i].first, 1});
    timeline.push_back({customers[i].second, -1});
  }
  sort(timeline.begin(), timeline.end());

  int maxCount = -1;
  int count = 0;
  for (int i = 0; i < 2 * n; i++) {
    count += timeline[i].second;
    maxCount = max(count, maxCount);
  }

  cout << maxCount << "\n";
}
