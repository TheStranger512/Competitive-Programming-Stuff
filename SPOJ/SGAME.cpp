/* Solved
 * 12978. SHAPE GAME
 * File:   SGAME.cpp
 * Author: Andy Y.F. Huang
 * Created on December 24, 2012, 5:47 PM
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
namespace SGAME {
int deg[333], tree[333];

int find(int node) {
  return tree[node] < 0 ? node : (tree[node] = find(tree[node]));
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


void solve(int test_num) {
  memset(tree, 0xFF, sizeof (tree));
  memset(deg, 0, sizeof (deg));
  int start;
  scanf("%d", &start);
  while (true) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == -1) break;
    unite(a, b);
    deg[a]++, deg[b]++;
  }
  for (int i = 1; i <= 300; i++) {
    if (deg[i] > 0 && find(i) != find(start)) {
      puts("NO");
      return;
    }
    if (deg[i] & 1) {
      puts("NO");
      return;
    }
  }
  puts("YES");
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
  SGAME::solve();
  return 0;
}

