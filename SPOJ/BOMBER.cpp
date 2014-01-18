/* Solved
 * 6289. Bomberman
 * File:   BOMBER.cpp
 * Author: Andy Y.F. Huang
 * Created on February 14, 2013, 6:35 PM
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
namespace BOMBER {
int nimber[111][111];
bool mex[333];

void solve(int test_num) {
  int rows, cols;
  scanf("%d %d", &rows, &cols);
  if (nimber[rows][cols] == 0) puts("2");
  else puts("1");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  nimber[0][0] = 0;
  for (int r = 1; r <= 100; r++) {
    for (int c = r; c <= 100; c++) {
      memset(mex, false, sizeof (mex));
      for (int y = 1; y <= r; y++)
        for (int x = 1; x <= c; x++)
          mex[nimber[y - 1][x - 1] ^ nimber[r - y][x - 1] ^ nimber[y - 1][c - x] ^ nimber[r - y][c - x]] = true;
      nimber[r][c] = 0;
      while (mex[nimber[r][c]])
        nimber[r][c]++;
      nimber[c][r] = nimber[r][c];
    }
  }
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  BOMBER::solve();
  return 0;
}

