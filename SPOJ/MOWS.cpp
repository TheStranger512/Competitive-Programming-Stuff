/* Solved
 * 4988. Madrids One Way Streets
 * File:   MOWS.cpp
 * Author: Andy Y.F. Huang
 * Created on March 29, 2013, 12:40 PM
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

namespace MOWS {
#define MAXV 102010
#define MAXE 1000100
int last[MAXV], to[MAXE], next[MAXE];
int label[MAXV], low[MAXV];
int temp[MAXV];
int best, bestcnt;
int hotels, places, edges;
stack<int> stck;

static int nextlabel() {
  static int X = 1;
  return X++;
}

void scc(int at) {
  label[at] = low[at] = nextlabel();
  stck.push(at);
  for (int e = last[at]; e > -1; e = next[e]) {
    if (label[to[e]] < 0)
      scc(to[e]);
    low[at] = min(low[at], low[to[e]]);
  }
  if (label[at] == low[at]) {
    int cnt = 0, size = 0;
    for (; stck.top() != at; stck.pop()) {
      low[stck.top()] = 1 << 25;
      temp[size++] = stck.top();
      if (stck.top() > hotels)
        cnt++;
    }
    stck.pop();
    low[at] = 1 << 25;
    temp[size++] = at;
    if (at > hotels)
      cnt++;
    if (cnt > bestcnt && size - cnt > 0) {
      bestcnt = cnt;
      best = 1 << 25;
      for (int i = 0; i < size; i++)
        if (temp[i] <= hotels)
          best = min(best, temp[i]);
    }
  }
}

void solve(int test_num) {
  scanf("%d %d %d", &hotels, &places, &edges);
  memset(last, -1, sizeof (last));
  memset(label, -1, sizeof (label));
  for (int e = 0, from; e < edges; e++) {
    scanf("%d %d", &from, to + e);
    next[e] = last[from];
    last[from] = e;
  }
  best = 1, bestcnt = 0;
  for (int i = 1; i <= hotels + places; i++)
    if (label[i] < 0)
      scc(i);
  printf("%d %d\n", best, bestcnt);
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
  MOWS::solve();
  return 0;
}

