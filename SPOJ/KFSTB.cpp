/* Solved
 * 12183. Help the Commander in Chief
 * File:   KFSTB.cpp
 * Author: Andy Y.F. Huang
 * Created on October 23, 2012, 12:24 AM
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace KFSTB {
const int mod = 1000000007;
int last[11111], to[11111], next[11111], order[11111], deg[11111];
int q[11111], dp[11111];

void solve(int test_num) {
  memset(last, 0xFF, sizeof (last));
  memset(deg, 0, sizeof (deg));
  memset(dp, 0, sizeof (dp));
  int vertices, edges, src, dest;
  scanf("%d %d %d %d", &vertices, &edges, &src, &dest);
  for (int e = 0; e < edges; e++) {
    int start;
    scanf("%d %d", &start, &to[e]);
    deg[to[e]]++;
    next[e] = last[start];
    last[start] = e;
  }
  int qf = 0, qb = 0, toplen = 0;
  q[qb++] = src;
  while (qf < qb) {
    int cur = q[qf++];
    order[toplen++] = cur;
    for (int id = last[cur]; id != - 1; id = next[id])
      if (--deg[to[id]] == 0)
        q[qb++] = to[id];
  }
  dp[src] = 1;
  for (int i = 0; i < toplen; i++) {
    for (int id = last[order[i]]; id != -1; id = next[id]) {
      dp[to[id]] += dp[order[i]];
      if (dp[to[id]] >= mod)
        dp[to[id]] -= mod;
    }
  }
  printf("%d\n", dp[dest]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  KFSTB::solve();
  return 0;
}

