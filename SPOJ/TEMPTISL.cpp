/*
 * Solved
 * 4179. Temptation Island
 * File:   TEMPTISL.cpp
 * Author: Andy Y.F. Huang
 * Created on January 26, 2013, 12:41 AM
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
namespace TEMPTISL {
int size, len, st, ed;
long long dp[55][55];

void solve(int test_num) {
  memset(dp, 0, sizeof (dp));
  dp[0][--st] = 1;
  for (int p = 0; p < len; p++)
    for (int i = 0; i < size; i++) {
      dp[p + 1][(i + 1) % size] += dp[p][i];
      dp[p + 1][(i - 1 + size) % size] += dp[p][i];
    }
  printf("%lld\n", dp[len][--ed]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (true) {
    scanf("%d %d %d %d", &size, &len, &st, &ed);
    if (size == -1) break;
    solve(1);
  }
}
}

int main() {
  TEMPTISL::solve();
  return 0;
}

