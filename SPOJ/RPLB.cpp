/* Solved
 * 11372. Blueberries
 * File:   RPLB.cpp
 * Author: Andy Y.F. Huang
 * Created on May 24, 2013, 1:21 AM
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

namespace RPLB {
bool a[1111], b[1111], c[1111];
int val[1111];

void solve(int test_num) {
  int len, lim;
  scanf("%d %d", &len, &lim);
  for (int i = 0; i < len; i++)
    scanf("%d", val + i);
  memset(a, false, sizeof (a));
  memset(b, false, sizeof (b));
  a[0] = b[0] = true;
  for (int i = 0; i < len; i++) {
    memcpy(c, a, sizeof (c));
    for (int j = lim - val[i]; j >= 0; j--)
      c[j + val[i]] |= c[j];
    for (int j = 0; j <= lim; j++)
      a[j] |= b[j];
    memcpy(b, c, sizeof (b));
  }
  for (int i = lim; i >= 0; i--)
    if (c[i]) {
      printf("Scenario #%d: %d\n", test_num, i);
      break;
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
  RPLB::solve();
  return 0;
}

