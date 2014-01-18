/* Solved
 * 13588. One X LIS
 * File:   ONEXLIS.cpp
 * Author: Andy Y.F. Huang
 * Created on June 21, 2013, 9:20 PM
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

namespace ONEXLIS {
int arr[100111];
vector<int> vals;
int tree[2][1 << 18];
int offset;

void update(int* tree, int p, int v) {
  tree[p += offset] = v;
  for (p >>= 1; p > 0; p >>= 1)
    tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
}

int get(int* tree, int l, int r) {
  int res = -13371337;
  for (l += offset, r += offset + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = max(res, tree[l++]);
    if (r & 1) res = max(res, tree[--r]);
  }
  return res;
}

void solve(int test_num) {
  vals.clear();
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%d", arr + i);
    vals.push_back(arr[i]);
  }
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  offset = 1;
  while (offset < len) offset <<= 1;
  memset(tree[0], 0xC0, 8 * offset);
  memset(tree[1], 0xc0, 8 * offset);
  int res = 0;
  for (int i = 0; i < len; i++) {
    arr[i] = lower_bound(vals.begin(), vals.end(), arr[i]) - vals.begin();
    int onex = get(tree[0], arr[i] + 1, vals.size()) + 1;
    onex = max(onex, get(tree[1], 0, arr[i]) + 1);
    update(tree[1], arr[i], onex);
    res = max(res, onex);
    int lis = get(tree[0], 0, arr[i]) + 1;
    lis = max(lis, 1);
    update(tree[0], arr[i], lis);
  }
  printf("%d\n", res);
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
  ONEXLIS::solve();
  return 0;
}

