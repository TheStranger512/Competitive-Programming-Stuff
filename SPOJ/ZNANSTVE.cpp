/* Solved
 * 10623. ZNANSTVENIK
 * File:   ZNANSTVE.cpp
 * Author: Andy Y.F. Huang
 * Created on May 24, 2013, 12:57 AM
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

namespace ZNANSTVE {
typedef unsigned long long llong;
const int BASE = 1000000007;
llong hash[1111][1111], temp[1111];
llong base[1111];
char grid[1111][1111];

void solve(int test_num) {
  int rows, cols;
  scanf("%d %d", &rows, &cols);
  for (int r = 0; r < rows; r++)
    scanf("%s", grid[r]);
  base[0] = 1;
  for (int i = 1; i < 1111; i++)
    base[i] = base[i - 1] * BASE;
  memset(hash, 0, sizeof (hash));
  for (int r = rows - 1; r > 0; r--)
    for (int c = 0; c < cols; c++)
      hash[r][c] = hash[r + 1][c] + grid[r][c] * base[r];
  //plnarr(hash, rows, cols);
  for (int r = 1; r < rows; r++) {
    memcpy(temp, hash[r], sizeof (temp));
    sort(temp, temp + cols);
    bool ok = true;
    for (int c = 1; c < cols && ok; c++)
      if (temp[c] == temp[c - 1])
        ok = false;
    if (!ok) {
      printf("%d\n", r - 1);
      return;
    }
  }
  printf("%d\n", rows - 1);
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
  ZNANSTVE::solve();
  return 0;
}

