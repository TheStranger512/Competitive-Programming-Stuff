/* Solved
 * 408. Jill Rides Again
 * File:   JRIDE.cpp
 * Author: Andy Y.F. Huang
 * Created on June 22, 2013, 1:19 PM
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

namespace JRIDE {
int len;

void solve(int test_num) {
  scanf("%d", &len);
  int low = 0, sum = 0, lowpos = 1, A = -1, B = -1;
  int best = 0;
  for (int i = 2, val; i <= len; i++) {
    scanf("%d", &val);
    sum += val;
    if (sum - low > best || (sum - low == best && (i - lowpos) > (B - A))) {
      A = lowpos;
      B = i;
      best = sum - low;
    }
    if (sum < low) {
      low = sum;
      lowpos = i;
    }
  }
  if (A == -1)
    printf("Route %d has no nice parts\n", test_num);
  else
    printf("The nicest part of route %d is between stops %d and %d\n", test_num, A, B);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int t = 1; t <= tests; t++)
    solve(t);
}
}

int main() {
  JRIDE::solve();
  return 0;
}

