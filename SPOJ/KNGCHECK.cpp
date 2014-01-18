/* Solved
 * 13651. Check
 * File:   KNGCHECK.cpp
 * Author: Andy Y.F. Huang
 * Created on February 14, 2013, 7:16 PM
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
namespace KNGCHECK {
const int kdx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int kdy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int hdx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int hdy[] = {2, -2, 1, -1, 2, -2, 1, -1};
typedef pair<int, int> Point;
int grid[11][11];

void solve(int test_num) {
  memset(grid, 0, sizeof (grid));
  vector<Point> kings, pawns, horses;
  for (int r = 1; r <= 8; r++) {
    for (int c = 1; c <= 8; c++) {
      char str[11];
      scanf("%s", str);
      if (str[0] == 'B' && str[1] == 'K')
        grid[r][c] = 1;
      else if (str[0] == 'W' && str[1] == 'K')
        kings.push_back(Point(r, c));
      else if (str[0] == 'W' && str[1] == 'P')
        pawns.push_back(Point(r, c));
      else if (str[0] == 'W' && str[1] == 'H')
        horses.push_back(Point(r, c));
    }
  }
  bool check = false;
  for (int i = 0; i < (int) kings.size(); i++)
    for (int d = 0; d < 8; d++)
      if (grid[kings[i].first + kdy[d]][kings[i].second + kdx[d]] == 1)
        check = true;
  for (int i = 0; i < (int) horses.size(); i++) {
    for (int d = 0; d < 8; d++) {
      int r = horses[i].first + hdy[d], c = horses[i].second + hdx[d];
      if (r >= 1 && r <= 8 && c > 0 && c < 9 && grid[r][c] == 1)
        check = true;
    }
  }
  for (int i = 0; i < (int) pawns.size(); i++) {
    int r = pawns[i].first, c = pawns[i].second;
    if (grid[r - 1][c - 1] == 1 || grid[r - 1][c + 1] == 1)
      check = true;
  }
  printf("Case #%d: %s\n", test_num, check ? "Check" : "Not Check");
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
  KNGCHECK::solve();
  return 0;
}

