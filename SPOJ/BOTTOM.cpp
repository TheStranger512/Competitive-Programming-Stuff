/*
 * Solved
 * 1799. The Bottom of a Graph
 * File:   BOTTOM.cpp
 * Author: Andy Y.F. Huang
 * Created on February 7, 2013, 10:22 PM
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
namespace BOTTOM {
vector<int> graph[5111];
int vertices, edges;
int label[5111], lowlink[5111];
int nextnum;
stack<int> stck;
vector<int> ans, temp;
bool sink[5555];

void scc(int at) {
  label[at] = lowlink[at] = nextnum++;
  stck.push(at);
  for (size_t i = 0; i < graph[at].size(); i++) {
    if (label[graph[at][i]] == -1)
      scc(graph[at][i]);
    sink[at] &= sink[graph[at][i]] && lowlink[graph[at][i]] <= vertices;
    lowlink[at] = min(lowlink[at], lowlink[graph[at][i]]);
  }
  if (label[at] == lowlink[at]) {
    while (stck.top() != at) {
      if (sink[at])
        ans.push_back(stck.top());
      lowlink[stck.top()] = 1e8;
      stck.pop();
    }
    if (sink[at])
      ans.push_back(stck.top());
    lowlink[stck.top()] = 1e8;
    stck.pop();
  }
}

void solve(int test_num) {
  for (int v = 1; v <= vertices; v++)
    if (graph[v].size() > 0)
      graph[v].clear();
  ans.clear();
  for (int e = 0; e < edges; e++) {
    int from, to;
    scanf("%d %d", &from, &to);
    graph[from].push_back(to);
  }
  nextnum = 1;
  memset(sink, true, sizeof (sink));
  memset(label, -1, sizeof (label));
  memset(lowlink, -1, sizeof (lowlink));
  for (int v = 1; v <= vertices; v++)
    if (label[v] == -1)
      scc(v);
  sort(ans.begin(), ans.end());
  printf("%d", ans.front());
  for (size_t i = 1; i < ans.size(); i++)
    printf(" %d", ans[i]);
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  //freopen("C:/Users/Windows/Documents/Compsci/ACM-ICPC/2003 - University of Ulm Local/bottom.in", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (true) {
    scanf("%d %d", &vertices, &edges);
    if (vertices == 0) break;
    solve(1);
  }
}
}

int main() {
  BOTTOM::solve();
  return 0;
}

