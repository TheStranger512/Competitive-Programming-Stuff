/* Solved
 * 11560. A Summatory
 * File:   PUCMM210.cpp
 * Author: Andy Y.F. Huang
 * Created on August 12, 2012, 1:01 AM
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
namespace PUCMM210 {
typedef unsigned long long uint64;
const uint64 k_max_n = 1000010, mod = 1000000003;
uint64 ans[k_max_n], f[k_max_n];

void init(){
  f[0] = 0;
  for (uint64 i = 1; i < k_max_n; i++)
    f[i] = (f[i - 1] + (i * i * i)) % mod;
  ans[1] = f[1];
  for (int i = 0; i < k_max_n; i++)
    ans[i] = (f[i] + ans[i - 1]) % mod;
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  init();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++) {
    int n;
    scanf("%d", &n);
    printf("%llu\n", ans[n]);
  }
}
}

int main() {
  PUCMM210::solve();
  return 0;
}

