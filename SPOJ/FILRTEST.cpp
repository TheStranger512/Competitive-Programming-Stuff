/* Solved
 * 7423. File Recover Testing
 * File:   FILRTEST.cpp
 * Author: Andy Y.F. Huang
 * Created on July 25, 2013, 9:04 PM
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

namespace FILRTEST {
int K;
char str[1000111];
int pre[1000111];

void solve(int test_num) {
  if (K == -1) return;
  int len = strlen(str);
  pre[0] = -1;
  for (int i = 0, j = -1; i < len; ) {
    while (~j && str[j] != str[i])
      j = pre[j];
    pre[++i] = ++j;
  }
  int common = pre[len], res = 0;
  for (int low = 1, high = 1000000000, mid; low <= high; ) {
    mid = (low + high) >> 1;
    if (1LL * mid * len - (mid - 1LL) * common <= K) {
      res = mid;
      low = mid + 1;
    }
    else high = mid - 1;
  }
  printf("%d\n", res);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %s", &K, str) != EOF)
    solve(1);
}
}

int main() {
  FILRTEST::solve();
  return 0;
}

