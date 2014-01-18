/* Solved
 * 110. Fill the Cisterns
 * File:   CISTFILL.cpp
 * Author: Andy Y.F. Huang
 * Created on August 15, 2012, 11:43 PM
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
namespace CISTFILL {
const int k_max_len = 50050;
int base[k_max_len], height[k_max_len], width[k_max_len], depth[k_max_len];

double getvolume(int len, double waterlevel) {
  double ans = 0.0;
  for (int i = 0; i < len; i++)
    if (base[i] <= waterlevel)
      ans += 1.0 * width[i] * depth[i] * (min(waterlevel, 1.0 * height[i]) - base[i]);
  return ans;
}

void solve(int test_num) {
  int len, volume, highest = 0;
  double low = 0, high;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%d %d %d %d", &base[i], &height[i], &width[i], &depth[i]);
    height[i] += base[i];
    highest = max(highest, height[i] + 5);
  }
  high = highest;
  scanf("%d", &volume);
  for (int iters = 0; iters < 100; iters++) {
    double mid = (low + high) / 2.0;
    //pln(mid);
    if (getvolume(len, mid) < volume)
      low = mid;
    else
      high = mid;
  }
  if (low >= highest)
    puts("OVERFLOW");
  else
    printf("%.2f\n", low);
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
  CISTFILL::solve();
  return 0;
}

