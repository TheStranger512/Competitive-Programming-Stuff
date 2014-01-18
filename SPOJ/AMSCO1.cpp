/* Solved
 * 13941. The AMSCO cipher
 * File:   AMSCO1.cpp
 * Author: Andy Y.F. Huang
 * Created on May 1, 2013, 8:38 PM
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

namespace AMSCO1 {
char A[255][11];
char B[255][11];
char order[11], str[255];
int perm[11];

void solve(int test_num) {
  memset(A, 0, sizeof (A));
  memset(B, 0, sizeof (B));
  int cols = strlen(order), rows = 0;
  //pln(str);
  for (int i = 0, c = 0, two = 1; str[i] > 0; i++) {
    A[rows][c] = str[i];
    if (two && str[i + 1] > 0)
      B[rows][c] = str[++i];
    c++;
    two ^= 1;
    if (c == cols) {
      rows++;
      c = 0;
      two = B[rows - 1][0] ? 0 : 1;
    }
  }
//  for (int i = 0; i <= rows; i++, pln())
//    for (int j = 0; j < cols; j++, pf(' '))
//      pf(A[i][j]), pf(B[i][j]);
  for (int i = 0; i < cols; i++)
    perm[order[i] - '1'] = i;
  for (int i = 0; i < cols; i++) {
    int c = perm[i];
    for (int r = 0; r <= rows; r++) {
      if (A[r][c]) putchar(A[r][c]);
      if (B[r][c]) putchar(B[r][c]);
    }
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
  AMSCO1::solve();
  return 0;
}

