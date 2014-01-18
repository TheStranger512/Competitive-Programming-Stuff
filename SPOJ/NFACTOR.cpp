/* Solved
 * 8238. N-Factorful
 * File:   NFACTOR.cpp
 * Author: Andy Y.F. Huang
 * Created on September 28, 2012, 4:33 PM
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
namespace NFACTOR {
const int k_lim = 1000000;
int ans[11][k_lim + 10];
int len[11] = {0};
int cnt[k_lim] = {0};

void init() {
  for (int i = 2; i <= k_lim; i++)
    if (cnt[i] == 0)
      for (int j = i; j <= k_lim; j += i)
        cnt[j]++;
  for (int i = 1; i <= k_lim; i++)
    ans[cnt[i]][len[cnt[i]]++] = i;
}

void solve(int test_num) {
  int a, b, n;
  scanf("%d %d %d", &a, &b, &n);
  printf("%d\n", upper_bound(ans[n], ans[n] + len[n], b)
         - lower_bound(ans[n], ans[n] + len[n], a));
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
  NFACTOR::solve();
  return 0;
}

