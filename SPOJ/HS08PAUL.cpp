/* Solved
 * 4164. A conjecture of Paul Erdős
 * precompute + binary search
 * File:   HS08PAUL.cpp
 * Author: Andy Y.F. Huang
 * Created on September 9, 2012, 10:31 PM
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
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace HS08PAUL {
typedef unsigned int uint;
const uint k_lim = 10000000;
int ans[15000];
const uint witnesses[] = {2, 7, 61};
uint len;

uint power(uint base, uint exp, uint mod) {
  uint ans = 1;
  while (exp) {
    if (exp & 1)
      ans = ((long long) ans * base) % mod;
    base = ((long long) base * base) % mod;
    exp >>= 1;
  }
  return ans;
}

bool millerRabin(unsigned int num) {
  const int k_len_bases = 3;
  if (num <= 1)
    return false;
  if (num <= 3)
    return true;
  if ((num & 1) == 0)
    return false;
  uint d = num - 1, s = 0;
  while ((d & 1) == 0) {
    d >>= 1;
    s++;
  }
  for (int i = 0; i < k_len_bases; i++) {
    if (witnesses[i] > num - 2)
      break;
    uint x = power(witnesses[i], d, num);
    if (x == 1 || x == num - 1)
      continue;
    bool flag = false;
    for (uint j = 0; j < s; j++) {
      x = power(x, 2, num);
      if (x == 1)
        return false;
      if (x == num - 1) {
        flag = true;
        break;
      }
    }
    if (!flag)
      return false;
  }
  return true;
}

void init() {
  uint sq[3300], four[60];
  len = 0;
  for (uint i = 0; i < 3300; i++)
    sq[i] = i * i;
  for (uint i = 0; i < 60; i++)
    four[i] = sq[i] * sq[i];
  for (int i = 0; i < 3300; i++) {
    for (int j = 0; j < 60; j++) {
      uint num = sq[i] + four[j];
      if (num <= k_lim && millerRabin(num))
        ans[len++] = num;
    }
  }
  sort(ans, ans + len);
  len = unique(ans, ans + len) - ans;
}

void solve(int test_num) {
  int n;
  scanf("%d", &n);
  printf("%d\n", upper_bound(ans, ans + len, n) - ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  init();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  HS08PAUL::solve();
  return 0;
}

