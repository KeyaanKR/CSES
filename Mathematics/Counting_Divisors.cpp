#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<ll> getSievePrimes(ll n) {
  vector<bool> isPrime(n + 1, true);
  isPrime[0] = isPrime[1] = false;

  for (ll i = 2; i <= sqrt(n); i++) {
    if (isPrime[i]) {
      for (ll j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  vector<ll> primes;
  for (ll i = 2; i <= n; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }

  return primes;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin >> n;

  vector<ll> primes = getSievePrimes(1000);
  for (ll i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    ll divisors = 1;

    for (auto p : primes) {
      if (x % p == 0) {
        ll power = 0;
        while (x % p == 0) {
          x /= p;
          power++;
        }
        divisors *= (power + 1);
      }
    }

    if (x > 1)
      divisors *= 2;

    cout << divisors << "\n";
  }
}
