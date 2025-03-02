#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll n;
  cin >> n;

  vector<pair<ll, ll>> ab(n);
  for (ll i = 0; i < n; i++)
    cin >> ab[i].first >> ab[i].second;

  vector<pair<ll, ll>> roomAssign = ab;
  sort(roomAssign.begin(), roomAssign.end());

  set<ll> availableRooms;
  auto cmp = [](pair<ll, ll> a, pair<ll, ll> b) { return a.second > b.second; };
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(cmp)>
      occupiedRooms(cmp);
  map<pair<ll, ll>, vector<ll>> roomOccupy;
  ll roomNum = 1;
  for (ll i = 0; i < n; i++) {
    pair<ll, ll> currRoom = roomAssign[i];
    while (occupiedRooms.size() > 0 &&
           occupiedRooms.top().second < currRoom.first) {
      availableRooms.insert(occupiedRooms.top().first);
      occupiedRooms.pop();
    }

    if (availableRooms.empty())
      availableRooms.insert(roomNum++);

    ll room = *availableRooms.begin();
    roomOccupy[currRoom].push_back(room);
    occupiedRooms.push({room, currRoom.second});
    availableRooms.erase(availableRooms.begin());
  }

  cout << roomNum - 1 << "\n";
  for (ll i = 0; i < n; i++) {
    cout << roomOccupy[ab[i]].back() << " ";
    roomOccupy[ab[i]].pop_back();
  }
  cout << "\n";

  return 0;
}
