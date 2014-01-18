/* Solved
 * 10818. Medium Factorization
 * File:   FACTCG2.cpp
 * Author: Andy Y.F. Huang
 * Created on February 17, 2013, 7:45 PM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace FACTCG2 {
#define MAX 10000000
bool prime[11000111];
int primes[555], len;
int n;

void solve(int test_num) {
  putchar('1');
  for (int i = 0; !prime[n]; i++) {
    while (n % primes[i] == 0) {
      printf(" x %d", primes[i]);
      n /= primes[i];
    }
  }
  if (n != 1)
    printf(" x %d", n);
  putchar('\n');
}

void init() {
  memset(prime, true, sizeof (prime));
  len = 0;
  for (int i = 2; i <= 3162; i++) {
    if (prime[i]) {
      primes[len++] = i;
      for (int j = i * i; j <= MAX; j += i)
        prime[j] = false;
    }
  }
  pln(len);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  init();
  while (scanf("%d", &n) != EOF)
    solve(1);
}
}

int main() {
  FACTCG2::solve();
  return 0;
}

