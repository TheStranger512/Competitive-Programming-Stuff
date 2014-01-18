/*
 * Solved
 * 10514. K12 - Building Construction
 * File:   KOPC12A.cpp
 * Author: Andy Y.F. Huang
 * Created on March 11, 2013, 1:12 PM
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

namespace KOPC12A {
typedef long long llong;
int height[11000], cost[11000];
int len;

llong getcost(int tarH) {
  llong ans = 0;
  for (int i = 0; i < len; i++)
    ans += cost[i] * abs(height[i] - tarH);
  return ans;
}

void solve(int test_num) {
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d", height + i);
  for (int i = 0; i < len; i++)
    scanf("%d", cost + i);
  llong ans = 1LL << 50;
  for (int low = 0, high = 10000; low <= high; ) {
    int mid1 = (2 * low + high) / 3, mid2 = (low + 2 * high) / 3;
    llong a = getcost(mid1), b = getcost(mid2);
    ans = min(ans, min(a, b));
    if (a > b)
      low = mid1 + 1;
    else high = mid2 - 1;
  }
  printf("%lld\n", ans);
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
  KOPC12A::solve();
  return 0;
}

