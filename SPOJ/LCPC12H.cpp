/* Solved
 * 12409. Johnny at school
 * File:   LCPC12H.cpp
 * Author: Andy Y.F. Huang
 * Created on April 23, 2013, 9:28 PM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

namespace LCPC12H {
int rads[1555], pts[1555];
int dist[1555], prev[1555], ans[1555];
long long sum[1555];

void solve(int test_num) {
  memset(prev, -1, sizeof (prev));
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d %d", rads + i, pts + i);
  memset(dist, 0, sizeof (dist));
  memset(sum, 0xF0, sizeof (sum));
  memset(prev, -1, sizeof (prev));
  int best = 0;
  for (int i = 0; i < len; i++) {
    if (dist[i] == 0) {
      dist[i] = 1;
      sum[i] = pts[i];
    }
    for (int j = i + 1; j < len; j++) {
      if (rads[i] >= rads[j]) continue;
      if (dist[i] + 1 >= dist[j]) {
        if (dist[i] + 1 > dist[j]) {
          dist[j] = dist[i] + 1;
          sum[j] = sum[i] + pts[j];
          prev[j] = i;
        }
        else if (sum[i] + pts[j] >= sum[j]) {
          sum[j] = sum[i] + pts[j];
          prev[j] = i;
        }
      }
    }
    if (dist[i] >= dist[best]) {
      if (dist[i] > dist[best] || sum[i] >= sum[best])
        best = i;
    }
  }
//  plnarr(dist, dist + len);
//  plnarr(sum, sum + len);
  int anslen = 0;
  for (int at = best; at >= 0; at = prev[at])
    ans[anslen++] = at;
  reverse(ans, ans + anslen);
  printf("%d.", test_num);
  for (int i = 0; i < anslen; i++)
    printf(" %d", ans[i] + 1);
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  LCPC12H::solve();
  return 0;
}

