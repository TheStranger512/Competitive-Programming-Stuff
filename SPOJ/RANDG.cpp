/* Solved
 * 12363. Red And Green
 * File:   RANDG.cpp
 * Author: Andy Y.F. Huang
 * Created on July 22, 2013, 12:23 PM
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

namespace RANDG {
string str;

void solve(int test_num) {
  int len = str.size(), res = len;
  for (int i = -1, gr = 0; i < len; i++) {
    if (i >= 0 && str[i] == 'G')
      gr++;
    int red = 0;
    for (int j = i + 1; j < len; j++)
      if (str[j] == 'R')
        red++;
    res = min(res, gr + red);
  }
  cout << res << endl;
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (cin >> str)
    solve(1);
}
}

int main() {
  RANDG::solve();
  return 0;
}

