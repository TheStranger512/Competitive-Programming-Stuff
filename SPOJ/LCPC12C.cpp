/* Solved
 * 12398. Johnny Listens to Music
 * File:   LCPC12C.cpp
 * Author: Andy Y.F. Huang
 * Created on December 10, 2012, 8:35 PM
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
namespace LCPC12C {
#define mod 835454957
#define lim (1 << 24)
int h[55];
int rmq[lim << 1];

void solve(int test_num) {
  memset(rmq, 0x3F, sizeof (rmq));
  //pln(lim);
  int len, m, addedcnt = 0;
  scanf("%d %d", &len, &m);
  for (int i = 0; i < m; i++)
    scanf("%d", &h[i]);
  long long ans = 0;
  for (int i = 0, j = 0, s; i < len; i++) {
    int cur = h[j];
    s = j + 1;
    if (s == m) s = 0;
    h[j] = ((h[j] ^ h[s]) + 13) % mod;
    j = s;
    if (cur % 3 == 0) {
      if (!addedcnt) continue;
      int low = 1 << 30;
      for (int l = lim, r = addedcnt + lim; l < r; l >>= 1, r >>= 1) {
        if (l & 1) low = min(low, rmq[l++]);
        if (r & 1) low = min(low, rmq[--r]);
      }
      ans += low;
    }
    else if (cur % 3 == 1) {
      if (!addedcnt) continue;
      rmq[--addedcnt + lim] = 1 << 30;
      for (int i = (addedcnt + lim) >> 1; i; i >>= 1)
        rmq[i] = min(rmq[i + i], rmq[i + i + 1]);
    }
    else {
      rmq[addedcnt + lim] = cur;
      for (int i = (addedcnt + lim) >> 1; i; i >>= 1)
        rmq[i] = min(rmq[i + i], rmq[i + i + 1]);
      addedcnt++;
    }
  }
  printf("%d. %lld\n", test_num, ans);
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
  LCPC12C::solve();
  return 0;
}

