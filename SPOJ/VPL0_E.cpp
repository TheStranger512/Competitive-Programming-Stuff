/* Solved
 * 12962. External Sequence
 * File:   VPL0_E.cpp
 * Author: Andy Y.F. Huang
 * Created on December 10, 2012, 9:49 PM
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
namespace VPL0_E {
string ans[44];

void solve(int test_num) {
  int n;
  scanf("%d", &n);
  printf("Scenario #%d: %s\n", test_num, ans[n].c_str());
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ans[0] = "1";
  for (int i = 1; i <= 40; i++) {
    stringstream ss;
    for (int j = 0; j < (int) ans[i - 1].size(); ) {
      int cnt = 0, cur = ans[i - 1][j];
      int k = j;
      while (k < (int) ans[i - 1].size() && ans[i - 1][k] == cur)
        k++, cnt++;
      j = k;
      ss << cnt << (cur - '0');
    }
    ss >> ans[i];
  }
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  VPL0_E::solve();
  return 0;
}

