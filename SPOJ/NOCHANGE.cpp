/* Solved
 * 1847. No Change
 * File:   NOCHANGE.cpp
 * Author: Andy Y.F. Huang
 * Created on March 29, 2013, 10:44 PM
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

namespace NOCHANGE {
bool dp[111000];
int vals[11];

void solve(int test_num) {
  int len, tar;
  scanf("%d %d", &tar, &len);
  for (int i = 0; i < len; i++)
    scanf("%d", vals + i);
  for (int i = 1; i < len; i++)
    vals[i] += vals[i - 1];
  memset(dp, false, sizeof (dp));
  dp[0] = true;
  for (int i = 0; i < len; i++)
    for (int j = vals[i]; j <= tar; j++)
      dp[j] |= dp[j - vals[i]];
  if (dp[tar]) puts("YES");
  else puts("NO");
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
  NOCHANGE::solve();
  return 0;
}

