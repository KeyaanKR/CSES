#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> passage;

struct Node {
  passage pass;
  ll LPinPass;
  Node *left, *right, *parent;

  Node(passage p)
      : pass(p), LPinPass(p.second - p.first), left(nullptr), right(nullptr),
        parent(nullptr) {}
};

bool inPass(ll &light, passage &pass) {
  if (pass.first < light && light < pass.second)
    return true;
  return false;
}

void insertLight(Node *root, ll light) {
  passage passL = {root->pass.first, light};
  passage passR = {light, root->pass.second};

  root->left = new Node(passL);
  root->right = new Node(passR);

  root->left->parent = root;
  root->right->parent = root;

  root->LPinPass = max(root->left->LPinPass, root->right->LPinPass);
}

void updateLP(Node *node) {
  while (node) {
    if (node->left && node->right)
      node->LPinPass = max(node->left->LPinPass, node->right->LPinPass);
    node = node->parent;
  }
}

Node *findNode(Node *root, ll light) {
  if (!root->left || !root->right)
    return root;

  if (inPass(light, root->left->pass))
    return findNode(root->left, light);
  else
    return findNode(root->right, light);
}

// amortized O(n * logn)
void solve(ll l, vector<ll> p) {
  vector<ll> longestPass;
  Node *root = new Node({0, l});
  for (auto light : p) {
    Node *insertPass = findNode(root, light);
    insertLight(insertPass, light);
    updateLP(insertPass);
    longestPass.push_back(root->LPinPass);
  }

  for (auto LP : longestPass)
    cout << LP << " ";
  cout << "\n";
}

struct CustomComparator {
  bool operator()(const pair<ll, ll> &p1, const pair<ll, ll> &p2) const {
    return p1.second < p2.second;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll x, n;
  cin >> x >> n;

  vector<ll> p(n);
  for (ll i = 0; i < n; i++)
    cin >> p[i];

  set<pair<ll, ll>, CustomComparator> passages;
  multiset<ll, greater<ll>> passageLengths;
  passages.insert({0, x});
  passageLengths.insert(x);
  for (ll i = 0; i < n; i++) {
    auto it = passages.lower_bound({0, p[i]});
    if (it != passages.end()) {
      ll s = it->first;
      ll e = it->second;
      ll len = it->second - it->first;

      passages.erase({s, e});
      passages.insert({s, p[i]});
      passages.insert({p[i], e});

      passageLengths.erase(passageLengths.find(len));
      passageLengths.insert(p[i] - s);
      passageLengths.insert(e - p[i]);
    }
    cout << *passageLengths.begin() << " ";
  }
  cout << "\n";
}
