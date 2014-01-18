/* Solved
 * 15267. FRIEND CIRCLE
 * File:   FRNDCIRC.cpp
 * Author: Andy Y.F. Huang
 * Created on July 23, 2013, 12:35 AM
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

namespace FRNDCIRC {
typedef long long llong;
int dsu[222000];
int size[222000];
char x[22], y[22];
llong a[111000], b[111000];
llong val[222000];

int findset(int x) {
  return dsu[x] < 0 ? x : dsu[x] = findset(dsu[x]);
}

void unite(int a, int b) {
  a = findset(a), b = findset(b);
  if (a == b) return;
  if (dsu[a] < dsu[b]) {
    dsu[b] = a;
    size[a] += size[b];
  }
  else {
    if (dsu[a] == dsu[b])
      dsu[b]--;
    dsu[a] = b;
    size[b] += size[a];
  }
}

llong hash(char* str) {
  llong res = 0;
  for (int i = 0; str[i] > 0; i++)
    res = res * 1000000007 + str[i];
  return res;
}

void solve(int test_num) {
  int E, V;
  scanf("%d", &E);
  for (int e = 0; e < E; e++) {
    scanf("%s %s", x, y);
    a[e] = hash(x);
    b[e] = hash(y);
    val[e + e] = a[e];
    val[e + e + 1] = b[e];
  }
  sort(val, val + E + E);
  V = unique(val, val + E + E) - val;
  for (int v = 0; v < V; v++) {
    dsu[v] = -1;
    size[v] = 1;
  }
  for (int e = 0, aa, bb; e < E; e++) {
    aa = lower_bound(val, val + V, a[e]) - val;
    bb = lower_bound(val, val + V, b[e]) - val;
    unite(aa, bb);
    printf("%d\n", size[findset(aa)]);
  }
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
  FRNDCIRC::solve();
  return 0;
}

