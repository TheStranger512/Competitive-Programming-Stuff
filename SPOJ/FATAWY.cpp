/* Solved
 * 12714. Fatawy
 * File:   FATAWY.cpp
 * Author: Andy Y.F. Huang
 * Created on March 25, 2013, 7:57 PM
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

namespace FATAWY {

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


int len[555];
char str[555][12];

int getlcs(const char* a, const char* b, int lena, int lenb) {
  static int dp[13][13];
  memset(dp, 0, sizeof (dp));
  for (int i = 1; i <= lena; i++)
    for (int j = 1; j <= lenb; j++)
      if (a[i] == b[j])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
  return dp[lena][lenb];
}

void solve(int test_num) {
  int size, limit;
  scanf("%d %d", &size, &limit);
  for (int i = 0; i < size; i++) {
    scanf("%s", str[i] + 1);
    len[i] = strlen(str[i] + 1);
  }
  DisjointSet < 555 > dsu;
  dsu.makeset();
  for (int i = 0; i < size; i++)
    for (int j = i + 1; j < size; j++)
      if (100 * getlcs(str[i], str[j], len[i], len[j]) >= max(len[i], len[j]) * limit)
        dsu.unite(i, j);
  int res = 0;
  for (int i = 0; i < size; i++)
    if (dsu.find(i) == i)
      res++;
  printf("Case #%d:\n%d\n", test_num, res);
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
  FATAWY::solve();
  return 0;
}

