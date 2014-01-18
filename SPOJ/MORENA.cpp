/* Solved
 * 12209. Morenas Candy Shop ( Easy )
 * File:   MORENA.cpp
 * Author: Andy Y.F. Huang
 * Created on April 28, 2013, 6:46 PM
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

namespace MORENA {
typedef long long llong;
llong vals[1110000], seq[1110000];
int high[1 << 21], low[1 << 21];
int offset, valcnt;

int get(llong x) {
  return lower_bound(vals, vals + valcnt, x) - vals;
}

void update(int* tree, int pos, int val) {
  tree[pos += offset] = val;
  for (pos >>= 1; pos > 0; pos >>= 1)
    tree[pos] = max(tree[pos << 1], tree[pos << 1 | 1]);
}

int query(int* tree, int l, int r) {
  int res = 0;
  for (l += offset, r += offset + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = max(res, tree[l++]);
    if (r & 1) res = max(res, tree[--r]);
  }
  return res;
}

void solve(int test_num) {
  memset(high, 0, sizeof (high));
  memset(low, 0, sizeof (low));
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%lld", seq + i);
    vals[i] = seq[i];
  }
  sort(vals, vals + len);
  valcnt = unique(vals, vals + len) - vals;
  offset = 1;
  while (offset < valcnt)
    offset <<= 1;
  update(low, get(seq[0]), 1);
  update(high, get(seq[0]), 1);
  for (int i = 1; i < len - 1; i++) {
    int id = get(seq[i]);
    update(low, id, query(high, id + 1, valcnt - 1) + 1);
    update(high, id, query(low, 0, id - 1) + 1);
  }
  int id = get(seq[len - 1]);
  int ans = max(query(high, id + 1, valcnt - 1), query(low, 0, id - 1)) + 1;
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  MORENA::solve();
  return 0;
}

