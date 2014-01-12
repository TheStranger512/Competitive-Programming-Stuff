/*
 * Solved
 * 6818. Capital City
 * File:   CAPCITY.cpp
 * Author: Andy Y.F. Huang
 * Created on February 26, 2013, 4:58 PM
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
namespace CAPCITY {
#define MAX 222222
int last[MAX], to[MAX], next[MAX];
stack<int> stck;
int comp[MAX], label[MAX], lowlink[MAX];
int deg[MAX];
int nextnum, lastcomp;

void scc(int at) {
  label[at] = lowlink[at] = nextnum++;
  stck.push(at);
  for (int id = last[at]; id != -1; id = next[id]) {
    if (label[to[id]] == -1)
      scc(to[id]);
    lowlink[at] = min(lowlink[at], lowlink[to[id]]);
  }
  if (label[at] == lowlink[at]) {
    comp[at] = at;
    lowlink[at] = MAX;
    lastcomp = at;
    for (; stck.top() != at; stck.pop()) {
      comp[stck.top()] = at;
      lowlink[stck.top()] = MAX;
    }
    stck.pop();
  }
}

void solve(int test_num) {
  int vertices, edges;
  scanf("%d %d", &vertices, &edges);
  memset(last, -1, sizeof (last));
  memset(label, -1, sizeof (label));
  for (int e = 0; e < edges; e++) {
    int a, b;
    scanf("%d %d", &b, &a);
    to[e] = b;
    next[e] = last[a];
    last[a] = e;
  }
  nextnum = 0;
  for (int v = 1; v <= vertices; v++)
    if (label[v] == -1)
      scc(v);
  vector<int> ans;
  for (int v = 1; v <= vertices; v++)
    if (comp[v] == lastcomp)
      ans.push_back(v);
  printf("%d\n", ans.size());
  for (int i = 0; i < (int) ans.size(); i++)
    printf("%d ", ans[i]);
  putchar('\n');
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
  CAPCITY::solve();
  return 0;
}

