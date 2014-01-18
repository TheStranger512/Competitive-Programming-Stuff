/* Solved
 * 4180. Pizza Location
 * File:   PIZZALOC.cpp
 * Author: Andy Y.F. Huang
 * Created on January 4, 2013, 4:38 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace PIZZALOC {
#define SIZE(x) (int) (x.size())
int rx[22], ry[22];
int px[111], py[111], ppl[111];
bool have[111];
vector<int> poss[22];

inline int dist(int x, int y, int a, int b) {
  return (x - a)*(x - a) + (y - b)*(y - b);
}

void solve(int test_num) {
  int rests, radius, locs;
  scanf("%d %d %d", &rests, &radius, &locs);
  for (int i = 0; i < locs; i++)
    scanf("%d %d", &rx[i], &ry[i]);
  int pplcnt;
  scanf("%d", &pplcnt);
  for (int i = 0; i < pplcnt; i++)
    scanf("%d %d %d", &px[i], &py[i], &ppl[i]);
  radius *= radius;
  for (int i = 0; i < locs; i++)
    for (int j = 0; j < pplcnt; j++)
      if (dist(rx[i], ry[i], px[j], py[j]) <= radius)
        poss[i].push_back(j);
  int ans = 0;
  for (int mask = (1 << locs) - 1; mask > 0; mask--) {
    if (__builtin_popcount(mask) != rests)continue;
    memset(have, false, sizeof (have));
    int sum = 0;
    for (int bit = 0; bit < locs; bit++)
      if (1 << bit & mask)
        for (int i = 0; i < SIZE(poss[bit]); i++)
          if (!have[poss[bit][i]]) {
            have[poss[bit][i]] = true;
            sum += ppl[poss[bit][i]];
          }
    ans = max(ans, sum);
  }
  printf("%d\n", ans);
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
  PIZZALOC::solve();
  return 0;
}

