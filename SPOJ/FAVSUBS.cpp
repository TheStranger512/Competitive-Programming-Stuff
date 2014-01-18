/* Solved
 * 8409. Favorite Sub Hair
 * File:   FAVSUBS.cpp
 * Author: Andy Y.F. Huang
 * Created on April 17, 2013, 8:35 PM
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

namespace FAVSUBS {
int cols[1111], arr[111000];
int rmq[2222], offset;

void update(int pos, int val) {
  rmq[pos + offset] = val;
  for (int i = (pos + offset) >> 1; i > 0; i >>= 1)
    rmq[i] = min(rmq[i << 1], rmq[i << 1 | 1]);
}

int get(int l, int r) {
  int ans = 13371337;
  for (l += offset, r += offset + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = min(ans, rmq[l++]);
    if (r & 1) ans = min(ans, rmq[--r]);
  }
  return ans;
}

void solve(int test_num) {
  int len, colors;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d", arr + i);
  scanf("%d", &colors);
  for (int i = 0; i < colors; i++)
    scanf("%d", cols + i);
  sort(cols, cols + colors);
  offset = 1;
  while (offset < colors)
    offset <<= 1;
  memset(rmq, -1, sizeof (rmq));
  long long ans = 0;
  for (int i = 0; i < len; i++) {
    int pos = lower_bound(cols, cols + colors, arr[i]) - cols;
    if (pos < colors && cols[pos] == arr[i])
      update(pos, i);
    ans += get(0, colors - 1) + 1;
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
  FAVSUBS::solve();
  return 0;
}

