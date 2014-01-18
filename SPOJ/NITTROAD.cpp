/* Solved
 * 13868. Roads of NITT
 * File:   NITTROAD.cpp
 * Author: Andy Y.F. Huang
 * Created on April 3, 2013, 4:52 PM
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

namespace NITTROAD {

template <size_t MAXSIZE> struct DisjointSet {
  int tree[MAXSIZE], size[MAXSIZE];

  void makeset(int size_ = MAXSIZE) {
    memset(tree, -1, sizeof (int) * size_);
    fill(size, size + MAXSIZE, 1);
  }

  void unite(int a, int b) {
    int root1 = find(a), root2 = find(b);
    if (root1 == root2) return;
    if (tree[root1] > tree[root2]) size[tree[root1] = root2] += size[root1];
    else {
      if (tree[root1] == tree[root2]) tree[root1]--;
      size[tree[root2] = root1] += size[root2];
    }
  }

  int find(int node) {
    return tree[node] < 0 ? node : (tree[node] = find(tree[node]));
  }
} ;

int from[22222], to[22222], pos[22222];
char type[22222];
int ans[22222];
bool used[22222];
DisjointSet < 22222 > dsu;

void solve(int test_num) {
  memset(used, false, sizeof (used));
  int len, quests;
  scanf("%d", &len);
  for (int i = 1; i < len; i++)
    scanf("%d %d", from + i, to + i);
  scanf("%d", &quests);
  for (int q = 0; q < quests; q++) {
    scanf(" %c", type + q);
    if (type[q] == 'R') {
      scanf("%d", pos + q);
      used[pos[q]] = true;
    }
  }
  dsu.makeset();
  for (int i = 1; i < len; i++)
    if (!used[i])
      dsu.unite(from[i], to[i]);
  int total = 0;
  for (int i = 1; i <= len; i++)
    if (dsu.find(i) == i)
      total += dsu.size[i] * (len - dsu.size[i]);
  total >>= 1;
  for (int q = quests - 1; q > 0; q--) {
    if (type[q] == 'Q') ans[q] = total;
    else {
      int root1 = dsu.find(from[pos[q]]), root2 = dsu.find(to[pos[q]]);
      total -= dsu.size[root1] * dsu.size[root2];
      dsu.unite(root1, root2);
    }
  }
  for (int q = 0; q < quests; q++)
    if (type[q] == 'Q')
      printf("%d\n", ans[q]);
  putchar('\n');
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
  NITTROAD::solve();
  return 0;
}

