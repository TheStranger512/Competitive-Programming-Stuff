/* Solved
 * 665. String it out
 * File:   SUBS.cpp
 * Author: Andy Y.F. Huang
 * Created on April 21, 2013, 9:29 PM
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

namespace SUBS {
char X[500500], Y[500500];

void solve(int test_num) {
  scanf("%s %s", X, Y);
  int lenX = strlen(X), lenY = strlen(Y);
  int ans = 0;
  for (int low = 1, high = lenY; low <= high; ) {
    int mid = (low + high) >> 1;
    bool ok = false;
    for (int y = 0, x = 0, cnt = mid; y < lenY; y++) {
      if (Y[y] == X[x]) {
        cnt--;
        if (cnt == 0) {
          x++;
          cnt = mid;
        }
      }
      if (x == lenX) {
        ok = true;
        break;
      }
    }
    if (ok) {
      ans = mid;
      low = mid + 1;
    }
    else high = mid - 1;
  }
  printf("%d\n", ans);
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
  SUBS::solve();
  return 0;
}

