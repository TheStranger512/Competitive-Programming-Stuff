/* Solved
 * 15312. Annoying Coins Quest
 * File:   VPL2_BE.cpp
 * Author: Andy Y.F. Huang
 * Created on July 22, 2013, 12:45 PM
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

namespace VPL2_BE {
int v[111], t[111], k[111]; //value, transfer annoy, keep annoy
int trans[11111], change[11111];
//min annoyment transferring x money keeping rest
//max annoyment from shopkeeper giving out x change

void solve(int test_num) {
  int N, B; //# of coins, transaction cost;
  cin >> N >> B;
  for (int i = 0; i < N; i++)
    cin >> v[i] >> t[i] >> k[i];
  memset(trans, 0x3F, sizeof (trans));
  memset(change, 0xC0, sizeof (change));
  trans[0] = change[0] = 0;
  for (int i = 0, cnt; i < N; i++) {
    cin >> cnt;
    while (cnt--) {
      for (int b = 10000; b >= 0; b--)
        trans[b + v[i]] = min(trans[b + v[i]] + k[i], trans[b] + t[i]);
      for (int b = v[i] - 1; b >= 0; b--)
        trans[b] += k[i];//must keep
    }
    for (int b = 0; b <= 10000; b++)
      change[b + v[i]] = max(change[b + v[i]], change[b] + k[i] + t[i]);
  }
  //plnarr(trans, trans + 20);
  //plnarr(change, change + 20);
  int res = 1 << 30;
  for (int i = B; i <= 10000; i++)
    if (trans[i] < 1e7 && change[i - B] >= 0)
      res = min(res, trans[i] + change[i - B]);
  printf("Scenario #%d: %d\n", test_num, res > 1e7 ? -1 : res);
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
  VPL2_BE::solve();
  return 0;
}

