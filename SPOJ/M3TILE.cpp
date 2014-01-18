/* Solved
 * 3883. LATGACH3
 * http://www.algorithmist.com/index.php/UVa_10918
 * File:   M3TILE.cpp
 * Author: Andy Y.F. Huang
 * Created on September 22, 2012, 11:48 PM
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
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace M3TILE {
int f[35], g[35];

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  f[0] = 1, f[1] = 0;
  g[0] = 0, g[1] = 1;
  for (int i = 2; i <= 30; i++) {
    f[i] = f[i - 2] + 2 * g[i - 1];
    g[i] = f[i - 1] + g[i - 2];
  }
  while (true) {
    int n;
    scanf("%d", &n);
    if (n == -1)
      break;
    printf("%d\n", f[n]);
  }
}
}

int main() {
  M3TILE::solve();
  return 0;
}

