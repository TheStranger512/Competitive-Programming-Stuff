/* Solved
 * 10069. Kompići
 * File:   KOMPICI.cpp
 * Author: Andy Y.F. Huang
 * Created on December 8, 2012, 8:46 PM
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
namespace KOMPICI {
int count[1 << 11], count2[1 << 11];

int getmask(long long val) {
  int ans = 0;
  while (val > 9) {
    ans |= 1 << (val % 10);
    val /= 10;
  }
  ans |= 1 << val;
  return ans;
}

inline int bitcnt(int val)  {
  int ans = 0;
  while (val) {
    if (val & 1) ans++;
    val >>= 1;
  }
  return ans;
}

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    long long num;
    scanf("%lld", &num);
    count[getmask(num)]++;
    //pln(toString(getmask(num), 2));
  }
  long long ans = 0;
  for (int mask = 1023; mask > 0; mask--)
    for (int sub = mask - 1; sub > 0; sub--)
      if ((mask & sub) == sub)
        count2[sub] += count[mask];
  for (int mask = 1023; mask > 0; mask--)
    count[mask] += count2[mask];
  for (int mask = 1023; mask > 0; mask--) {
    //    if (count[mask])
    //      pln(toString(mask, 2), count[mask]);
    if (bitcnt(mask) & 1)
      ans += 1LL * count[mask] * (count[mask] - 1) / 2;
    else
      ans -= 1LL * count[mask] * (count[mask] - 1) / 2;
  }
  printf("%lld\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  KOMPICI::solve();
  return 0;
}

