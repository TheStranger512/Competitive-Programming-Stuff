/* Solved
 * 14887. Good Travels
 * File:   GOODA.cpp
 * Author: Andy Y.F. Huang
 * Created on May 11, 2013, 8:06 PM
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

namespace GOODA {

struct State {
  int at, e;
  bool went;

  State(int a, int b, bool c) : at(a), e(b), went(c) { }

} ;
#define lim 1000010
#define inf 1 << 25
long long dp[lim], fun[lim];
int last[lim], to[lim], next[lim], head[lim];
int label[lim], lowlink[lim], stck[lim], comp[lim];
int stop, revtop[lim], revtoplen, nextnum;
stack<State> rec;

void scc(int src) {
  rec.push(State(src, last[src], false));
  while (!rec.empty()) {
    int cur = rec.top().at, &e = rec.top().e;
    if (e == last[cur] && !rec.top().went) {
      label[cur] = lowlink[cur] = nextnum++;
      stck[stop++] = cur;
    }
    if (e > -1)  {
      if (!rec.top().went) {
        rec.top().went = true;
        if (label[to[e]] == -1) {
          rec.push(State(to[e], last[to[e]], false));
          continue;
        }
      }
      lowlink[cur] = min(lowlink[cur], lowlink[to[e]]);
      e = next[e];
      rec.top().went = false;
      continue;
    }
    if (label[cur] == lowlink[cur]) {
      revtop[revtoplen++] = cur;
      lowlink[cur] = inf;
      comp[cur] = cur;
      while (stck[stop - 1] != cur) {
        int v = stck[--stop];
        comp[v] = cur;
        lowlink[v] = inf;
      }
      stop--;
    }
    rec.pop();
  }
}

void solve(int test_num) {
  memset(label, 0xFF, sizeof (label));
  memset(last, 0xFF, sizeof (last));
  memset(dp, 0, sizeof (dp));
  int cities, edges, src, dest;
  scanf("%d %d %d %d", &cities, &edges, &src, &dest);
  for (int i = 1; i <= cities; i++)
    scanf("%lld", &fun[i]);
  for (int e = 0; e < edges; e++) {
    int start, end;
    scanf("%d %d", &start, &end);
    if (last[start] == -1)
      head[start] = e;
    to[e] = end;
    next[e] = last[start];
    last[start] = e;
  }
  nextnum = stop = revtoplen = 0;
  scc(src);
  //plnarr(revtop, revtop + revtoplen);
  for (int c = 1; c <= cities; c++) {
    //fun[c] = 0;
    //assert(next[head[comp[c]]] == -1);
    if (c != comp[c]) {
      fun[comp[c]] += fun[c];
      next[head[comp[c]]] = last[c];
      head[comp[c]] = head[c];
    }
  }
  for (int i = revtoplen - 1; i >= 0; i--) {
    int cur = revtop[i];
    dp[cur] += fun[cur];
    for (int id = last[cur]; id != -1; id = next[id]) {
      to[id] = comp[to[id]];
      dp[to[id]] = max(dp[to[id]], dp[cur]);
    }
  }
  //plnarr(fun + 1, fun + 1 + cities);
  //plnarr(dp + 1, dp + 1 + cities);
  printf("%lld\n", dp[comp[dest]]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  GOODA::solve();
  return 0;
}

