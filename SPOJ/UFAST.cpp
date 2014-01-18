/* Solved
 * 695. Unite Fast
 * File:   UFAST.cpp
 * Author: Andy Y.F. Huang
 * Created on February 11, 2013, 11:17 PM
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

/**
 * Unsolved
 * @author Andy Y.F. Huang
 */
namespace UFAST {
#define MAX 1024
int pos[111];
int dp[1111], prev[1111];
int dyn[1111], prev2[1111];

void solve(int test_num) {
  int len, lim;
  scanf("%d %d", &len, &lim);
  for (int i = 0; i < len; i++)
    scanf("%d", pos + i);
  sort(pos, pos + len);
  for (int i = 0; i <= MAX; i++)
    prev[i] = prev2[i] = abs(i - pos[0]);
  for (int i = 1; i < len; i++) {
    memset(dp, 0, sizeof (dp));
    memset(dyn, 0, sizeof (dyn));
    deque<int> dq, dq2;
    int at = 0;
    for (int j = 0; j <= MAX; j++) {
      for (; at <= MAX && at <= j + lim; at++) {
        while (!dq.empty() && prev[at] <= prev[dq.back()])
          dq.pop_back();
        dq.push_back(at);
        while (!dq2.empty() && prev2[at] <= prev2[dq2.back()])
          dq2.pop_back();
        dq2.push_back(at);
      }
      while (dq.front() < j - lim)
        dq.pop_front();
      while (dq2.front() < j - lim)
        dq2.pop_front();
      dp[j] = prev[dq.front()] + abs(pos[i] - j);
      dyn[j] = max(prev2[dq2.front()], abs(pos[i] - j));
    }
    memcpy(prev, dp, sizeof (prev));
    memcpy(prev2, dyn, sizeof (prev2));
  }
  printf("%d %d\n", *min_element(prev2, prev2 + MAX + 1), *min_element(prev, prev + MAX + 1));
}

void makecase() {
  freopen("input.txt", "w", stdout);
  srand(time(NULL));
  printf("%d\n", 1);
  int len = rand() % 100 + 1, lim = rand() % 100 + 1;
  printf("%d %d\n", len, lim);
  for (int i = 0; i < len; i++)
    printf("%d ", rand() % 1000);
}

void solve() {
  #ifdef AZN
  //makecase();
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
  UFAST::solve();
  return 0;
}

