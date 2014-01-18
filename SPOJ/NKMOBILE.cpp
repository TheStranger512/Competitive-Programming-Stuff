/* Solved
 * 2226. IOI01 Mobiles
 * File:   NKMOBILE.cpp
 * Author: Andy Y.F. Huang
 * Created on October 18, 2012, 9:14 PM
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
namespace NKMOBILE {
int bit[1111][1111], size;

void update(int x, int y, int val) {
  x++, y++;
  for (int i = x; i <= size; i += i &-i)
    for (int j = y; j <= size; j += j&-j)
      bit[i][j] += val;
}

int query(int x, int y) {
  int ans = 0;
  x++, y++;
  for (int i = x; i > 0; i -= i&-i)
    for (int j = y; j > 0; j -= j&-j)
      ans += bit[i][j];
  return ans;
}

void solve(int test_num) {
  int command, x1, y1, x2, y2, val;
  while (true) {
    scanf("%d", &command);
    if (command == 3)
      break;
    if (command == 0) {
      scanf("%d", &size);
      memset(bit, 0, sizeof (bit));
    }
    else if (command == 1) {
      scanf("%d %d %d", &x1, &y1, &val);
      update(x1, y1, val);
    }
    else if (command == 2) {
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      printf("%d\n", query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1)
             + query(x1 - 1, y1 - 1));
    }
  }
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
  NKMOBILE::solve();
  return 0;
}

