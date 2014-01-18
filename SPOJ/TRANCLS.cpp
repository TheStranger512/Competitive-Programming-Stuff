/* Solved
 * 13683. Transitive Closure
 * File:   TRANCLS.cpp
 * Author: Andy Y.F. Huang
 * Created on February 12, 2013, 9:18 PM
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
namespace TRANCLS {
int dist[111][111];
int orig[111][111];

void solve(int test_num) {
  memset(orig, 0x3F, sizeof (orig));
  int size;
  scanf("%d", &size);
  for (int i = 0; i < size; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    orig[a][b] = 1;
  }
  memcpy(dist, orig, sizeof (dist));
  for (int k = 0; k < size; k++)
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  int ans = 0;
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      if (dist[i][j] < 1e9 && orig[i][j] != 1)
        ans++;
  printf("Case #%d: %d\n", test_num, ans);
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
  TRANCLS::solve();
  return 0;
}

