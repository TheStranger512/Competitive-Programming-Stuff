/* Solved
 * 15208. Minimum Cost
 * File:   MC.cpp
 * Author: Andy Y.F. Huang
 * Created on June 21, 2013, 12:21 PM
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

namespace MC {
int dp[1111], prev[1111];
char A[1111], B[1111];

void solve(int test_num) {
  if (A[0] == '#') return;
  int lenA = strlen(A + 1);
  int lenB = strlen(B + 1);
  prev[0] = 0;
  for (int j = 1; j <= lenB; j++)
    prev[j] = prev[j - 1] + 30;
  for (int i = 1; i <= lenA; i++) {
    dp[0] = i * 15;
    for (int j = 1; j <= lenB; j++) {
      if (A[i] == B[j])
        dp[j] = prev[j - 1];
      else
        dp[j] = min(15 + prev[j], 30 + dp[j - 1]);
    }
    memcpy(prev, dp, sizeof (prev));
  }
  printf("%d\n", dp[lenB]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%s %s", A + 1, B + 1) == 2)
    solve(1);
}
}

int main() {
  MC::solve();
  return 0;
}

