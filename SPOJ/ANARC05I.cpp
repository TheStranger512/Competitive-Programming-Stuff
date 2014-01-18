/* Solved
 * 4565. What is your Logo
 * The number of polygons is equal to number of times
 * a point is revisited because segments dont overlap
 * File:   ANARC05I.cpp
 * Author: Andy Y.F. Huang
 * Created on September 11, 2012, 9:38 PM
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
namespace ANARC05I {
char str[1010];
int pts[1010];

void solve(int test_num) {
  int ans = 0, len = 0, x = 1024, y = 1024;
  pts[len++] = (x << 10) + y;
  for (int i = 0; str[i] != 'Q'; i++) {
    if (str[i] == 'U')
      y++;
    else if (str[i] == 'D')
      y--;
    else if (str[i] == 'L')
      x--;
    else
      x++;
    pts[len++] = (x << 10) + y;
  }
  sort(pts, pts + len);
  for (int i = 1; i < len; i++)
    ans += pts[i] == pts[i - 1];
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%s", str);
    if (str[0] == 'Q')
      break;
    solve(1);
  }
}
}

int main() {
  ANARC05I::solve();
  return 0;
}

