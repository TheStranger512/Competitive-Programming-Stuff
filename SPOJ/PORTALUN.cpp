/*
 * Solved
 * 10588. Portal
 * File:   PORTALUN.cpp
 * Author: Andy Y.F. Huang
 * Created on March 29, 2013, 1:09 PM
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

namespace PORTALUN {
int vertices, edges;
int last[1111], to[555555], next[555555];
int nimber[1111], indeg[1111], order[1111], q[1111];
bool mex[1111];

void solve(int test_num) {
  memset(indeg, 0, sizeof (indeg));
  memset(last, -1, sizeof (last));
  for (int e = 0, a, b; e < edges; e++) {
    scanf("%d %d", &a, &b);
    if (b > a) swap(a, b);
    to[e] = b;
    next[e] = last[a];
    last[a] = e;
    indeg[b]++;
  }
  int qf = 0, qb = 0, len = 0;
  for (int v = 0; v < vertices; v++)
    if (indeg[v] == 0)
      q[qb++] = v;
  for (int e; qf < qb; qf++)
    for (order[len++] = q[qf], e = last[q[qf]]; e > -1; e = next[e])
      if (--indeg[to[e]] == 0)
        q[qb++] = to[e];
  reverse(order, order + vertices);
  for (int i = 0; i < vertices; i++) {
    memset(mex, false, sizeof (mex));
    for (int e = last[i]; e > -1; e = next[e])
      mex[nimber[to[e]]] = true;
    nimber[i] = 0;
    while (mex[nimber[i]])
      nimber[i]++;
  }
  int stonecnt, xorsum = 0;
  scanf("%d", &stonecnt);
  for (int q = 0, at; q < stonecnt; q++) {
    scanf("%d", &at);
    xorsum ^= nimber[at];
  }
  if (xorsum == 0) puts("I lose");
  else puts("I win");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d", &vertices, &edges) != EOF)
    if (vertices > 0)
      solve(1);
}
}

int main() {
  PORTALUN::solve();
  return 0;
}

