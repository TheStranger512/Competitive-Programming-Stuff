/* Solved
 * 3791. Street
 * File:   STREET.cpp
 * Author: Andy Y.F. Huang
 * Created on April 28, 2013, 2:51 PM
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

namespace STREET {
int low[522][522];
int dp[522][522];
//dp[i][j] = most area with i buildings, last building ends at <= j

void chmax(int& a, int b) {
  if (b > a) a = b;
}

void solve(int test_num) {
  memset(dp, 0xF0, sizeof (dp));
  memset(low, 0, sizeof (low));
  int len, cnt, most;
  scanf("%d %d %d", &len, &cnt, &most);
  for (int i = 1; i <= len; i++)
    scanf("%d", low[1] + i);
  for (int w = 2; w <= len; w++)
    for (int i = 1; i + w - 1 <= len; i++)
      low[w][i] = min(low[w - 1][i], low[1][i + w - 1]);
  memset(dp[0], 0, sizeof (dp[0]));
  for (int i = 1; i <= cnt; i++) { //i is # of buldings including new one
    for (int j = i; j <= len; j++) //j is pos of new building
      for (int w = 1; j + w - 1 <= len && w <= most; w++)
        chmax(dp[i][j + w - 1], dp[i - 1][j - 1] + low[w][j] * w);
    //plnarr(dp[i], dp[i] + len + 1);
    for (int j = 1; j <= len; j++)
      chmax(dp[i][j], dp[i][j - 1]);
  }
  printf("%d\n", dp[cnt][len]);
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
  STREET::solve();
  return 0;
}

