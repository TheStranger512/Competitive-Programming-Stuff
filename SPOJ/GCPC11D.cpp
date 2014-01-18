/* Solved
 * 9120. Magic Star - backtracking
 * File:   GCPC11D.cpp
 * Author: Andy Y.F. Huang
 * Created on September 2, 2012, 9:26 PM
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
namespace GCPC11D {
/*
....F....
.A.I.D.L.
..H...E..
.C.J.B.K.
....G....
 */
const int px[12] = {5, 2, 4, 6, 8, 3, 7, 2, 4, 6, 8, 5};
const int py[12] = {1, 2, 2, 2, 2, 3, 3, 4, 4, 4, 4, 5};
int lines[6][4] = {
  {1, 2, 3, 4},
  {0, 2, 5, 7},
  {0, 3, 6, 10},
  {7, 8, 9, 10},
  {4, 6, 9, 11},
  {1, 5, 8, 11}
};
char grid[15][15];
bool used[15] = {false};
bool letused[15] = {false};

bool rec(int pos) {
  if (pos == 12) {
    for (int y = 1; y <= 5; putchar('\n'), y++)
      for (int x = 1; x <= 9; x++)
        putchar(grid[x][y]);
    putchar('\n');
    return true;
  }
  if (used[pos])
    return rec(pos + 1);
  for (int i = 0; i < 12; i++) {
    if (letused[i])
      continue;
    grid[px[pos]][py[pos]] = char(i + 'A');
    letused[i] = true;
    //pln(grid[px[pos]][py[pos]]);
    bool good = true;
    for (int j = 0; j < 6; j++) {
      bool empty = false;
      int sum = 0;
      for (int k = 0; k < 4; k++) {
        char c = grid[px[lines[j][k]]][py[lines[j][k]]];
        if (c == 'x')
          empty = true;
        if (c != '.' && c != 'x')
          sum += c - 'A' + 1;
      }
      if (empty && sum >= 26) {
        good = false;
        break;
      }
      if (!empty && sum != 26) {
        good = false;
        break;
      }
    }
    if (good && rec(pos + 1))
      return true;
    letused[i] = false;
  }
  grid[px[pos]][py[pos]] = 'x';
  return false;
}

void solve(int test_num) {
  memset(grid, '.', sizeof (grid));
  for (int y = 1; y <= 5; y++)
    for (int x = 1; x <= 9; x++)
      scanf("%c\r\n", &grid[x][y]);
  for (int i = 0; i < 12; i++)
    if (grid[px[i]][py[i]] != 'x')
      used[i] = true, letused[grid[px[i]][py[i]] - 'A'] = true;
  for (int i = 0; i < 12; i++) {
    if (grid[px[i]][py[i]] == 'x') {
      rec(i);
      break;
    }
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  GCPC11D::solve();
  return 0;
}

