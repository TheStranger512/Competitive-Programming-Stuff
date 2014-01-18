/* Solved
 * 15038. Hell Classico
 * File:   CLASSICO.cpp
 * Author: Andy Y.F. Huang
 * Created on May 27, 2013, 10:37 PM
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

namespace CLASSICO {

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  printf("Case %d:", test_num);
  deque<int> dq;
  for (int i = 0, x; i < len; i++) {
    scanf("%d", &x);
    while (!dq.empty() && x > dq.back())
      dq.pop_back();
    dq.push_back(x);
    if (len >= 11 && i >= len - 11) {
      printf(" %d", dq.front());
      dq.pop_front();
    }
  }
  if (len < 11) puts(" go home!");
  else puts("");
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
  CLASSICO::solve();
  return 0;
}

