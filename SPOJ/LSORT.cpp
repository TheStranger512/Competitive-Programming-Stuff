/* Solved
 * 676. Sorting is not easy
 * File:   LSORT.cpp
 * Author: Andy Y.F. Huang
 * Created on April 21, 2013, 4:36 PM
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

namespace LSORT {
int dp[1010][1010];
int seq[1010], pos[1010];
int tree[1010], len;

void update(int pos, int val) {
  for (int i = pos; i <= len; i += i&-i)
    tree[i] += val;
}

int query(int pos) {
  int res = 0;
  for (int i = pos; i > 0; i -= i&-i)
    res += tree[i];
  return res;
}

int rec(int l, int r) {
  if (dp[l][r] > -1) return dp[l][r];
  int& res = dp[l][r];
  update(pos[l], 1);
  res = query(pos[l]) * (r - l + 1) + rec(l + 1, r);
  update(pos[l], -1);
  update(pos[r], 1);
  res = min(res, query(pos[r]) * (r - l + 1) + rec(l, r - 1));
  update(pos[r], -1);
  return res;
}

void solve(int test_num) {
  scanf("%d", &len);
  for (int i = 1; i <= len; i++) {
    scanf("%d", seq + i);
    pos[seq[i]] = i;
  }
  memset(tree, 0, sizeof (tree));
  memset(dp, -1, sizeof (dp));
  for (int i = 1; i <= len; i++)
    dp[i][i] = pos[i];
  int ans = rec(1, len);
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
  LSORT::solve();
  return 0;
}

