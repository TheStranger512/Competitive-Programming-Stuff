/* Solved
 * 3752. JEDNAKOST
 * File:   JEDNAKOS.cpp
 * Author: Andy Y.F. Huang
 * Created on December 31, 2012, 6:06 PM
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <cstddef>
#include <utility>
#include <valarray>
#include <cstdlib>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace JEDNAKOS {
int sum;
char str[1111];
int dp[1111][5555];
int low[1111];

void solve(int test_num) {
  scanf("%[^=]=%d", str + 1, &sum);
  memset(dp, 0x3F, sizeof (dp));
  dp[0][0] = 0;
  int len = strlen(str + 1);
  assert(1 <= len && len <= 1000);
  assert(1 <= sum && sum <= 5000);
  int i, j, k, cur, nlen = 0;
  for (i = 1; i <= len; i++)
    str[i] -= '0';
  for (i = 1; i <= len; ) {
    if (str[i] > 0) {
      str[++nlen] = str[i++];
      continue;
    }
    j = i;
    while (j <= len && str[j] == 0)
      j++;
    //reduce strings of zeros to at most 3
    for (k = 0; k < min(3, j - i); k++)
      str[++nlen] = 0;
    i = j;
  }
  for (i = 1; i <= nlen; i++) {
    low[i] = low[i - 1] + str[i];
    cur = 0;
    for (j = i; j <= nlen; j++) {
      cur = (cur << 1) + (cur << 3) + str[j];
      if (cur > sum)
        break;
      for (k = sum - cur; k >= low[i - 1]; k--) {
        dp[j][cur + k] = min(dp[j][cur + k], dp[i - 1][k] + 1);
      }
    }
  }
  printf("%d\n", dp[nlen][sum] - 1);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests = 1;
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  JEDNAKOS::solve();
  return 0;
}

