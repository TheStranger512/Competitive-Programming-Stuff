/* Solved
 * 10380. prayatna PR - dsu
 * File:   CAM5.cpp
 * Author: Andy Huang
 * Created on June 15, 2012, 11:09 PM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#define pln(x) println(x)
#define pf(x) print(x)
#define plnarr(i, j) println(i, j)
#endif

struct DisjointSet {
private:
  int* tree;
  int size;
public:

  DisjointSet(const int size) : size(size) {
    tree = new int[size];
    memset(tree, 0xFF, sizeof (tree) * size);
  }

  void unite(const int& root1, const int& root2) {
    if (root1 == root2)
      return;
    if (tree[root1] > tree[root2])
      tree[root1] = root2;
    else {
      if (tree[root1] == tree[root2])
        tree[root1]--;
      tree[root2] = root1;
    }
  }

  int find(const int& node) {
    if (tree[node] < 0)
      return node;
    tree[node] = find(tree[node]);
    return tree[node];
  }

} ;

using namespace std;

#define max_vertices 100010

bool cnt[max_vertices];

void solve() {
  memset(cnt, false, sizeof (cnt));
  int vertices, edges;
  scanf("%d %d", &vertices, &edges);
  if (vertices == 0) {
    puts("0");
    return;
  }
  if (edges == 0) {
    printf("%d\n", vertices);
    return;
  }
  DisjointSet dsu(vertices);
  int ans = 0;
  while (edges--) {
    int a, b;
    scanf("%d %d", &a, &b);
    dsu.unite(dsu.find(a), dsu.find(b));
  }
  
  for (int i = 0; i < vertices; i++) {
    int root = dsu.find(i);
    if (!cnt[root]) {
      cnt[root] = true;
      ans++;
    }
  }
  printf("%d\n", ans);
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d\r\n", &tests);
  while (tests--)
    solve();
  return 0;
}

