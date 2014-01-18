/* Solved
 * 11102. SelfDescribingSequenceProblem
 * File:   MAIN12A.cpp
 * Author: Andy Y.F. Huang
 * Created on April 22, 2013, 12:32 AM
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

namespace MAIN12A {
#define MAX 1000001
int ans[MAX];

void solve(int test_num) {
  int n;
  scanf("%d", &n);
  printf("Case #%d: %d\n", test_num, ans[n]);
}

void init() {
  ans[1] = 1;
  for (int i = 2, at = 1, num = 2; i < MAX; ) {
    int st = i, cnt = ans[at];
    while (i < MAX && i - st < cnt)
      ans[i++] = num;
    at++;
    num++;
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  init();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  MAIN12A::solve();
  return 0;
}

