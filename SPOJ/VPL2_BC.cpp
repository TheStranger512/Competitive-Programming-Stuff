/* Solved
 * 15310. Peter Quest
 * File:   VPL2_BC.cpp
 * Author: Andy Y.F. Huang
 * Created on July 21, 2013, 11:17 PM
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

namespace VPL2_BC {
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int mines[111000];

void solve(int test_num) {
  int R, C, K;
  scanf("%d %d %d", &R, &C, &K);
  for (int i = 0, r, c; i < K; i++) {
    scanf("%d %d", &r, &c);
    ++r, ++c;
    mines[i] = r << 13 | c;
  }
  sort(mines, mines + K);
  printf("Scenario #%d:\n", test_num);
  for (int r = 1; r <= R; r++, putchar('\n')) {
    for (int c = 1, res; c <= C; c++) {
      if (binary_search(mines, mines + K, r << 13 | c))
        putchar('*');
      else {
        res = 0;
        for (int d = 0; d < 8; d++)
          if (binary_search(mines, mines + K, ((r + dy[d]) << 13) + c + dx[d]))
            res++;
        if (res == 0) putchar('-');
        else putchar('0' + res);
      }
    }
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
  VPL2_BC::solve();
  return 0;
}

