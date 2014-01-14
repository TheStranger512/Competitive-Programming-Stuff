/* Solved
 * IOI '07 - Zagreb, Croatia
 * Miners
 * File:   ioi0721.cpp
 * Author: Andy Y.F. Huang
 * Created on September 21, 2012, 12:24 AM
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
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ioi0721 {
//max production type of last 2 shipments for each mine
//encoded for every 2 bits, 0 is empty state
//first 2 bits is type of second last shipment
//second 2 bits is type of last shipment
//1 - meat, 2 - fish, 3 - bread
int len, dp[1 << 4][1 << 4], prev[1 << 4][1 << 4], cnt[4];
const int k_empty = 0;
char str[100010];

inline int value(int state, int type) {
  cnt[1] = cnt[2] = cnt[3] = 0;
  cnt[state >> 2] = cnt[state & 3] = cnt[type] = 1;
  return cnt[1] + cnt[2] + cnt[3];
}

inline int newstate(int state, int type) {
  return (state >> 2) + (type << 2);
}

void solve(int test_num) {
  memset(prev, 0xF0, sizeof (prev));
  prev[0][0] = 0;
  scanf("%d\r\n", &len);
  gets(str + 1);
  for (int i = 1; i <= len; i++) {
    memset(dp, 0xF0, sizeof (dp));
    int type = str[i] == 'M' ? 1 : str[i] == 'F' ? 2 : 3;
    for (int state1 = 0; state1 < 16; state1++) {
      for (int state2 = 0; state2 < 16; state2++) {
        int nstate1 = newstate(state1, type);
        int nstate2 = newstate(state2, type);
        dp[nstate1][state2] = max(dp[nstate1][state2], prev[state1][state2] + value(state1, type));
        dp[state1][nstate2] = max(dp[state1][nstate2], prev[state1][state2] + value(state2, type));
      }
    }
    //    int x = 0, y = 0;
    //    for (int a = 0; a < 16; a++)
    //      for (int b = 0; b < 16; b++)
    //        if (dp[a][b] > dp[x][y])
    //          x = a, y = b;
    //    //pln(i, x, y, dp[x][y]);
    memcpy(prev, dp, sizeof (int) * (1 << 8));
  }
  int ans = 0;
  for (int i = 0; i < 16; i++)
    for (int j = 0; j < 16; j++)
      ans = max(ans, dp[i][j]);
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  ioi0721::solve();
  return 0;
}

