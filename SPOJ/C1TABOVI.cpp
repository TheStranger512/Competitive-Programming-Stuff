/* Solved
 * 7882. Tabovi
 * File:   C1TABOVI.cpp
 * Author: Andy Y.F. Huang
 * Created on April 21, 2013, 1:04 AM
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

namespace C1TABOVI {
int have[1111], need[1111];
int seq[1111];

int signum(int x) {
  return (x > 0) - (x < 0);
}

int go(int l, int r) {
  if (l > r) return 0;
  int best = l;
  for (int i = l; i <= r; i++)
    if (abs(seq[i]) < abs(seq[best]))
      best = i;
  int diff = -seq[best];
  for (int i = l; i <= r; i++)
    seq[i] += diff;
  return abs(diff) + go(l, best - 1) + go(best + 1, r);
}

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d", have + i);
  for (int i = 0; i < len; i++)
    scanf("%d", need + i);
  for (int i = 0; i < len; i++)
    seq[i] = have[i] - need[i];
  int res = 0;
  for (int i = 0, j = i; i < len; ) {
    j = i;
    while (j < len && signum(seq[i]) == signum(seq[j]))
      j++;
    if (signum(seq[i]) != 0)
      res += go(i, j - 1);
    i = j;
  }
  printf("%d\n", res);
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
  C1TABOVI::solve();
  return 0;
}

