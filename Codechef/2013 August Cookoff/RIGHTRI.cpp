/*
 * 
 * File:   RIGHTRI.cpp
 * Author: Andy Y.F. Huang
 * Created on Aug 18, 2013, 12:23:55 PM
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

using namespace std;

namespace RIGHTRI {

int sq(int x) {
  return x * x;
}

void solve(int test_num) {
  int N, res = 0;
  int x1, y1, x2, y2, x3, y3, a[3];
  scanf("%d", &N);
  while (N--) {
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    a[0] = sq(x1 - x2) + sq(y1 - y2);
    a[1] = sq(x1 - x3) + sq(y1 - y3);
    a[2] = sq(x2 - x3) + sq(y2 - y3);
    sort(a, a + 3);
    if (a[2] == a[0] + a[1])
      res++;
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
  RIGHTRI::solve();
  return 0;
}
