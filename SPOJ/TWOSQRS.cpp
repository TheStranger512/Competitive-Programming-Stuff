/* Solved
 * 91. Two squares or not two squares
 * File:   TWOSQRS.cpp
 * Author: Andy Y.F. Huang
 * Created on August 10, 2012, 12:39 AM
 */

#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstring>
#include <ctime>
#include <algorithm>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace TWOSQRS {
const int k_max_n = 1000010;
bool prime[k_max_n];
int primes[k_max_n >> 2];

void sieve() {
  memset(prime, true, sizeof (prime));
  int len = 0, i;
  for (i = 2; i * i < k_max_n; i++) {
    if (prime[i]) {
      primes[len++] = i;
      for (int j = i * i; j < k_max_n; j += i)
        prime[j] = false;
    }
  }
  for (; i < k_max_n; i++)
    if (prime[i])
      primes[len++] = i;
}

void solve(int test_num) {
  long long num;
  scanf("%lld", &num);
  int lim = (int) sqrt(num);
  for (int i = 0; num > 1 && primes[i] <= lim; i++) {
    int cnt = 0;
    while (num % primes[i] == 0) {
      cnt++;
      num /= primes[i];
    }
    if ((cnt & 1) && primes[i] % 4 == 3) {
      puts("No");
      return;
    }
  }
  if (num % 4 == 3)
    puts("No");
  else
    puts("Yes");
}

void makeCase() {
  srand(time(NULL));
  freopen("input.txt", "w", stdout);
  printf("%d\n", 100);
  for (int i = 0; i < 100; i++)
    printf("%lld\n", rand() % 100000000000LL);
}

void solve() {
  #ifdef AZN
  //makeCase();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  sieve();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  TWOSQRS::solve();
  return 0;
}

