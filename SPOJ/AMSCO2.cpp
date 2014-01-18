/* Solved
 * 14435. Decipher the AMSCO cipher
 * File:   AMSCO2.cpp
 * Author: Andy Y.F. Huang
 * Created on May 1, 2013, 8:59 PM
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

namespace AMSCO2 {
char A[255][11], B[255][11];
bool haveA[255][11], haveB[255][11];
char order[11], str[255];
int perm[11];

void solve(int test_num) {
  memset(haveA, 0, sizeof (haveA));
  memset(haveB, 0, sizeof (haveB));
  int cols = strlen(order);
  int len = strlen(str), rows = 0;
  for (int i = 0; i < cols; i++)
    perm[order[i] - '1'] = i;
  for (int i = 0, c = 0; i < len; i++) {
    haveA[rows][c] = true;
    if ((rows + c) % 2 == 0 && i + 1 < len) {
      haveB[rows][c] = true;
      i++;
    }
    c++;
    if (c == cols) {
      rows++;
      c = 0;
    }
  }
  for (int c = 0, i = 0; c < cols; c++) {
    int col = perm[c];
    for (int r = 0; r <= rows; r++) {
      if (haveA[r][col]) A[r][col] = str[i++];
      if (haveB[r][col]) B[r][col] = str[i++];
    }
  }
//  for (int i = 0; i <= rows; i++, pln())
//    for (int j = 0; j < cols; j++, pf(' '))
//      pf(A[i][j]), pf(B[i][j]);
  for (int r = 0; r <= rows; r++)
    for (int c = 0; c < cols; c++) {
      if (haveA[r][c]) putchar(A[r][c]);
      if (haveB[r][c]) putchar(B[r][c]);
    }
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%s %s", order, str) != EOF)
    solve(1);
}
}

int main() {
  AMSCO2::solve();
  return 0;
}

