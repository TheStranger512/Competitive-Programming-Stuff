/* Solved
 * 13780. Audition
 * File:   CRAN04.cpp
 * Author: Andy Y.F. Huang
 * Created on February 18, 2013, 2:27 PM
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
namespace CRAN04 {
char str[1 << 20];
int cnt[1 << 20];

void solve(int test_num) {
  int len, need;
  scanf("%d %d %s", &len, &need, str);
  cnt[0] = 1;
  int cur = 0;
  long long ans = 0;
  for (int i = 0; i < len; i++) {
    cnt[i + 1] = 0;
    cur += str[i] == '1';
    if (cur >= need)
      ans += cnt[cur - need];
    cnt[cur]++;
  }
  printf("%lld\n", ans);
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
  CRAN04::solve();
  return 0;
}

