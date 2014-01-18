/* Solved
 * 12734. Seating Arrangement
 * File:   QN02.cpp
 * Author: Andy Y.F. Huang
 * Created on December 22, 2012, 6:40 PM
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
namespace QN02 {

struct DisjointSet {
  vector<int> tree;

  void makeset(int size) {
    tree.resize(size + 1, -1);
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

DisjointSet dsu;

void solve(int test_num) {
  int students, friends;
  scanf("%d %d", &students, &friends);
  dsu.makeset(students);
  for (int i = 0; i < friends; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    dsu.unite(a, b);
  }
  int quests;
  scanf("%d", &quests);
  for (int q = 0; q < quests; q++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (dsu.find(a) == dsu.find(b))
      puts("YES");
    else puts("NO");
  }
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
  QN02::solve();
  return 0;
}

