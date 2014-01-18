/*
 * Solved
 * 10645. The Rail Network Renovation
 * File:   MYQ7.cpp
 * Author: Andy Y.F. Huang
 * Created on February 10, 2013, 12:01 AM
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
namespace MYQ7 {

template <size_t MAXSIZE> struct DisjointSet {
  int tree[MAXSIZE];

  void makeset() {
    memset(tree, 0xFF, sizeof (tree));
  }

  void unite(int a, int b) {
    int root1 = find(a), root2 = find(b);
    if (root1 == root2) return;
    if (tree[root1] > tree[root2]) tree[root1] = root2;
    else {
      if (tree[root1] == tree[root2]) tree[root1]--;
      tree[root2] = root1;
    }
  }

  int find(int node) {
    return tree[node] < 0 ? node : (tree[node] = find(tree[node]));
  }
} ;

struct Edge {
  int from, to, cost;

  bool operator<(const Edge & e) const {
    return cost < e.cost;
  }
} ;

DisjointSet < 1111 > dsu;
Edge edges[1 << 20];

void solve(int test_num) {
  int cities, edgecnt;
  scanf("%d %d", &cities, &edgecnt);
  long long total = 0;
  for (int e = 0; e < edgecnt; e++) {
    int reb, dest;
    scanf("%d %d %d %d", &edges[e].from, &edges[e].to, &dest, &reb);
    total += dest;
    edges[e].cost = reb - dest;
  }
  sort(edges, edges + edgecnt);
  dsu.makeset();
  for (int e = 0; e < edgecnt; e++) {
    if (edges[e].cost <= 0) {
      total += edges[e].cost;
      dsu.unite(edges[e].from, edges[e].to);
      continue;
    }
    if (dsu.find(edges[e].from) == dsu.find(edges[e].to))
      continue;
    dsu.unite(edges[e].from, edges[e].to);
    total += edges[e].cost;
  }
  printf("%lld\n", total);
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
  MYQ7::solve();
  return 0;
}

