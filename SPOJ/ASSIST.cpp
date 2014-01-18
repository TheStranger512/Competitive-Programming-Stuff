/* Solved
 * 1798. Assistance Required
 * File:   ASSIST.cpp
 * Author: Andy Y.F. Huang
 * Created on August 3, 2012, 1:15 AM
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
namespace ASSIST {
bool chosen[34000] = {0};
int nums[3010];

void init() {
  int len = 1, cur = 2;
  while (len <= 3000) {
    while (chosen[cur])
      cur++;
    nums[len++] = cur;
    int i = cur + 1, cnt = 0;
    while (i < 34000) {
      if (chosen[i]) {
        i++;
        continue;
      }
      cnt++;
      if (cnt == cur) {
        cnt = 0;
        chosen[i] = true;
      }
      i++;
    }
    cur++;
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  init();
  while (true) {
    int n;
    scanf("%d", &n);
    if (n == 0)
      break;
    printf("%d\n", nums[n]);
  }
}
}

int main() {
  ASSIST::solve();
  return 0;
}

