#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

vector<vector<ll>> matMul(vector<vector<ll>> mat1, vector<vector<ll>> mat2) {
  vector<vector<ll>> mat;
  vector<ll> row1, row2;

  row1.push_back((mat1[0][0] * mat2[0][0]) % MOD +
                 (mat1[0][1] * mat2[1][0]) % MOD);
  row1.push_back((mat1[0][0] * mat2[0][1]) % MOD +
                 (mat1[0][1] * mat2[1][1]) % MOD);
  row2.push_back((mat1[1][0] * mat2[0][0]) % MOD +
                 (mat1[1][1] * mat2[1][0]) % MOD);
  row2.push_back((mat1[1][0] * mat2[0][1]) % MOD +
                 (mat1[1][1] * mat2[1][1]) % MOD);

  for (auto prod : row1)
    prod %= MOD;
  for (auto prod : row2)
    prod %= MOD;

  mat.push_back(row1);
  mat.push_back(row2);

  return mat;
}

vector<vector<ll>> repeatSquaring(vector<vector<ll>> mat, ll n) {
  if (n == 1)
    return mat;

  vector<vector<ll>> half = repeatSquaring(mat, n / 2);
  vector<vector<ll>> result = matMul(half, half);

  if (n % 2 == 1)
    result = matMul(result, mat);

  return result;
}

int main() {
  ll n;
  cin >> n;

  vector<vector<ll>> mat = {{0, 1}, {1, 1}};
  if (n == 0)
    cout << 0 << endl;
  else if (n == 1)
    cout << 1 << endl;
  else {
    vector<vector<ll>> result = repeatSquaring(mat, n - 1);
    cout << result[1][1] % MOD << endl;
  }
}
