/* Solved
 * 8785. Cut the Silver Bar
 * File:   SILVER.cpp
 * Author: Andy Y.F. Huang
 * Created on July 25, 2013, 9:45 PM
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

namespace SILVER {

void solve(int test_num) {
  int N;
  while (cin >> N)
    if (N > 0)
      for (int l = 15; l >= 0; l--)
        if (1 << l & N) {
          printf("%d\n", l);
          break;
        }

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
  SILVER::solve();
  return 0;
}

