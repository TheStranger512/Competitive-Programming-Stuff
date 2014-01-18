/* Solved
 * 7637. Road Map
 * File:   RANJAN05.cpp
 * Author: Andy Y.F. Huang
 * Created on May 12, 2013, 4:33 PM
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

namespace RANJAN05 {
int last[55000], to[111000], next[111000];
int par[55000];

void addedge(int a, int b) {
  static int E = 0;
  to[E] = b;
  next[E] = last[a];
  last[a] = E++;
}

void dfs(int x) {
  for (int e = last[x]; e > -1; e = next[e]) {
    if (par[to[e]] == -1) {
      par[to[e]] = x;
      dfs(to[e]);
    }
  }
}

void solve(int test_num) {
  memset(last, -1, sizeof (last));
  memset(par, -1, sizeof (par));
  int size, root, nroot;
  scanf("%d %d %d", &size, &root, &nroot);
  for (int i = 1, p; i <= size; i++) {
    if (i == root) continue;
    scanf("%d", &p);
    addedge(i, p);
    addedge(p, i);
  }
  par[nroot] = nroot;
  dfs(nroot);
  for (int i = 1; i <= size; i++)
    if (i != nroot)
      printf("%d ", par[i]);
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
  RANJAN05::solve();
  return 0;
}

