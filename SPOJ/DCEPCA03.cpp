/* Solved
 * 12914. Totient Extreme
 * File:   DCEPCA03.cpp
 * Author: Andy Y.F. Huang
 * Created on December 7, 2012, 10:43 PM
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
namespace DCEPCA03 {
#define lim 10010
int sum[11111];
int phi[11111];

void solve(int test_num) {
  int upto;
  scanf("%d", &upto);
  long long ans = 0;
  for (int i = 1; i <= upto; i++)
    ans += 1LL * phi[i] * sum[upto];
  printf("%lld\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  for (int i = 1; i <= lim; i++)
    phi[i] = i;
  for (int i = 2; i <= lim; i++) {
    if (phi[i] == i) {
      phi[i]--;
      for (int j = i + i; j <= lim; j += i)
        phi[j] = phi[j] * (i - 1) / i;
    }
  }
  for (int i = 1; i <= lim; i++)
    sum[i] = phi[i] + sum[i - 1];
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  DCEPCA03::solve();
  return 0;
}

