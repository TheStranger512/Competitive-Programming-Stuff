/* Solved
 * 3389. The Knights of the Round Circle
 * File:   KNIGHTSR.cpp
 * Author: Andy Y.F. Huang
 * Created on April 21, 2013, 11:42 PM
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

namespace KNIGHTSR {
double ans[11111];

void solve(int test_num) {
  int n;
  while (scanf("%d", &n) != EOF)
    if (n > 0)
      printf("With %d competitors, a Jedi Knight will be replaced approximately %.02lf times.\n\n", n, ans[n]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  for (int i = 2; i <= 10000; i++)
    ans[i] = ans[i - 1] + 1.0 / i;
  solve(1);
}
}

int main() {
  KNIGHTSR::solve();
  return 0;
}

