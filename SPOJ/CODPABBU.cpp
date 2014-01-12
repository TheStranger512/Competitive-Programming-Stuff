/* Solved
 * SPOJ 16214. Pabbu-pneumonia
 * File:   CODPABBU.cpp
 * Author: Andy Y.F. Huang
 * Created on Dec 1, 2013, 5:50:06 PM
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

using namespace std;

namespace CODPABBU {
int mod;
typedef long long ll;
ll mat[3][3], base[3][3];

void mult(ll c[3][3], ll a[3][3], ll b[3][3]) {
  static ll temp[3][3];
  memset(temp, 0, sizeof(temp));
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % mod;
  memcpy(c, temp, sizeof(temp));
}

void solve(int test_num) {
  int a, d, r, n;
  scanf("%d %d %d %d %d", &a, &d, &r, &n, &mod);
  memset(mat, 0, sizeof(mat));
  memset(base, 0, sizeof(base));
  mat[0][0] = mat[1][1] = mat[2][2] = 1;
  base[0][1] = base[0][2] = base[2][2] = 1;
  base[1][1] = base[1][2] = r;
  //plnarr(base, 3, 3);
  for (int e = n / 2; e > 0; e >>= 1) {
    if (e & 1)
      mult(mat, mat, base);
    mult(base, base, base);
  }
  ll res = 0;
  if (n & 1)
    res = (mat[1][1] * a + mat[1][2] * d) % mod;
  else
    res = (mat[0][1] * a + mat[0][2] * d) % mod;
  printf("%d\n", (int) res);
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
  CODPABBU::solve();
  return 0;
}
