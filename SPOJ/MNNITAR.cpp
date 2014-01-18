/* Solved
 * 11962. Arya Rage
 * File:   MNNITAR.cpp
 * Author: Andy Y.F. Huang
 * Created on May 21, 2013, 11:20 PM
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

namespace MNNITAR {
#define MOD 1000000007
typedef long long llong;
llong base[50][2][2];
llong mat[2][2], temp[2][2];

void mult(llong a[2][2], llong b[2][2], llong c[2][2]) {
  memset(temp, 0, sizeof (temp));
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % (MOD - 1);
  memcpy(c, temp, sizeof (temp));
}

void solve(int test_num) {
  long long n;
  scanf("%lld", &n);
  mat[0][0] = mat[1][1] = 1;
  mat[0][1] = mat[1][0] = 0;
  if (n == 0) {
    puts("1");
    return;
  }
  n--;
  for (int e = 0; e < 50; e++)
    if (1LL << e & n)
      mult(mat, base[e], mat);
  llong res = 1, two = 2;
  for (int e = mat[0][0]; e > 0; e >>= 1) {
    if (e & 1)
      res = (res * two) % MOD;
    two = two * two % MOD;
  }
  printf("%d\n", (int) res);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  base[0][0][0] = base[0][0][1] = base[0][1][0] = 1;
  for (int e = 1; e < 50; e++)
    mult(base[e - 1], base[e - 1], base[e]);
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  MNNITAR::solve();
  return 0;
}

