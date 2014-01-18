/* Solved
 * 7187. Dinosaur Menace
 * File:   DINOSM.cpp
 * Author: Andy Y.F. Huang
 * Created on March 31, 2013, 9:58 PM
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

namespace DINOSM {
#define SOURCE 301
#define SINK 302
#define sq(x) ((x)*(x))
int cnt, width, height;
int x[333], y[333];
int last[333], to[222222], next[222222], q[333];
double between[333][333];
bool vis[333];
int edges;

void addedge(int a, int b) {
  to[edges] = b;
  next[edges] = last[a];
  last[a] = edges++;
  to[edges] = a;
  next[edges] = last[b];
  last[b] = edges++;
}

bool poss(double dist) {
  memset(last, -1, sizeof (last));
  double sqdist = 4.0 * dist * dist;
  edges = 0;
  for (int i = 0; i < cnt; i++) {
    if (y[i] + dist >= height || x[i] <= dist)
      addedge(SOURCE, i);
    if (y[i] <= dist || x[i] + dist >= width)
      addedge(SINK, i);
    for (int j = i + 1; j < cnt; j++)
      if (between[i][j] <= sqdist)
        addedge(i, j);
  }
  memset(vis, false, sizeof (vis));
  vis[SOURCE] = true;
  q[0] = SOURCE;
  for (int qf = 0, qb = 1, e; qf < qb; qf++)
    for (e = last[q[qf]]; e > -1; e = next[e])
      if (!vis[to[e]])
        vis[q[qb++] = to[e]] = true;
  return !vis[SINK];
}

void solve(int test_num) {
  double high = 1e8;
  for (int i = 0; i < cnt; i++) {
    scanf("%d %d", x + i, y + i);
    high = min(high, hypot(x[i], y[i]));
    high = min(high, hypot(width - x[i], height - y[i]));
  }
  for (int i = 0; i < cnt; i++)
    for (int j = i + 1; j < cnt; j++)
      between[i][j] = sq(x[i] - x[j] + 0LL) + sq(y[i] - y[j] + 0LL);
  double ans = 0;
  for (double low = 0, mid; high - low > 1e-6; ) {
    mid = (low + high) / 2.0;
    if (poss(mid)) {
      ans = max(ans, mid);
      low = mid;
    }
    else high = mid;
  }
  printf("%.3lf\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d %d", &cnt, &width, &height) != EOF)
    if (cnt > -1)
      solve(1);
}
}

int main() {
  DINOSM::solve();
  return 0;
}

