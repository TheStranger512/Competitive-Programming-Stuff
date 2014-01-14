/*
 * Solved
 * IOI '11 - Pattaya, Thailand
 * Rice Hub
 * File:   ioi1113.cpp
 * Author: Andy Y.F. Huang
 * Created on Aug 26, 2013, 6:56:31 PM
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

using namespace std;

namespace ioi1113 {
typedef long long ll;
int R, L;
ll B;
int x[100111];
ll f[100111], g[100111]; //to 0, to L

void solve(int test_num) {
  scanf("%d %d %lld", &R, &L, &B);
  for (int i = 1; i <= R; i++)
    scanf("%d", x + i);
  f[0] = 0;
  for (int i = 1; i <= R; i++)
    f[i] = f[i - 1] + x[i];
  g[R + 1] = 0;
  for (int i = R; i > 0; i--)
    g[i] = g[i + 1] + L - x[i];
  int res = 1;
  for (int l = 2, h = R; l <= h;) {
    int m = (l + h) >> 1;
    bool ok = false;
    for (int i = m; i <= R; i++) {
      int med = (i + i - m + 1) >> 1;
      ll cost = f[i] - f[med] - ll(i - med) * (x[med]) + g[i - m + 1] - g[med]
          - ll(med - (i - m + 1)) * (L - x[med]);
      if (cost <= B) {
        ok = true;
        break;
      }
    }
    if (ok) {
      res = m;
      l = m + 1;
    } else
      h = m - 1;
  }
  printf("%d\n", res);
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
  ioi1113::solve();
  return 0;
}
