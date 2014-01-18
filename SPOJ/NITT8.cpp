/* Solved
 * 12326. Dating Rishi
 * File:   NITT8.cpp
 * Author: Andy Y.F. Huang
 * Created on October 28, 2012, 1:49 AM
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
namespace NITT8 {

struct Girl {
  int id, height;

  bool operator<(const Girl & g) const {
    return height > g.height;
  }
} ;

Girl girls[111111];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%d", &girls[i].height);
    girls[i].id = i;
  }
  sort(girls, girls + len);
  long long ans = 0;
  int maxpos = girls[0].id, minpos = girls[0].id;
  for (int i = 1; i < len; i++) {
    ans = max(ans, 1LL * girls[i].height * (maxpos - girls[i].id));
    ans = max(ans, 1LL * girls[i].height * (girls[i].id - minpos));
    maxpos = max(maxpos, girls[i].id);
    minpos = min(minpos, girls[i].id);
  }
  printf("%lld\n", ans);
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
  NITT8::solve();
  return 0;
}

