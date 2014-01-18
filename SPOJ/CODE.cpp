/* Solved
 * 1785. Code
 * File:   CODE.cpp
 * Author: Andy Y.F. Huang
 * Created on September 28, 2012, 8:54 PM
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
namespace CODE {
int rec[1 << 20], prevedge[1 << 20], top;
bool used[1 << 20][10];
int mod, len;

void solve (int test_num) {
  mod = 1, top = 0;
  memset(used, false, sizeof (used));
  for (int i = 0; i < len - 1; i++)
    mod *= 10;
  rec[top] = 0, prevedge[top++] = -1;
  while (top > 0) {
outer:
    int state = rec[top - 1];
    for (int d = 9; d >= 0; d--) {
      if (!used[state][d]) {
        used[state][d] = true;
        rec[top] = (state * 10 + d) % mod;
        prevedge[top++] = d;
        goto outer;
      }
    }
    if (prevedge[--top] != -1)
      putchar(prevedge[top] + '0');
  }
  for (int i = 0; i < len - 1; i++)
    putchar('0');
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d", &len);
    if (!len)
      break;
    solve(1);
  }
}
}

int main() {
  CODE::solve();
  return 0;
}

