#include <bits/stdc++.h>
using namespace std;

// set<string> solve(string s) {
//   int n = s.length();
//   sort(s.begin(), s.end());
//
//   set<string> uniqueStrings;
//   do {
//     uniqueStrings.insert(s);
//   } while (next_permutation(s.begin(), s.end()));
//
//   return uniqueStrings;
// }

void add(string s, char c, vector<string> &str) {
  int l = s.length();

  for (int j = 0; j < l + 1; j++) {
    string t;
    for (int k = 0; k < l + 1; k++) {
      if (k < j)
        t = t + string(1, s[k]);
      else if (k == j)
        t = t + string(1, c);
      else
        t = t + string(1, s[k - 1]);
    }
    str.push_back(t);
  }
}

void permutate(vector<string> &permutations, char c) {
  if (permutations.size() == 0) {
    permutations.push_back(string(1, c));
  } else {
    vector<string> str;
    for (auto s : permutations)
      add(s, c, str);
    permutations = str;
  }
}

int main() {
  string s;
  cin >> s;

  vector<string> permutations;
  for (auto c : s)
    permutate(permutations, c);

  sort(permutations.begin(), permutations.end());
  auto it = unique(permutations.begin(), permutations.end());
  permutations.erase(it, permutations.end());

  cout << permutations.size() << "\n";
  for (auto s : permutations)
    cout << s << "\n";

  // set<string> uniqueStrings = solve(s);
  //
  // cout << uniqueStrings.size() << "\n";
  // for (string str : uniqueStrings) {
  //   cout << str << "\n";
  // }
}
