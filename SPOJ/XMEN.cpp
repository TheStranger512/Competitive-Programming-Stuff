/* Solved
 * 13805. X-MEN
 * File:   XMEN.cpp
 * Author: Andy Y.F. Huang
 * Created on February 18, 2013, 3:47 PM
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
namespace XMEN {
typedef pair<int, int> Point;
int posa[111000], len;
Point pts[111000];
int dp[111000];

int query(int pos) {
  int ans = 0;
  for (int i = pos + 1; i > 0; i -= i&-i)
    ans = max(ans, dp[i]);
  return ans;
}

int update(int pos, int val) {
  for (int i = pos + 1; i <= len; i += i&-i)
    dp[i] = max(dp[i], val);
}

void solve(int test_num) {
  scanf("%d", &len);
  for (int i = 0, val; i < len; i++) {
    scanf("%d", &val);
    posa[val] = i;
  }
  for (int i = 0, val; i < len; i++) {
    scanf("%d", &val);
    pts[i].first = posa[val];
    pts[i].second = i;
  }
  sort(pts, pts + len);
  memset(dp, 0, sizeof (dp));
  int ans = 0;
  for (int i = 0; i < len; i++) {
    int temp = query(pts[i].second) + 1;
    ans = max(ans, temp);
    update(pts[i].second, temp);
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
  XMEN::solve();
  return 0;
}

