#include <bits/stdc++.h>
#include <ios>
using namespace std;

typedef long long int ll;

class Node {
public:
  ll data;
  Node *next;
  Node *prev;

  Node() {
    data = 0;
    next = NULL;
    prev = NULL;
  }

  Node(ll data) {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
  }
};

// O(n*n)
void solve(ll n, ll k) {
  Node *head = new Node(1);
  Node *iter = head;
  for (ll i = 2; i <= n; i++) {
    Node *temp = new Node(i);
    iter->next = temp;
    temp->prev = iter;
    iter = temp;
  }
  iter->next = head;
  head->prev = iter;

  while (n) {
    ll skipF = (k % n);
    ll skipB = n - skipF - 2;

    if (skipF <= skipB || skipB < 0) {
      while (skipF--) {
        iter = iter->next;
      }
      Node *temp = iter->next;
      cout << temp->data << " ";
      iter->next = temp->next;
      temp->next->prev = iter;
    } else {
      while (skipB--) {
        iter = iter->prev;
      }
      Node *temp = iter->prev;
      cout << temp->data << " ";
      iter->prev = temp->prev;
      temp->prev->next = iter;
      iter = iter->prev;
    }
    n--;
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n, k;
  cin >> n >> k;

  solve(n, k);
}
