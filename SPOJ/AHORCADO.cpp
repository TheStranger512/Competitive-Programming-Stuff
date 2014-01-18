/* Solved
 * 9242. B Beware, the end of the world
 * File:   AHORCADO.cpp
 * Author: Andy Y.F. Huang
 * Created on March 29, 2013, 12:21 PM
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

namespace AHORCADO {
const int DX[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
const int DY[] = {1, 0, -1, 0, 1, -1, 1, -1, 0};
int rows, cols;
char prev[25][25], now[25][25];

void solve(int test_num) {
  for (int r = 1; r <= rows; r++)
    scanf("%s", prev[r] + 1);
  scanf(" N ");
  for (int r = 1; r <= rows; r++)
    scanf("%s", now[r] + 1);
  int prevcnt = 0, nowcnt = 0;
  bool ok = true;
  for (int r = 1; r <= rows; r++) {
    for (int c = 1; c <= cols; c++) {
      if (prev[r][c] != '*') continue;
      bool cok = false;
      for (int d = 0; d < 9; d++) {
        int nr = r + DY[d], nc = c + DX[d];
        if (now[nr][nc] == '*')
          cok = true;
      }
      prevcnt++;
      if (!cok) ok = false;
    }
  }
  for (int r = 1; r <= rows; r++)
    for (int c = 1; c <= cols; c++)
      if (now[r][c] == '*')
        nowcnt++;
  if (ok && nowcnt >= prevcnt) puts("VALID");
  else puts("NOT VALID");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d", &rows, &cols) != EOF)
    if (rows > 0)
      solve(1);

}
}

int main() {
  AHORCADO::solve();
  return 0;
}

