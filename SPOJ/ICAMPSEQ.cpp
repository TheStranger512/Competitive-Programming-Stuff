/* Solved
 * 1784. IOICamp Sequence
 * File:   ICAMPSEQ.cpp
 * Author: Andy Y.F. Huang
 * Created on September 4, 2012, 4:30 PM
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
namespace ICAMPSEQ {
double low[10], high[10], x[4];
char str[4][50];

void solve(int test_num) {
  int len;
  double ans = -1e10;
  scanf("%d", &len);
  for (int i = 0; i < 10; i++)
    low[i] = 1e10, high[i] = -1e10;
  for (int i = 0; i < len; i++) {
    double sum;
    scanf("%s %s %s %s", str[0], str[1], str[2], str[3]);
    x[0] = atof(str[0]);
    x[1] = atof(str[1]);
    x[2] = atof(str[2]);
    x[3] = atof(str[3]);
    for (int mask = 0; mask < 8; mask++) {
      sum = 0;
      for (int bit = 0; bit < 4; bit++)
        sum += (1 << bit & mask) ? x[bit] : -x[bit];
      low[mask] = min(low[mask], sum);
      high[mask] = max(high[mask], sum);
    }
  }
  for (int i = 0; i < 8; i++)
    ans = max(ans, high[i] - low[i]);
  printf("%.3lf\n", ans);
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
  ICAMPSEQ::solve();
  return 0;
}

