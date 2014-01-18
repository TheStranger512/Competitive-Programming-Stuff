/* Solved
 * 9755. Grey Area
 * File:   SCPC11A.cpp
 * Author: Andy Y.F. Huang
 * Created on September 28, 2012, 3:26 PM
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
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace SCPC11A {
int values, width, cnt[200];

void solve(int test_num) {
  memset(cnt, 0, sizeof (cnt));
  int high = 0, intervals = -1;
  for (int i = 0; i < values; i++) {
    int val;
    scanf("%d", &val);
    cnt[val / width]++;
    high = max(high, cnt[val / width]);
    intervals = max(intervals, val / width + 1);
  }
  double ans = 0.01;
  for (int i = 0, j = intervals - 1; i < intervals; i++, j--) {
    ans += (cnt[i] * j) / (1.0 * high * (intervals - 1));
  }
  printf("%.6lf\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d %d", &values, &width);
    if (values == 0 && width == 0)
      break;
    solve(1);
  }
}
}

int main() {
  SCPC11A::solve();
  return 0;
}

