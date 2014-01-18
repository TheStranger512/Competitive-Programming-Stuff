/* Solved
 * 4318. Catch Fish
 * File:   MFISH.cpp
 * Author: Andy Y.F. Huang
 * Created on March 7, 2013, 12:42 AM
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

namespace MFISH {

template <class T, size_t size> struct FenwickTree {
  T tree[size + 1];

  void init() {
    memset(tree, 0, sizeof (tree));
  }

  void update(int pos, T val) {
    for (int i = pos; i <= (int) size; i += i&-i)
      tree[i] = max(tree[i], val);
  }

  T query(int pos) const {
    T ans = 0;
    for (int i = pos; i > 0; i -= i&-i)
      ans = max(ans, tree[i]);
    return ans;
  }
} ;

typedef pair<int, int> Ship;
Ship ships[111000];
FenwickTree<int, 111000 > dp;
int cnt[111000];

void solve(int test_num) {
  dp.init();
  cnt[0] = 0;
  int len, shipcnt;
  scanf("%d", &len);
  for (int i = 1; i <= len; i++) {
    scanf("%d", cnt + i);
    cnt[i] += cnt[i - 1];
  }
  scanf("%d", &shipcnt);
  for (int i = 0; i < shipcnt; i++)
    scanf("%d %d", &ships[i].first, &ships[i].second);
  sort(ships, ships + shipcnt);
  int pst = 0;
  for (int i = 0; i < shipcnt; i++) {
    int size = ships[i].second;
    int anch = ships[i].first;
    int lim = min(len - size + 1, anch);
    if (i < shipcnt - 1)
      lim = min(lim, ships[i + 1].first - size);
    int st = max(1, anch - size + 1);
    if (i > 0)
      st = max(st, pst + ships[i - 1].second);
    pst = st;
    for (int j = lim; j >= st; j--)
      dp.update(j + size - 1, dp.query(j - 1) + cnt[j + size - 1] - cnt[j - 1]);
  }
  printf("%d\n", dp.query(len));
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
  MFISH::solve();
  return 0;
}

