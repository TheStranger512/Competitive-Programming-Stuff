/* Solved
 * 14839. Boxdropper
 * File:   BOXD.cpp
 * Author: Andy Y.F. Huang
 * Created on May 11, 2013, 10:30 PM
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

namespace BOXD {
int x1[555], y1[555], x2[555], y2[555];
double g[555][555];

int diff(int a, int b, int c, int d) {
  return max(max(a, c) - min(b, d), 0);
}

double dist(int i, int j) {
  return hypot(diff(x1[i], x2[i], x1[j], x2[j]), diff(y1[i], y2[i], y1[j], y2[j]));
}

void solve(int test_num) {
  memset(g, 0, sizeof (g));
  int size = 0;
  while (true) {
    char type;
    if (scanf(" %c", &type) == EOF)
      break;
    if (type == 'B') {
      size++;
      scanf("%d %d %d %d", x1 + size, y1 + size, x2 + size, y2 + size);
      if (x1[size] > x2[size])
        swap(x1[size], x2[size]);
      if (y1[size] > y2[size])
        swap(y1[size], y2[size]);
      for (int i = 1; i <= size; i++)
        g[i][size] = g[size][i] = dist(i, size);
      for (int i = 1; i <= size; i++)
        for (int j = 1; j <= size; j++)
          g[size][i] = g[i][size] = min(g[size][i], g[size][j] + g[j][i]);
      for (int i = 1; i <= size; i++)
        for (int j = 1; j <= size; j++)
          g[i][j] = min(g[i][j], g[i][size] + g[size][j]);
      //plnarr(g, size + 1, size + 1);
      //pln();
    }
    else {
      int a, b;
      scanf("%d %d", &a, &b);
      printf("%.2lf\n", g[a][b]);
    }
  }
  //plnarr(g, size + 1, size + 1);
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
  BOXD::solve();
  return 0;
}

