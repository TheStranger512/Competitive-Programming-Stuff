/* Solved
 * 7759. Hyperactive Girl
 * File:   MHLAR10.cpp
 * Author: Andy Y.F. Huang
 * Created on November 22, 2012, 8:10 PM
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

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace MHLAR10 {
#define mod 100000000
int maxval, len;
int dp[111][111]; //dp[i][j] = # of ways ending with i last and j second last
pair<int, int> events[111];

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

void solve(int test_num) {
  memset(dp, 0, sizeof (dp));
  for (int i = 1; i <= len; i++)
    scanf("%d %d", &events[i].first, &events[i].second);
  events[0] = make_pair(-100, 0);
  sort(events + 1, events + len + 1);
  for (int i = 1; i <= len; i++) {
    if (events[i].first == 0)
      dp[i][0] = 1;
    for (int j = 0; j < i; j++) {
      for (int k = 0; k < j; k++) {
        if (events[k].second < events[i].first && events[i].first <= events[j].second
                && events[j].second < events[i].second)
          add(dp[i][j], dp[j][k]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= len; i++)
    if (events[i].second >= maxval)
      for (int j = 0; j < i; j++)
        add(ans, dp[i][j]);
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d %d", &maxval, &len);
    if (maxval == 0 && len == 0)
      break;
    solve(1);
  }
}
}

int main() {
  MHLAR10::solve();
  return 0;
}

