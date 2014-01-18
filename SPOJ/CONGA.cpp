/* Solved
 * 10399. Conga line
 * File:   CONGA.cpp
 * Author: Andy Y.F. Huang
 * Created on September 27, 2012, 9:53 PM
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
namespace CONGA {
int pos[1001000], len;

void solve(int test_num) {
  for (int i = 0; i < len; i++)
    scanf("%d", &pos[i]);
  long long ans = 0;
  for (int i = len / 2 - 1; i >= 0; i--)
    ans += pos[len - i - 1] - pos[i] - (len - (i << 1) - 1);
  printf("%lld\n", ans);
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
  CONGA::solve();
  return 0;
}

