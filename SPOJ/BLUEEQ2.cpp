/* Solved
 * 1458. Help Blue Mary Please! (Act II)
 * File:   BLUEEQ2.cpp
 * Author: Andy Y.F. Huang
 * Created on October 27, 2012, 11:47 AM
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
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace BLUEEQ2 {
int lim;
int coefs[9], degs[9];
int a[3444555], b[3444555];
int term[6][155];

int fpow(int base, int expon) {
  int ans = 1, temp = base;
  while (expon > 0) {
    if (expon & 1)
      ans *= temp;
    temp *= temp;
    expon >>= 1;
  }
  return ans;
}

void solve1() {
  if (coefs[0] == 0)
    printf("%d\n", lim);
  else
    puts("0");
}

void solve2() {
  int ans = 0;
  for (int i = 1; i <= lim; i++)
    for (int j = 1; j <= lim; j++)
      if (term[0][i] + term[1][j] == 0)
        ans++;
  printf("%d\n", ans);
}

void solve3() {
  int ans = 0;
  for (int i = 1; i <= lim; i++)
    for (int j = 1; j <= lim; j++)
      for (int k = 1; k <= lim; k++)
        if (term[0][i] + term[1][j] + term[2][k] == 0)
          ans++;
  printf("%d\n", ans);
}

void countans(int lena, int lenb) {
  int ans = 0;
  sort(a, a + lena);
  sort(b, b + lenb);
  for (int i = 0, j = 0; i < lena && j < lenb; ) {
    if (a[i] < b[j])
      i++;
    else if (a[i] > b[j])
      j++;
    else {
      int cnta = 0, cntb = 0;
      int cur = a[i], k = i;
      while (a[k] == cur) {
        cnta++;
        k++;
      }
      i = k;
      cur = b[j];
      k = j;
      while (b[k] == cur) {
        cntb++;
        k++;
      }
      j = k;
      ans += cnta * cntb;
    }
  }
  printf("%d\n", ans);
}

void solve4() {
  //  int ans = 0;
  //  for (int i = 1; i <= lim; i++)
  //    for (int j = 1; j <= lim; j++)
  //      for (int k = 1; k <= lim; k++)
  //        for (int l = 1; l <= lim; l++)
  //          if (coefs[0] * fpow(i, degs[0]) + coefs[1] * fpow(j, degs[1])
  //                  + coefs[2] * fpow(k, degs[2]) + coefs[3] * fpow(l, degs[3]) == 0)
  //            ans++;
  //  pln(ans);
  int lena = 0, lenb = 0;
  for (int i = 1; i <= lim; i++)
    for (int j = 1; j <= lim; j++)
      a[lena++] = term[0][i] + term[1][j];
  for (int i = 1; i <= lim; i++)
    for (int j = 1; j <= lim; j++)
      b[lenb++] = -(term[2][i] + term[3][j]);
  countans(lena, lenb);
}

void solve5() {
  int lena = 0, lenb = 0;
  for (int i = 1; i <= lim; i++)
    for (int j = 1; j <= lim; j++)
      for (int k = 1; k <= lim; k++)
        a[lena++] = term[0][i] + term[1][j] + term[2][k];
  for (int i = 1; i <= lim; i++)
    for (int j = 1; j <= lim; j++)
      b[lenb++] = -(term[3][i] + term[4][j]);
  countans(lena, lenb);
}

void solve6() {
  int lena = 0, lenb = 0;
  for (int i = 1; i <= lim; i++)
    for (int j = 1; j <= lim; j++)
      for (int k = 1; k <= lim; k++)
        a[lena++] = term[0][i] + term[1][j] + term[2][k];
  for (int i = 1; i <= lim; i++)
    for (int j = 1; j <= lim; j++)
      for (int k = 1; k <= lim; k++)
        b[lenb++] = -(term[3][i] + term[4][j] + term[5][k]);
  countans(lena, lenb);
}

void solve(int test_num) {
  int len;
  scanf("%d %d", &len, &lim);
  for (int i = 0; i < len; i++)
    scanf("%d %d", &coefs[i], &degs[i]);
  for (int i = 0; i < len; i++)
    for (int j = 1; j <= lim; j++)
      term[i][j] = coefs[i] * fpow(j, degs[i]);
  if (len == 1)
    solve1();
  else if (len == 2)
    solve2();
  else if (len == 3)
    solve3();
  else if (len == 4)
    solve4();
  else if (len == 5)
    solve5();
  else
    solve6();
}

void solve() {
  #ifdef AZN
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
  BLUEEQ2::solve();
  return 0;
}

