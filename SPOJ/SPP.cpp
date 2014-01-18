/* Solved
 * 2699. Recursive Sequence (Version II)
 * File:   SPP.cpp
 * Author: Andy Y.F. Huang
 * Created on June 22, 2013, 3:48 PM
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

namespace SPP {
typedef long long llong;
#define MAX 17
llong base[MAX][MAX], mat[MAX][MAX], temp[MAX][MAX];
int MOD, order, size;
int coef[MAX], seeds[MAX];

void mult(llong A[MAX][MAX], llong B[MAX][MAX]) {
  memset(temp, 0, sizeof (temp));
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      for (int k = 0; k < size; k++)
        temp[i][j] = (temp[i][j] + A[i][k] * B[k][j]) % MOD;
  memcpy(A, temp, sizeof (temp));
}

int go(llong N) {
  if (N <= 0) return 0;
  if (N <= order) return seeds[N];
  memset(mat, 0, sizeof (mat));
  memset(base, 0, sizeof (base));
  for (int i = 0; i <= order; i++)
    mat[i][i] = 1;
  for (int i = 0; i < order; i++) {
    base[0][i] = base[order][i] = coef[i] % MOD;
    if (i + 1 < order)
      base[i + 1][i] = 1;
  }
  base[order][order] = 1;
  N -= order;
  for (llong e = N; e > 0; e >>= 1) {
    if (e & 1) mult(mat, base);
    mult(base, base);
  }
  int res = 0, sum = 0;
  for (int i = 0; i < order; i++) {
    res = (res + mat[order][i] * seeds[order - i - 1]) % MOD;
    sum = (sum + seeds[i]) % MOD;
  }
  res = (res + mat[order][order] * sum) % MOD;
  //plnarr(base, size, size);
  return res;
}

void solve(int test_num) {
  memset(base, 0, sizeof (base));
  scanf("%d", &order);
  for (int i = 0; i < order; i++)
    scanf("%d", seeds + i);
  for (int i = 0; i < order; i++)
    scanf("%d", coef + i);
  size = order + 1;
  llong A, B;
  scanf("%lld %lld %d", &A, &B, &MOD);
  int res = go(B) - go(A - 1);
  if (res < 0) res += MOD;
  printf("%d\n", res);
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
  SPP::solve();
  return 0;
}

