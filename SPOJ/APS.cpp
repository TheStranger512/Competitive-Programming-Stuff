/* Solved
 * 13753. Amazing Prime Sequence
 * File:   APS.cpp
 * Author: Andy Y.F. Huang
 * Created on February 14, 2013, 7:07 PM
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
namespace APS {
#define MAX 10000000
int low[MAX + 5];
long long ans[MAX + 5];

void solve(int test_num) {
  int n;
  scanf("%d", &n);
  printf("%lld\n", ans[n]);
 }

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  ans[0] = ans[1] = 0;
  memset(low, 0x3F, sizeof (low));
  for (int i = 2; i <= MAX; i++) {
    if (low[i] > i)
      for (int j = i; j <= MAX; j += i)
        low[j] = min(low[j], i);
    ans[i] = ans[i - 1] + low[i];
  }
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  APS::solve();
  return 0;
}

