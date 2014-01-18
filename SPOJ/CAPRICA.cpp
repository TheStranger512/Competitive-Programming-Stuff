/* Solved
 * 10452. Caprica Cities
 * File:   CAPRICA.cpp
 * Author: Andy Y.F. Huang
 * Created on June 22, 2013, 1:03 AM
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

namespace CAPRICA {
int V, E, cntA, cntB;
int dist[1111];
int last[1111], to[22222], next[22222], cost[22222];
int A[1111], B[1111];

void solve(int test_num) {
  for (int i = 0; i < cntA; i++)
    scanf("%d", A + i);
  for (int i = 0; i < cntB; i++)
    scanf("%d", B + i);
  memset(last, -1, sizeof (last));
  for (int e = 0, a, b; e < E; e++) {
    scanf("%d %d %d", &a, &b, cost + e);
    cost[e + E] = cost[e];
    to[e] = b;
    next[e] = last[a];
    last[a] = e;
    to[e + E] = a;
    next[e + E] = last[b];
    last[b] = e + E;
  }
  memset(dist, 0x3F, sizeof (dist));
  queue<int> q;
  for (int i = 0; i < cntA; i++) {
    dist[A[i]] = 0;
    q.push(A[i]);
  }
  for (int at, e; !q.empty(); q.pop()) {
    at = q.front();
    for (e = last[at]; ~e; e = next[e])
      if (dist[at] + cost[e] < dist[to[e]]) {
        dist[to[e]] = dist[at] + cost[e];
        q.push(to[e]);
      }
  }
  int res = 1 << 30;
  for (int i = 0; i < cntB; i++)
    res = min(res, dist[B[i]]);
  printf("%d\n", res);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d %d %d", &V, &E, &cntA, &cntB) != EOF)
    if (V + E > 0)
      solve(1);
}
}

int main() {
  CAPRICA::solve();
  return 0;
}

