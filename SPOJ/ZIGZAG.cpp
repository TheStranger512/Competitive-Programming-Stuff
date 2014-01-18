/*
 * Solved
 * 7019. Zig-Zag rabbit
 * File:   ZIGZAG.cpp
 * Author: Andy Y.F. Huang
 * Created on January 28, 2013, 10:18 AM
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
namespace ZIGZAG {
typedef long long llong;
vector<llong> vals;
char str[333111];

void solve(int test_num) {
  int size, len;
  scanf("%d %d %s", &size, &len, str);
  llong ans = 1, sq = 1LL * size * size;
  int r = 0, c = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] == 'L') c--;
    else if (str[i] == 'R') c++;
    else if (str[i] == 'U') r--;
    else r++;
    int diag = r + c;
    if (diag < size) {
      llong upto = (diag + 0LL) * (diag + 1) / 2;
      if (diag & 1) ans += upto + diag - c + 1;
      else ans += upto + c + 1;
    }
    else {
      diag = 2 * size - r - c - 2;
      int nc = size - c - 1;
      llong upto = (diag + 0LL) * (diag + 1) / 2;
      if (diag & 1) ans += sq - (upto + diag - nc);
      else ans += sq - (upto + nc);
    }
  }
  printf("%lld\n", ans);
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
  ZIGZAG::solve();
  return 0;
}

