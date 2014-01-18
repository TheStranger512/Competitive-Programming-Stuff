/*
 * Solved
 * 4483. Roads Repair
 * File:   MROADS.cpp
 * Author: Andy Y.F. Huang
 * Created on March 11, 2013, 4:32 PM
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

namespace MROADS {
#define MAX 111000
#define INF (1 << 28)
int maxdist[MAX], par[MAX];
int size, money;
int last[MAX], to[2 * MAX], next[2 * MAX], lowcost[2 * MAX], cost[2 * MAX];

void addedge(int a, int b, int c, int d) {
  static int e = 0;
  to[e] = b;
  cost[e] = c;
  lowcost[e] = d;
  next[e] = last[a];
  last[a] = e++;
}

void dfs1(int at, int dist) {
  maxdist[at] = dist;
  for (int id = last[at]; id != -1; id = next[id]) {
    if (to[id] != par[at]) {
      par[to[id]] = at;
      dfs1(to[id], dist + cost[id]);
      maxdist[at] = max(maxdist[at], maxdist[to[id]]);
    }
  }
}

bool poss(int limit) {
  static int fixed[MAX];
  queue<int> q;
  fixed[1] = 0;
  q.push(1);
  int cash = money;
  for (; !q.empty(); q.pop()) {
    int at = q.front();
    bool leaf = true;
    for (int id = last[at]; id != -1; id = next[id]) {
      if (to[id] == par[at]) continue;
      leaf = false;
      fixed[to[id]] = fixed[at];
      if (maxdist[to[id]] - fixed[at] > limit) {
        int repair = min(maxdist[to[id]] - fixed[at] - limit, cost[id] - lowcost[id]);
        cash -= repair;
        if (cash < 0) return false;
        fixed[to[id]] += repair;
        q.push(to[id]);
      }
    }
    if (leaf && maxdist[at] - fixed[at] > limit)
      return false;
  }
  return true;
}

void solve(int test_num) {
  memset(last, -1, sizeof (last));
  scanf("%d %d", &size, &money);
  for (int i = 1, a, b, c, d; i < size; i++) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    addedge(a, b, c, d);
    addedge(b, a, c, d);
  }
  par[1] = -1;
  dfs1(1, 0);
  int best = INF;
  poss(0);
  for (int low = 0, high = INF, mid; low <= high; ) {
    mid = (low + high) >> 1;
    if (poss(mid)) {
      best = min(best, mid);
      high = mid - 1;
    }
    else low = mid + 1;
  }
  printf("%d\n", best);
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
  MROADS::solve();
  return 0;
}

