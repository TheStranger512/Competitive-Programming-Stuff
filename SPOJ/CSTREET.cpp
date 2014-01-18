/* Solved
 * 368. Cobbled streets
 * File:   CSTREET.cpp
 * Author: Andy Y.F. Huang
 * Created on August 8, 2012, 4:21 PM
 */

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace CSTREET {

struct Edge {
  int from, to, len;

  bool operator<(const Edge e) const {
    return len < e.len;
  }
} ;

const int k_max_size = 1010;
int tree[k_max_size];

void unite(int root1, int root2) {
  if (tree[root1] > tree[root2])
    tree[root1] = root2;
  else {
    if (tree[root1] == tree[root2])
      tree[root1]--;
    tree[root2] = root1;
  }
}

int find(int node) {
  return tree[node] < 0 ? node : (tree[node] = find(tree[node]));
}

Edge edges[300010];

void solve(int test_num) {
  memset(tree, 0xFF, sizeof (tree));
  int price, towns, roads, mst = 0;
  scanf("%d %d %d", &price, &towns, &roads);
  for (int i = 0; i < roads; i++)
    scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].len);
  sort(edges, edges + roads);
  for (int i = 0; i < roads; i++) {
    int a = find(edges[i].from);
    int b = find(edges[i].to);
    if (a == b)
      continue;
    mst += edges[i].len;
    unite(a, b);
  }
  printf("%d\n", mst * price);
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
  CSTREET::solve();
  return 0;
}

