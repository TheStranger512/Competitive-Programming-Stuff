/* Solved
 * 4354. Snowflakes
 * File:   TWINSNOW.cpp
 * Author: Andy Y.F. Huang
 * Created on September 19, 2012, 1:15 AM
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
namespace TWINSNOW {
int snow[100100][6], sum[100100] = {0};
int order[100100], len;

bool cmp(int a, int b) {
  if (sum[a] != sum[b])
    return sum[a] < sum[b];
  for (int i = 0; i < 6; i++)
    if (snow[a][i] != snow[b][i])
      return snow[a][i] < snow[b][i];
  return false;
}

void solve(int test_num) {
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    order[i] = i;
    for (int j = 0; j < 6; j++) {
      scanf("%d", &snow[i][j]);
      sum[i] += snow[i][j];
    }
    sort(snow[i], snow[i] + 6);
  }
  sort(order, order + len, cmp);
  for (int i = 0; i < len - 1; i++) {
    int compare = 0;
    for (int j = 0; j < 6; j++) {
      if (snow[order[i]][j] != snow[order[i + 1]][j]) {
        compare = -1;
        break;
      }
    }
    if (compare == 0)  {
      puts("Twin snowflakes found.");
      return;
    }
  }
  puts("No two snowflakes are alike.");
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
  TWINSNOW::solve();
  return 0;
}

