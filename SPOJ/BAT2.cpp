/* Solved
 * 13631. BATMAN2
 * File:   BAT2.cpp
 * Author: Andy Y.F. Huang
 * Created on February 10, 2013, 12:24 AM
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
 * Solved
 * @author Andy Y.F. Huang
 */
namespace BAT2 {

template <class T, size_t MAXSIZE, class Comp = less<T> > struct Indexer {
  T arr[MAXSIZE];
  int len;

  void add(const T & val) {
    arr[len++] = val;
  }

  void reset() {
    len = 0;
  }

  void process() {
    sort(arr, arr + len, Comp());
    len = unique(arr, arr + len) - arr;
  }

  int get(const T & val) {
    return lower_bound(arr, arr + len, val, Comp()) - arr;
  }
} ;

Indexer<int, 111 > hasher;
int dp[111][111], prev[111][111];
int arr[111];

void solve(int test_num) {
  hasher.reset();
  hasher.add(-(1 << 20));
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%d", arr + i);
    hasher.add(arr[i]);
  }
  hasher.process();
  for (int i = 0; i < len; i++)
    arr[i] = hasher.get(arr[i]);
  memset(prev, 0xF0, sizeof (prev));
  prev[0][len + 1] = 0;
  for (int i = 0; i < len; i++) {
    memset(dp, 0xF0, sizeof (dp));
    for (int u = 0; u <= len + 1; u++)
      for (int d = 0; d <= len + 1; d++) {
        dp[u][d] = max(dp[u][d], prev[u][d]);
        if (arr[i] > u)
          dp[arr[i]][d] = max(dp[arr[i]][d], prev[u][d] + 1);
        if (arr[i] < d)
          dp[u][arr[i]] = max(dp[u][arr[i]], prev[u][d] + 1);
      }
    memcpy(prev, dp, sizeof (prev));
  }
  int ans = 0;
  for (int u = 0; u <= len + 1; u++)
    for (int d = 0; d <= len + 1; d++)
      ans = max(ans, dp[u][d]);
  printf("%d\n", ans);
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
  BAT2::solve();
  return 0;
}

