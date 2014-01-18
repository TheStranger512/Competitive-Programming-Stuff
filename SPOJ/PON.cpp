/* Solved
 * 288. Prime or Not
 * File:   PON.cpp
 * Author: Andy Y.F. Huang
 * Created on August 11, 2012, 1:43 AM
 */

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

namespace PON {
//Miller Rabin primality testing
typedef long long llong;
const long long witnesses[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

llong mult(llong a, llong b, llong mod) {
  llong res = 0;
  for (; a > 0; a >>= 1) {
    if (a & 1)
      res = (res + b) % mod;
    b = (b << 1) % mod;
  }
  return res;
}

llong power(llong base, llong exp, llong mod) {
  llong ans = 1LL;
  while (exp) {
    if (exp & 1)
      ans = mult(ans, base, mod);
    base = mult(base, base, mod);
    exp >>= 1LL;
  }
  return ans;
}

bool millerRabin(long long num) {
  if (num <= 1)
    return false;
  if (num <= 3)
    return true;
  if ((num & 1) == 0)
    return false;
  llong d = num - 1, s = 0;
  while ((d & 1) == 0) {
    d >>= 1;
    s++;
  }
  for (int i = 0; i < 12; i++) {
    if (witnesses[i] > num - 2)
      break;
    llong x = power(witnesses[i], d, num);
    if (x == 1 || x == num - 1)
      continue;
    bool flag = false;
    for (unsigned int j = 0; j < s; j++) {
      x = power(x, 2, num);
      if (x == 1)
        return false;
      if (x == num - 1) {
        flag = true;
        break;
      }
    }
    if (!flag)
      return false;
  }
  return true;
}

bool slow(long long num) {
  long long sq = (long long) sqrt(num);
  for (int i = 2; i <= sq; i++)
    if (num % i == 0)
      return false;
  return true;
}

void solve(int test_num) {
  long long num;
  scanf("%lld", &num);
  bool good = millerRabin(num);
  if (good)
    puts("YES");
  else
    puts("NO");
//  bool real = slow(num);
//  if (real != good) {
//    pln(num);
//    //assert(false);
//  }
}

void makecase() {
  freopen("input.txt", "w", stdout);
  srand(time(NULL));
  int len = 1000;
  printf("%d\n", len);
  for (int i = 0; i < len; i++)
    printf("%lld\n", (rand() % 2000000000LL << 2LL) + 1);
}

void solve() {
  #ifdef AZN
  //makecase();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  PON::solve();
  return 0;
}

