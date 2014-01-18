/* Solved
 * 6825. Field Plan
 * File:   FPLAN.cpp
 * Author: Andy Y.F. Huang
 * Created on February 26, 2013, 9:41 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace FPLAN {
#define MAX 111111
int last[MAX], to[MAX], next[MAX];
int label[MAX], lowlink[MAX], comp[MAX];
int indeg[MAX];
int nextnum;
stack<int> stck;

void scc(int at) {
  label[at] = lowlink[at] = nextnum++;
  stck.push(at);
  for (int id = last[at]; id != -1; id = next[id]) {
    if (label[to[id]] < 0)
      scc(to[id]);
    lowlink[at] = min(lowlink[at], lowlink[to[id]]);
  }
  if (label[at] == lowlink[at]) {
    comp[at] = at;
    lowlink[at] = MAX;
    for (; stck.top() != at; stck.pop()) {
      comp[stck.top()] = at;
      lowlink[stck.top()] = MAX;
    }
    stck.pop();
  }
}

void solve(int test_num) {
  memset(last, -1, sizeof (last));
  memset(label, -1, sizeof (label));
  memset(indeg, 0, sizeof (indeg));
  nextnum = 0;
  int vertices, edges;
  scanf("%d %d", &vertices, &edges);
  for (int e = 0; e < edges; e++) {
    int from;
    scanf("%d %d", &from, &to[e]);
    next[e] = last[from];
    last[from] = e;
  }
  for (int v = 0; v < vertices; v++)
    if (label[v] < 0)
      scc(v);
  //assert(stck.empty());
  int anscomp = -1, cnt = 0;
  for (int v = 0; v < vertices; v++)
    for (int id = last[v]; id != -1; id = next[id])
      if (comp[to[id]] != comp[v])
        indeg[comp[to[id]]]++;
  for (int v = 0; v < vertices; v++)
    if (v == comp[v] && indeg[v] == 0) {
      anscomp = v;
      cnt++;
    }
  if (cnt > 1) puts("Confused");
  else {
    for (int v = 0; v < vertices; v++)
      if (comp[v] == anscomp)
        printf("%d\n", v);
    putchar('\n');
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
  FPLAN::solve();
  return 0;
}

