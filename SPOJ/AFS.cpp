/* Solved
 * 14138. Amazing Factor Sequence
 * File:   AFS.cpp
 * Author: Andy Y.F. Huang
 * Created on April 21, 2013, 5:16 PM
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

namespace AFS {
#define MAX 1000001
long long ans[MAX];
int rem[MAX];
int sum[MAX];
bool sieve[MAX];
//sum of all divisors < i

void solve(int test_num) {
  int n;
  scanf("%d", &n);
  printf("%lld\n", ans[n]);
}

void init() {
  for (int i = 1; i < MAX; i++) {
    rem[i] = i;
    sum[i] = 1;
  }
  for (int i = 2; i < MAX; i++) {
    if (!sieve[i]) {
      for (int j = i; j < MAX; j += i) {
        int temp = 0, cur = 1;
        sieve[j] = true;
        while (rem[j] % cur == 0) {
          temp += cur;
          cur *= i;
        }
        if (temp > 1)
          sum[j] *= temp;
      }
    }
  }
  ans[0] = ans[1] = 0;
  for (int i = 2; i < MAX; i++)
    ans[i] = ans[i - 1] + sum[i] - i;
//  plnarr(ans, ans + 10);
//  plnarr(sum, sum + 10);
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
  AFS::solve();
  return 0;
}

