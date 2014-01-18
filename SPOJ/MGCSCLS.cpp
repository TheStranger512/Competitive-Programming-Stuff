/* Solved
 * 9096. Bob and magical scale
 * File:   MGCSCLS.cpp
 * Author: Andy Y.F. Huang
 * Created on April 1, 2013, 12:38 AM
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

namespace MGCSCLS {
#define OFFSET 65536
#define pos(x) (x+OFFSET)
int dpleft[2 * OFFSET], dpright[2 * OFFSET];
int temp[2 * OFFSET];
int leftval[25][55], rightval[25][55];
int size;

void checkmax(int& a, int b) {
  if (b > a) a = b;
}

void go(int* dp, int val[25][55], int cnt) {
  dp[pos(0)] = 0;
  int low = 0, high = 0;
  for (int i = 0; i < cnt; i++) {
    int nhigh = high, nlow = low;
    for (int j = 1; j <= size; j++) {
      val[i][j] += val[i][j - 1];
      nhigh = max(nhigh, high + val[i][j]);
      nlow = min(nlow, low + val[i][j]);
    }
    for (int k = nlow; k <= nhigh; k++)
      temp[pos(k)] = -OFFSET;
    for (int k = low; k <= high; k++)
      for (int j = 1; j <= size; j++)
        checkmax(temp[pos(k + val[i][j])], dp[pos(k)] + j);
    high = nhigh;
    low = nlow;
    for (int k = low; k <= high; k++)
      checkmax(dp[pos(k)], temp[pos(k)]);
  }
}

void solve(int test_num) {
  memset(dpleft, 0xF0, sizeof (dpleft));
  memset(dpright, 0xF0, sizeof (dpright));
  memset(leftval, 0, sizeof (leftval));
  memset(rightval, 0, sizeof (rightval));
  int leftcnt, rightcnt;
  scanf("%d %d %d", &size, &leftcnt, &rightcnt);
  for (int i = 0; i < leftcnt; i++)
    for (int j = 1; j <= size; j++)
      scanf("%d", leftval[i] + j);
  for (int i = 0; i < rightcnt; i++)
    for (int j = 1; j <= size; j++)
      scanf("%d", rightval[i] + j);
  go(dpleft, leftval, leftcnt);
  go(dpright, rightval, rightcnt);
  int ans = -OFFSET;
  for (int i = 0; i < (OFFSET << 1); i++)
    ans = max(ans, dpleft[i] + dpright[i]);
  //plnarr(dpleft + OFFSET - 1, dpleft + OFFSET + 10);
  //plnarr(dpright + OFFSET - 1, dpright + OFFSET + 10);
  //pln(ans);
  printf("%d\n", leftcnt * size + rightcnt * size - ans);
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
  MGCSCLS::solve();
  return 0;
}

