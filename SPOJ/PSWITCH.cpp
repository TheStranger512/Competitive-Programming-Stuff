/* Solved
 * 8507. Party Switching
 * File:   PSWITCH.cpp
 * Author: Andy Y.F. Huang
 * Created on August 28, 2012, 9:12 PM
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
namespace PSWITCH {
char ans[16][1010];

bool cmp(int a, int b) {
  return strcmp(ans[a], ans[b]) < 0;
}

void solve(int test_num) {
  int lamps, counter, on[1000], oncnt = 0, off[1000], offcnt = 0, anslen = 0;
  int order[16];
  bool state[1010];
  scanf("%d %d", &lamps, &counter);
  while (true) {
    int lamp;
    scanf("%d", &lamp);
    if (lamp == -1)
      break;
    on[oncnt++] = lamp;
  }
  while (true) {
    int lamp;
    scanf("%d", &lamp);
    if (lamp == -1)
      break;
    off[offcnt++] = lamp;
  }
  for (int mask = (1 << 4) - 1; mask >= 0; mask--) {
    memset(state, true, sizeof (state));
    if (1 << 0 & mask) //toggle all lights
      memset(state, false, sizeof (state));
    if (1 << 1 & mask) //toggle odd lights
      for (int i = 1; i <= lamps; i += 2)
        state[i] ^= true;
    if (1 << 2 & mask) //toggle even lights
      for (int i = 2; i <= lamps; i += 2)
        state[i] ^= true;
    if (1 << 3 & mask) //toggle lamps 3k + 1 for all k
      for (int i = 1; i <= lamps; i += 3)
        state[i] ^= true;
    int bitcnt = 0;
    for (int i = 0; i < 4; i++)
      bitcnt += (1 << i & mask) > 0;
    bool good = (bitcnt & 1) == (counter & 1) && bitcnt <= counter;
    for (int i = 0; i < oncnt; i++)
      if (!state[on[i]])
        good = false;
    for (int i = 0; i < offcnt; i++)
      if (state[off[i]])
        good = false;
    if (good) {
      for (int i = 1; i <= lamps; i++)
        ans[anslen][i - 1] = state[i] ? '1' : '0';
      order[anslen] = anslen++;
    }
  }
  sort(order, order + anslen, cmp);
  if (anslen == 0) {
    puts("Impossible");
    return;
  }
  puts(ans[order[0]]);
  for (int i = 1; i < anslen; i++)
    if (strcmp(ans[order[i]], ans[order[i - 1]]) != 0)
      puts(ans[order[i]]);
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
  PSWITCH::solve();
  return 0;
}

