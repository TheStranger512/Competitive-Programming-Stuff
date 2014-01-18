/* Solved
 * 14543. Range Sum
 * File:   RANGESUM.cpp
 * Author: Andy Y.F. Huang
 * Created on April 25, 2013, 6:30 PM
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

namespace RANGESUM {
typedef long long llong;
llong tree[222222];
int maxlen;

void update(int pos, int val) {
  for (; pos <= maxlen; pos += pos &-pos)
    tree[pos] += val;
}

llong query(int pos) {
  llong res = 0;
  for (; pos > 0; pos -= pos &-pos)
    res += tree[pos];
  return res;
}

void solve(int test_num) {
  int len, startpos = 100000;
  scanf("%d", &len);
  maxlen = len + startpos;
  for (int i = 1, num; i <= len; i++) {
    scanf("%d", &num);
    update(startpos + i, num);
  }
  int quests;
  scanf("%d", &quests);
  for (int q = 0, type, l, r, x; q < quests; q++) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d %d", &l, &r);
      printf("%lld\n", query(r + startpos) - query(l - 1 + startpos));
    }
    else {
      scanf("%d", &x);
      update(startpos--, x);
    }
  }
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
  RANGESUM::solve();
  return 0;
}

