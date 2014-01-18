/* Solved
 * 14742. Building Bridges(HARD)
 * File:   BRDGHRD.cpp
 * Author: Andy Y.F. Huang
 * Created on April 27, 2013, 10:34 PM
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

namespace BRDGHRD {
int tree[100100], dp[100100];
pair<int, int> pos[100100];
int vals[100100];
int len;

void update(int pos, int val) {
  for (int i = pos; i <= len; i += i&-i)
    tree[i] = max(tree[i], val);
}

int get(int pos) {
  int res = 0;
  for (int i = pos; i > 0; i -= i&-i)
    res = max(res, tree[i]);
  return res;
}

void solve(int test_num) {
  scanf("%d", &len);
  for (int i = 1; i <= len; i++)
    dp[i] = tree[i] = 0;
  for (int i = 0; i < len; i++)
    scanf("%d", &pos[i].first);
  for (int i = 0; i < len; i++) {
    scanf("%d", &pos[i].second);
    vals[i] = pos[i].second;
  }
  sort(pos, pos + len);
  sort(vals, vals + len);
  int cnt = unique(vals, vals + len) - vals;
  for (int i = 0; i < len; i++) {
    int x = lower_bound(vals, vals + cnt, pos[i].second) - vals + 1;
    dp[i] = get(x) + 1;
    update(x, dp[i]);
  }
  printf("%d\n", *max_element(dp, dp + len));
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
  BRDGHRD::solve();
  return 0;
}

