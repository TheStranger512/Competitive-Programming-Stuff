/* Solved
 * Girl Friend and String Gift
 * File:   CHGLSTGT.cpp
 * Author: Andy Y.F. Huang
 * Created on Oct 27, 2013, 1:46:33 AM
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

using namespace std;

namespace CHGLSTGT {
typedef unsigned long long ll;
const ll BASE = 1000000007;
ll h[5555], r[5555], pw[5555];
int dp[5555];
int N;

bool ispalin(int a, int b) {
  //[a, b]
  ll x = h[b] - (a > 0 ? h[a - 1] * pw[b - a + 1] : 0);
  ll y = r[a] - r[b + 1] * pw[b - a + 1];
  return x == y;
}

void solve(int test_num) {
  string str;
  cin >> N >> str;
  h[0] = str[0];
  for (int i = 1; i < N; i++)
    h[i] = h[i - 1] * BASE + str[i];
  r[N] = 0;
  for (int i = N - 1; i >= 0; i--)
    r[i] = r[i + 1] * BASE + str[i];
  for (int i = 0; i < N; i++) {
    dp[i] = 1 << 29;
    if (ispalin(0, i))
      dp[i] = 1;
    for (int j = 1; j <= i; j++)
      if (ispalin(j, i))
        dp[i] = min(dp[i], dp[j - 1] + 1);
  }
  cout << dp[N - 1] << endl;
}

void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  pw[0] = 1;
  for (int i = 1; i <= 5000; i++)
    pw[i] = pw[i - 1] * BASE;
  int tests;
  cin >> tests;
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  CHGLSTGT::solve();
  return 0;
}
