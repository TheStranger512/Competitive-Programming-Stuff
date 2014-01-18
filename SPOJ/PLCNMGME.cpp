/* Solved
 * 8333. Place-name game
 * File:   PLCNMGME.cpp
 * Author: Andy Y.F. Huang
 * Created on June 22, 2013, 3:30 PM
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

namespace PLCNMGME {
#define MOD 100000007
typedef long long llong;
int cnt[21][21];
int dp[1 << 21];
const char* LETS = "BCDFGHJKLMNPQRSTVWXYZ";

void add(int& a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}

int ord(char c) {
  return strchr(LETS, c) - LETS;
}

void solve(int test_num) {
  memset(cnt, 0, sizeof (cnt));
  int len;
  scanf("%d", &len);
  if (len < 21) {
    puts("0");
    return;
  }
  for (int i = 0; i < len; i++) {
    static char str[15];
    scanf("%s", str);
    cnt[ord(str[0])][ord(str[strlen(str) - 1])]++;
  }
  dp[0] = 1;
  for (int mask = 0, cur, b; mask < 2097151; mask++) {
    if (dp[mask] == 0) continue;
    cur = __builtin_popcount(mask);
    for (b = 0; b < 21; b++)
      if (1 << b & ~mask)
        add(dp[mask | 1 << b], llong(cnt[cur][b]) * dp[mask] % MOD);
  }
  printf("%d\n", dp[2097151]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  PLCNMGME::solve();
  return 0;
}

