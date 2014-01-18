/* Solved
 * 2006. Load Balancing - adhoc
 * File:   BALIFE.cpp
 * Author: Andy Y.F. Huang
 * Created on August 31, 2012, 12:38 AM
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
namespace BALIFE {
int tasks[9010], left[9010], right[9010], len;

void solve(int test_num) {
  long long sum = 0;
  int ans = 0;
  for (int i = 0; i < len; i++)
    scanf("%d", &tasks[i]), sum += tasks[i];
  if (sum % len) {
    puts("-1");
    return;
  }
  if (len == 1) {
    puts("0");
    return;
  }
  int per = sum / len;
  left[0] = 0;
  if (tasks[0] < per)
    right[0] = 0, left[1] = per - tasks[0];
  else
    right[0] = tasks[0] - per, left[1] = 0;
  ans = right[0];
  for (int i = 1; i < len; i++) {
    int cur = tasks[i] - left[i] + right[i - 1];
    if (cur < per)
      right[i] = 0, left[i + 1] = per - cur;
    else
      right[i] = cur - per, left[i + 1] = 0;
    ans = max(ans, right[i]);
    ans = max(ans, left[i]);
  }
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d", &len);
    if (len == -1)
      break;
    solve(1);
  }
}
}

int main() {
  BALIFE::solve();
  return 0;
}

