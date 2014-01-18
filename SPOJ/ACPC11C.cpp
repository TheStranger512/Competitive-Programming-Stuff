/* Solved
 * 10240. Circleland
 * File:   ACPC11C.cpp
 * Author: Andy Y.F. Huang
 * Created on February 17, 2013, 9:24 PM
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
namespace ACPC11C {
int sum[111000];

void solve(int test_num) {
  int len, ans = 0;
  scanf("%d", &len);
  for (int i = 1, val; i <= len; i++) {
    scanf("%d", &val);
    sum[i] = val + sum[i - 1];
    ans += val;
  }
  for (int i = 1; i <= len; i++) {
    int low = min(sum[len] - sum[i], sum[i - 1]);
    int high = max(sum[len] - sum[i], sum[i - 1]);
    ans = min(ans, 2 * low + high);
  }
  printf("%d\n", ans);
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
  ACPC11C::solve();
  return 0;
}

