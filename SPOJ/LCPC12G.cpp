/*
 * Solved
 * 12408. Johnny Studies Genetics
 * File:   LCPC12G.cpp
 * Author: Andy Y.F. Huang
 * Created on March 5, 2013, 9:35 PM
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
namespace LCPC12G {
#define MAX 100
#define MOD 1000000007
typedef long long llong;
int mat[MAX][MAX], base[MAX][MAX], init[MAX];
int size;

void mult(int a[][MAX], int b[][MAX], int c[][MAX]) {
  static llong temp[MAX][MAX];
  memset(temp, 0, sizeof (temp));
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      for (int k = 0; k < size; k++)
        temp[i][j] = (temp[i][j] + (llong) (a[i][k]) * b[k][j]) % MOD;
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      c[i][j] = (int) (temp[i][j]);
}

void solve(int test_num) {
  llong gens;
  scanf("%lld %d", &gens, &size);
  memset(mat, 0, sizeof (mat));
  for (int i = 0; i < size; i++) {
    scanf("%d", init + i);
    mat[i][i] = 1;
  }
  memset(base, 0, sizeof (base));
  for (int i = 0, deg; i < size; i++) {
    scanf("%d", &deg);
    for (int j = 0, pos; j < deg; j++) {
      scanf("%d", &pos);
      base[i][pos] = 1;
    }
  }
  for (llong e = gens; e > 0; e >>= 1) {
    if (e & 1) mult(mat, base, mat);
    mult(base, base, base);
  }
  printf("%d.", test_num);
  for (int i = 0; i < size; i++) {
    llong ans = 0;
    for (int j = 0; j < size; j++) {
      ans += (llong) (mat[i][j]) * init[j];
      ans %= MOD;
    }
    printf(" %d", (int) ans);
  }
  putchar('\n');
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
  LCPC12G::solve();
  return 0;
}


