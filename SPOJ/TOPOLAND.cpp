/* Solved
 * 10424. To Poland
 * File:   TOPOLAND.cpp
 * Author: Andy Y.F. Huang
 * Created on December 10, 2012, 8:24 PM
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
namespace TOPOLAND {
#define lim (1 << 17)
int rmq[lim << 1];
char str[5];

void solve(int test_num) {
  memset(rmq, 0xF, sizeof (rmq));
  int len, quests, amount;
  scanf("%d %d", &len, &amount);
  for (int i = 0; i < len; i++)
    scanf("%d", &rmq[i + lim]);
  for (int i = lim - 1; i; i--)
    rmq[i] = max(rmq[i + i], rmq[i + i + 1]);
  scanf("%d", &quests);
  printf("Testcase %d:\n", test_num - 1);
  for (int q = 0; q < quests; q++) {
    scanf("%s", str);
    if (str[0] == 'A') {
      int dif;
      scanf("%d", &dif);
      amount += dif;
    }
    else if (str[0] == 'B') {
      int pos, val;
      scanf("%d %d", &pos, &val);
      rmq[pos + lim] = val;
      for (int i = (pos + lim) >> 1; i; i >>= 1)
        rmq[i] = max(rmq[i + i], rmq[i + i + 1]);
    }
    else {
      int from, to, ans = -1;
      scanf("%d %d", &from, &to);
      for (int l = from + lim, r = to + lim + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = max(ans, rmq[l++]);
        if (r & 1) ans = max(ans, rmq[--r]);
      }
      printf("%d\n", abs(ans - amount));
    }
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  TOPOLAND::solve();
  return 0;
}

