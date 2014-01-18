/* Solved
 * 7676. Sum of Digits
 * File:   CPCRC1C.cpp
 * Author: Andy Y.F. Huang
 * Created on October 23, 2012, 8:45 PM
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
namespace CPCRC1C {
typedef long long int64;
int a, b;

int64 digitsum(int upto) {
  int64 ans = 0;
  int64 period = 10, mult = 45;
  for (int d = 0; period / 10 < upto; d++) {
    ans += upto / period * mult;
    int cycle = period / 10, rem = upto % period, i;
    for (i = 0; rem >= cycle ; i++) {
      ans += cycle * i;
      rem -= cycle;
    }
    ans += rem * i;
    mult *= 10;
    period *= 10;
  }
  return ans;
}

void solve(int test_num) {
  printf("%lld\n", digitsum(b + 1) - digitsum(a));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d %d", &a, &b);
    if (a == -1 && b == -1)
      break;
    solve(1);
  }
}
}

int main() {
  CPCRC1C::solve();
  return 0;
}

