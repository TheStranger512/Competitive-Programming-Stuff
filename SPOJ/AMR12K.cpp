/* Solved
 * 13049. The Loyalty of the Orcs
 * File:   AMR12K.cpp
 * Author: Andy Y.F. Huang
 * Created on April 28, 2013, 10:36 PM
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

namespace AMR12K {
int last[111000], to[222000], next[222000];
bool isdead[111000];
int ecnt;
double ans;

void addedge(int a, int b) {
  to[ecnt] = b;
  next[ecnt] = last[a];
  last[a] = ecnt++;
}

void dfs(int at, int par, int dead) {
  ans += 1.0 * dead / (dead + 1);
  for (int e = last[at]; e > -1; e = next[e])
    if (to[e] != par)
      dfs(to[e], at, dead + isdead[at]);

}

void solve(int test_num) {
  memset(last, -1, sizeof (last));
  memset(isdead, false, sizeof (isdead));
  ecnt = ans = 0;
  int size;
  scanf("%d", &size);
  for (int i = 1, a, b; i < size; i++) {
    scanf("%d %d", &a, &b);
    addedge(a, b);
    addedge(b, a);
  }
  int deadcnt;
  scanf("%d", &deadcnt);
  for (int i = 0, a; i < deadcnt; i++) {
    scanf("%d", &a);
    isdead[a] = true;
  }
  dfs(1, -1, 0);
  printf("%.7lf\n", ans);
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
  AMR12K::solve();
  return 0;
}

