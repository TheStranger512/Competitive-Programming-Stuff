/* Solved
 * 8980. Cost
 * File:   KOICOST.cpp
 * Author: Andy Y.F. Huang
 * Created on May 23, 2013, 12:28 AM
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

namespace KOICOST {

struct Edge {
  int a, b, cost;

  bool operator<(const Edge & e) const {
    return cost > e.cost;
  }
} ;

const int MOD = int(1e9);
typedef long long llong;
Edge edges[111000];
int dsu[111000], size[111000];

int findset(int a) {
  return dsu[a] < 0 ? a : dsu[a] = findset(dsu[a]);
}

void unite(int a, int b) {
  if (dsu[a] < dsu[b])
    size[dsu[b] = a] += size[b];
  else {
    if (dsu[a] == dsu[b]) dsu[b]--;
    size[dsu[a] = b] += size[a];
  }
}

llong comb2(int x) {
  return (x * (x - 1LL) / 2) % MOD;
}

void solve(int test_num) {
  memset(dsu, -1, sizeof (dsu));
  int len, links;
  scanf("%d %d", &len, &links);
  for (int e = 0; e < links; e++)
    scanf("%d %d %d", &edges[e].a, &edges[e].b, &edges[e].cost);
  sort(edges, edges + links);
  for (int i = 1; i <= len; i++)
    size[i] = 1;
  llong res = 0, total = 0;
  for (int e = 0, a, b; e < links; e++) {
    a = findset(edges[e].a);
    b = findset(edges[e].b);
    if (a != b) {
      total -= comb2(size[a]);
      total -= comb2(size[b]);
      unite(a, b);
      total += comb2(size[a = findset(a)]);
    }
    res += llong(total) * edges[e].cost % MOD;
    if (res >= MOD)
      res -= MOD;
  }
  printf("%lld\n", res);
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
  KOICOST::solve();
  return 0;
}

