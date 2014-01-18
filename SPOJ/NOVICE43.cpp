/* Solved
 * 8442. Problem 3
 * File:   NOVICE43.cpp
 * Author: Andy Y.F. Huang
 * Created on November 22, 2012, 8:30 PM
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
namespace NOVICE43 {

inline int lowestzerobit(int val) {
  for (int i = 0; ; i++)
    if (!(1 << i & val))
      return i;
  assert(false);
}

int memo[1 << 13][12], len, cnt = 0;

int rec(int mask, int pos) {
  if (memo[mask][pos] != -1)
    return memo[mask][pos];
  if (pos == len - 1) {
    //pln(mask, pos, lowestzerobit(mask) + 1);
    return memo[mask][pos] = (lowestzerobit(mask) + 1);
  }
  int ans = 0, lowzero = lowestzerobit(mask);
  for (int i = 0; i <= lowzero; i++)
    ans += rec(1 << i | mask, pos + 1);
  //pln(mask, pos, ans);
  return memo[mask][pos] = ans;
}

void solve(int test_num) {
  memset(memo, 0xFF, sizeof (memo));
  scanf("%d", &len);
  printf("%d\n", rec(0, 0));
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
  NOVICE43::solve();
  return 0;
}

