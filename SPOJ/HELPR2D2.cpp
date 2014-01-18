/*
 * Solved
 * 132. Help R2-D2!
 * File:   HELPR2D2.cpp
 * Author: Andy Y.F. Huang
 * Created on March 6, 2013, 10:31 PM
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
namespace HELPR2D2 {
#define LIM (1 << 17)
int vol[1 << 18];
char str[55];

void update(int pos, int val) {
  vol[pos + LIM] -= val;
  for (int i = (pos + LIM) >> 1; i > 0; i >>= 1)
    vol[i] = max(vol[i << 1], vol[(i << 1) + 1]);
}

int query(int val) {
  int pos = 1;
  while (pos < LIM) {
    if (vol[pos << 1] >= val)
      pos <<= 1;
    else pos = (pos << 1) + 1;
  }
  return pos - LIM;
}

void solve(int test_num) {
  int cap, len;
  scanf("%d %d", &cap, &len);
  for (int i = 0; i < 2 * LIM; i++)
    vol[i] = cap;
  for (int q = 0, run, val; q < len; ) {
    scanf("%s", str);
    if (str[0] == 'b') {
      scanf("%d %d", &run, &val);
      for (; run-- > 0; q++)
        update(query(val), val);
    }
    else {
      sscanf(str, "%d", &val);
      update(query(val), val);
      q++;
    }
  }
  int used = 0, waste = 0;
  for (; vol[used + LIM] != cap; used++)
    waste += vol[used + LIM];
  printf("%d %d\n", used, waste);
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
  HELPR2D2::solve();
  return 0;
}

