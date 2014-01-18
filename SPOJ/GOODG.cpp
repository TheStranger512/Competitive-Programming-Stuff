/* Solved
 * 14893. Good Inflation
 * File:   GOODG.cpp
 * Author: Andy Y.F. Huang
 * Created on June 1, 2013, 3:23 PM
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

namespace GOODG {
typedef long long llong;

struct Line {
  llong b;
  int m;

  llong val(int x) {
    return b + llong(m) * x;
  }

  bool better(const Line& A, const Line & B) {
    //is x-val of intersection with B >= x-val of intersection of A and B
    return (B.b - b) * (A.m - B.m) >= (B.b - A.b) * (m - B.m);
  }
} ;

Line s[1 << 20];

void solve(int test_num) {
  int len, top = 1;
  s[0].m = s[0].b = 0;
  scanf("%d", &len);
  for (int i = 1, inc, rate; i <= len; i++) {
    scanf("%d %d", &inc, &rate);
    while (top >= 2 && s[top - 1].val(i) <= s[top - 2].val(i))
      top--;
    Line cur;
    cur.m = -rate;
    cur.b = s[top - 1].val(i) + inc + llong(rate) * i;
    while (top >= 1 && s[top - 1].m <= cur.m)
      top--;
    while (top >= 2 && cur.better(s[top - 1], s[top - 2]))
      top--;
    s[top++] = cur;
  }
  while (top >= 2 && s[top - 1].val(len + 1) <= s[top - 2].val(len + 1))
    top--;
  printf("%lld\n", s[top - 1].val(len + 1));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  GOODG::solve();
  return 0;
}

