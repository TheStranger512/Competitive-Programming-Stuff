/* Solved
 * 3969. M&M Game
 * Regular nim game
 * File:   MMMGAME.cpp
 * Author: Andy Y.F. Huang
 * Created on September 24, 2012, 8:55 PM
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
namespace MMMGAME {
int val[55], len;

void solve(int test_num) {
  scanf("%d", &len);
  int ones = 0, sum = 0;
  for (int i = 0; i < len; i++) {
    scanf("%d", &val[i]);
    sum ^= val[i];
    ones += val[i] == 1;
  }
  if (ones == len)
    puts(ones % 2 ? "Brother" : "John");
  else
    puts(sum == 0 ? "Brother" : "John");
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
  MMMGAME::solve();
  return 0;
}

