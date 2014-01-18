/* Solved
 * 8505. Nacci Fear
 * File:   NACCI.cpp
 * Author: Andy Y.F. Huang
 * Created on June 1, 2013, 11:00 PM
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

namespace NACCI {
typedef long long llong;
llong base[30][30], mat[30][30], temp[30][30];
int size, mod;

void mult(llong a[30][30], llong b[30][30], llong c[30][30]) {
  memset(temp, 0, sizeof (temp));
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      for (int k = 0; k < size; k++)
        if ((temp[i][j] += a[i][k] * b[k][j] % mod) >= mod)
          temp[i][j] -= mod;
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      c[i][j] = temp[i][j];
}

void solve(int test_num) {
  int digits, len;
  scanf("%d %d %d", &size, &digits, &len);
  mod = 1;
  for (int i = 0; i < digits; i++)
    mod *= 10;
  if (len < size)
    printf("%d\n", len);
  else {
    memset(mat, 0, sizeof (mat));
    memset(base, 0, sizeof (base));
    for (int i = 0; i < size; i++)
      base[0][i] = mat[i][i] = 1;
    for (int i = 1; i < size; i++)
      base[i][i - 1] = 1;
    for (int e = len - size + 1; e > 0; e >>= 1) {
      if (e & 1)
        mult(mat, base, mat);
      mult(base, base, base);
    }
    llong res = 0;
    for (int i = 0; i < size; i++)
      res += mat[0][i] * (size - i - 1);
    res %= mod;
    printf("%lld\n", res);
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  NACCI::solve();
  return 0;
}

