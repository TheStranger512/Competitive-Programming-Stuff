/*
 * Solved
 * 13745. Crack the Safe
 * File:   SAFECRAC.cpp
 * Author: Andy Y.F. Huang
 * Created on February 26, 2013, 12:28 AM
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
namespace SAFECRAC {
#define mod 1000000007
const int FROM[13] = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 7, 7, 8};
const int TO[13] =   {4, 2, 5, 3, 6, 7, 5, 6, 8, 9, 0, 8, 9};

int mat[10][10], base[18][10][10];
long long temp[10][10];

void mult(int a[10][10], int b[10][10], int res[10][10]) {
  memset(temp, 0, sizeof (temp));
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      for (int k = 0; k < 10; k++) {
        temp[i][j] += ((long long) (a[i][k]) * b[k][j]) % mod;
        if (temp[i][j] >= mod)
          temp[i][j] -= mod;
      }
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      res[i][j] = temp[i][j];
}

void solve(int test_num) {
  memset(mat, 0, sizeof (mat));
  int len;
  scanf("%d", &len);
  len--;
  for (int i = 0; i < 10; i++)
    mat[i][i] = 1;
  for (int e = len, i = 0; e > 0; e >>= 1, i++)
    if (e & 1)
      mult(mat, base[i], mat);
  long long ans = 0;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      ans += mat[i][j];
  ans %= mod;
  printf("%lld\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  for (int i = 0; i < 13; i++)
    base[0][FROM[i]][TO[i]] = base[0][TO[i]][FROM[i]] = 1;
  for (int i = 1; i < 18; i++)
    mult(base[i - 1], base[i - 1], base[i]);
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  SAFECRAC::solve();
  return 0;
}

