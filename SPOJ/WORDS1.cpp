/*
 * Solved
 * 41. Play on Words
 * File:   WORDS1.cpp
 * Author: Andy Y.F. Huang
 * Created on January 19, 2013, 11:59 AM
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
namespace WORDS1 {

template <size_t MAXSIZE> struct DisjointSet {
  int tree[MAXSIZE];

  void makeset(int size) {
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

DisjointSet < 27 > dsu;
char str[1111];
int indeg[27], outdeg[27];

void solve(int test_num) {
  memset(indeg, 0, sizeof (indeg));
  memset(outdeg, 0, sizeof (outdeg));
  dsu.makeset(27);
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%s", str);
    int st = str[0] - 'a', ed = str[strlen(str) - 1] - 'a';
    outdeg[st]++;
    indeg[ed]++;
    dsu.unite(st, ed);
  }
  for (int i = 0; i < 26; i++) {
    if (indeg[i] + outdeg[i] <= 0) continue;
    for (int j = i + 1; j < 26; j++) {
      if (indeg[j] + outdeg[j] > 0 && dsu.find(i) != dsu.find(j)) {
        puts("The door cannot be opened.");
        return;
      }
    }
  }
  bool minusone = false, plusone = false;
  for (int i = 0; i < 26; i++) {
    if (indeg[i] == outdeg[i]) continue;
    int diff = indeg[i] - outdeg[i];
    if (diff == -1) {
      if (minusone)  {
        puts("The door cannot be opened.");
        return;
      }
      minusone = true;
    }
    else if (diff == 1) {
      if (plusone) {
        puts("The door cannot be opened.");
        return;
      }
      plusone = true;
    }
    else {
      puts("The door cannot be opened.");
      return;
    }
  }
  if (!(minusone ^ plusone))
    puts("Ordering is possible.");
  else
    puts("The door cannot be opened.");
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
  WORDS1::solve();
  return 0;
}

