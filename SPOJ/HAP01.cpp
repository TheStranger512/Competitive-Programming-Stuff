/* Solved
 * 14629. Play with Binary Numbers
 * File:   HAP01.cpp
 * Author: Andy Y.F. Huang
 * Created on April 21, 2013, 5:07 PM
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

namespace HAP01 {
#define MOD 65535
typedef unsigned long long ull;
int A[65536], B[65536];
//# of odd one bits, # of even one bits

void solve(int test_num) {
  ull from, to;
  int diff;
  cin >> from >> to >> diff;
  int ans = 0;
  for (ull i = from; i <= to; i++) {
    int even = 0, odd = 0;
    for (ull t = i; t > 0; t >>= 16) {
      even += A[t & MOD];
      odd += B[t & MOD];
    }
    if (abs(even - odd) == diff)
      ans++;
  }
  cout << ans << endl;
}

void init() {
  memset(A, 0, sizeof (A));
  memset(B, 0, sizeof (B));
  for (int i = 0; i <= MOD; i++) {
    for (int j = 0; j < 16; j++)
      if (1 << j & i) {
        if (j & 1) A[i]++;
        else B[i]++;
      }
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  init();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  HAP01::solve();
  return 0;
}

