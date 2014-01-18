/* Solved
 * 3934. Recaman’s Sequence - simple iteration
 * File:   MRECAMAN.cpp
 * Author: Andy Y.F. Huang
 * Created on August 31, 2012, 1:13 AM
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
namespace MRECAMAN {
bool seen[3012600] = {false};
int ans[500010];

void init() {
  ans[0] = 0;
  for (int i = 1; i <= 500000; i++) {
    ans[i] = ans[i - 1] - i;
    if (ans[i] > 0 && !seen[ans[i]])
      seen[ans[i]] = true;
    else
      ans[i] += (i << 1), seen[ans[i]] = true;
  }
}

inline void solve(int test_num, int k) {
  printf("%d\n", ans[k]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  init();
  while (true) {
    int k;
    scanf("%d", &k);
    if (k == -1)
      break;
    solve(1, k);
  }
}
}

int main() {
  MRECAMAN::solve();
  return 0;
}

