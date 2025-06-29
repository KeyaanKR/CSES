#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MOD 1000000007

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
  ll n;
  cin >> n;

  vector<ll> primes = getSievePrimes(10e6);

  ll sum = n % MOD;
  for (auto prime : primes) {
    ll power = 1;
    while (n >= pow(prime, power)) {
      ll divisor = pow(prime, power);
      ll multiples = n / divisor;
      sum = (sum + ((divisor * multiples) % MOD)) % MOD;
      power++;
    }
  }

  cout << sum << "\n";
}
