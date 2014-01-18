/* Solved
 * 7760. Kids’ Wishes
 * File:   MKLAR10.cpp
 * Author: Andy Y.F. Huang
 * Created on May 12, 2013, 3:53 PM
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

namespace MKLAR10 {
int vals[222000];
pair<int, int> edge[111000];
int deg[111000];
int dsu[111000], size[111000];
int kids, wishes;

int findset(int x) {
  return dsu[x] < 0 ? x : dsu[x] = findset(dsu[x]);
}

void unite(int a, int b) {
  a = findset(a), b = findset(b);
  if (a == b) return;
  if (dsu[a] < dsu[b])
    size[dsu[b] = a] += size[b];
  else {
    if (dsu[a] == dsu[b]) dsu[b]--;
    size[dsu[a] = b] += size[a];
  }
}

void solve(int test_num) {
  for (int i = 0; i < wishes; i++) {
    scanf("%d %d", &edge[i].first, &edge[i].second);
    if (edge[i].first > edge[i].second)
      swap(edge[i].first, edge[i].second);
    vals[i << 1] = edge[i].first;
    vals[i << 1 | 1] = edge[i].second;
  }
  sort(vals, vals + wishes + wishes);
  sort(edge, edge + wishes);
  int len = unique(vals, vals + wishes + wishes) - vals;
  wishes = unique(edge, edge + wishes) - edge;
  for (int i = 0; i < len; i++) {
    deg[i] = 0;
    dsu[i] = -1;
    size[i] = 1;
  }
  bool ok = true;
  for (int i = 0; i < wishes; i++) {
    int a = lower_bound(vals, vals + len, edge[i].first) - vals;
    int b = lower_bound(vals, vals + len, edge[i].second) - vals;
    deg[a]++, deg[b]++;
    if (findset(a) == findset(b) && size[findset(a)] < kids)
      ok = false;
    unite(a, b);
  }
  for (int i = 0; i < len; i++)
    if (deg[i] > 2)
      ok = false;
  if (ok) puts("Y");
  else puts("N");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d", &kids, &wishes) != EOF)
    if (kids > 0)
      solve(1);
}
}

int main() {
  MKLAR10::solve();
  return 0;
}

