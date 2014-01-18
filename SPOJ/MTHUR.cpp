/* Solved
 * 12012. grace marks
 * File:   MTHUR.cpp
 * Author: Andy Y.F. Huang
 * Created on March 11, 2013, 11:17 PM
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

namespace MTHUR {
#define MAX 11000
int len;
int prev[MAX], now[MAX], fav[5 * MAX];

void solve(int test_num) {
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d", prev + i);
  for (int i = 0; i < len; i++)
    scanf("%d", now + i);
  int favlen;
  scanf("%d", &favlen);
  for (int i = 0; i < favlen; i++)
    scanf("%d", fav + i);
  sort(fav, fav + favlen);
  favlen = unique(fav, fav + favlen) - fav;
  int best = 1 << 30, ans = -1;
  for (int low = 0, high = favlen - 1, m1, m2, d1, d2; low <= high; ) {
    m1 = (2 * low + high) / 3;
    m2 = (low + 2 * high + 2) / 3;
    d1 = d2 = 0;
    for (int i = 0; i < len; i++) {
      d1 += abs(prev[i] - now[i] - fav[m1]);
      d2 += abs(prev[i] - now[i] - fav[m2]);
    }
    if (d1 < best) best = d1, ans = m1;
    if (d2 < best) best = d2, ans = m2;
    if (d1 > d2)
      low = m1 + 1;
    else
      high = m2 - 1;
  }
  printf("%d\n", fav[ans]);
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
  MTHUR::solve();
  return 0;
}

