/* Solved
 * 6322. The hunt for Gollum
 * File:   ARDA1.cpp
 * Author: Andy Y.F. Huang
 * Created on August 27, 2012, 9:58 PM
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
namespace ARDA1 {
char gollum[310][310], grid[2010][2010];

inline char nextchar() {
  char c = 0;
  while (c <= ' ')
    c = getchar_unlocked();
  return c;
}

void solve(int test_num) {
  int rows1, cols1, rows2, cols2;
  scanf("%d %d", &rows1, &cols1);
  for (int y = 0; y < rows1; y++)
    for (int x = 0; x < cols1; x++)
      gollum[x][y] = nextchar();
  scanf("%d %d", &rows2, &cols2);
  for (int y = 0; y < rows2; y++)
    for (int x = 0; x < cols2; x++)
      grid[x][y] = nextchar();
  int limx = cols2 - cols1 + 1;
  int limy = rows2 - rows1 + 1;
  bool match = false;
  for (int y = 0; y < limy; y++) {
    for (int x = 0; x < limx; x++) {
      bool good = true;
      for (int i = 0; i < rows1 && good; i++) {
        for (int j = 0; j < cols1; j++) {
          if (grid[x + j][y + i] != gollum[j][i]) {
            good = false;
            break;
          }
        }
      }
      if (good) {
        printf("(%d,%d)\n", y + 1, x + 1);
        match = true;
      }
    }
  }
  if (!match)
    puts("NO MATCH FOUND...");
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
  ARDA1::solve();
  return 0;
}

