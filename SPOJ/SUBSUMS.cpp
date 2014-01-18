/* Solved
 * 3749. Subset Sums
 * File:   SUBSUMS.cpp
 * Author: Andy Y.F. Huang
 * Created on January 3, 2013, 11:11 PM
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
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <cstddef>
#include <utility>
#include <valarray>
#include <cstdlib>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace SUBSUMS {
int num[35];
int val[155555], cnt[155555];

void solve(int test_num) {
  int len, from, to;
  scanf("%d %d %d", &len, &from, &to);
  for (int i = 0; i < len; i++)
    scanf("%d", &num[i]);
  int first = len >> 1, second = len - first;
  for (int mask = (1 << first) - 1; mask >= 0; mask--) {
    val[mask] = 0;
    for (int bit = 0; bit < first; bit++)
      if (1 << bit & mask)
        val[mask] += num[bit];
  }
  sort(val, val + (1 << first));
  int firstlen = 0;
  for (int i = 0; i < (1 << first); ) {
    int j = i;
    cnt[firstlen] = 0;
    while (j < (1 << first) && val[j] == val[i])
      j++, cnt[firstlen]++;
    val[firstlen++] = val[i];
    i = j;
  }
  partial_sum(cnt, cnt + firstlen, cnt);
  long long ans = 0;
  for (int mask = (1 << second) - 1; mask >= 0; mask--) {
    int sum = 0;
    for (int bit = 0; bit < second; bit++)
      if (1 << bit & mask)
        sum += num[first + bit];
    int high = upper_bound(val, val + firstlen, to - sum) - val - 1;
    int low = lower_bound(val, val + firstlen, from - sum) - val;
    if (low <= high)
      ans += cnt[high] - (low == 0 ? 0 : cnt[low - 1]);
  }
  printf("%lld\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests = 1;
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  SUBSUMS::solve();
  return 0;
}

