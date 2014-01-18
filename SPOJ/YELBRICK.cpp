/* Solved
 * 10575. The Yellow Brick Road
 * File:   YELBRICK.cpp
 * Author: Andy Y.F. Huang
 * Created on August 12, 2012, 12:48 AM
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
namespace YELBRICK {
int bricks[1010][3];

void solve(int test_num, int len) {
  long long ans = 0;
  int size = 1234567890;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &bricks[i][j]);
      size = min(size, bricks[i][j]);
    }
  }
  for (int i = 0; i < len; i++) {
    long long cur = 1;
    for (int j = 0; j < 3; j++)
      cur *= bricks[i][j] / size;
    ans += cur;
  }
  printf("%lld\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    int len;
    scanf("%d", &len);
    if (len == 0)
      break;
    solve(1, len);
  }
}
}

int main() {
  YELBRICK::solve();
  return 0;
}

