/* Solved
 * 8057. Square Free Factorization
 * File:   AMR10C.cpp
 * Author: Andy Y.F. Huang
 * Created on August 8, 2012, 1:51 PM
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace AMR10C {
const int max_n = 1010;
bool prime[max_n];
int primes[max_n >> 2];

void sieve() {
  memset(prime, true, sizeof (prime));
  int len = 0, i;
  for (i = 2; i * i < max_n; i++) {
    if (prime[i]) {
      primes[len++] = i;
      for (int j = i * i; j < max_n; j += i)
        prime[j] = false;
    }
  }
  for (; i < max_n; i++)
    if (prime[i])
      primes[len++] = i;
}

void solve(int test_num) {
  int num, sq, ans = 1;
  scanf("%d", &num);
  sq = (int) sqrt(num);
  for (int i = 0; i < 169 && num >= primes[i]; i++) {
    int cnt = 0;
    while (num % primes[i] == 0) {
      cnt++;
      num /= primes[i];
    }
    ans = max(ans, cnt);
  }
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
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
  AMR10C::solve();
  return 0;
}

