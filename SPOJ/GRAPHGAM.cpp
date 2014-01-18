/* Solved
 * 3108. Charlesbert and Merangelou
 * File:   GRAPHGAM.cpp
 * Author: Andy Y.F. Huang
 * Created on June 22, 2013, 12:52 PM
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

namespace GRAPHGAM {
int g[111][111];
int far[111];
char str[111];

void solve(int test_num) {
  int size, lim;
  scanf("%d %d", &size, &lim);
  for (int i = 0; i < size; i++) {
    scanf("%s", str);
    for (int j = 0; j < size; j++)
      if (str[j] == 'Y')
        g[i][j] = 1;
      else
        g[i][j] = 1 << 28;
    g[i][i] = 0;
  }
  for (int k = 0; k < size; k++)
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  for (int i = 0; i < size; i++)
    far[i] = *max_element(g[i], g[i] + size);
  if (*min_element(far, far + size) > lim)
    puts("INFINITE GAME");
  else {
    int res = 1 << 28;
    for (int i = 0; i < size; i++)
      if (far[i] <= lim)
        res = min(res, (g[0][i] + lim - 1) / lim * lim + far[i]);
    printf("%d\n", res);
  }
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
  GRAPHGAM::solve();
  return 0;
}

