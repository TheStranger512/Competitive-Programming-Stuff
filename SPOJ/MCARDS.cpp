/* Solved
 * 4053. Card Sorting
 * File:   MCARDS.cpp
 * Author: Andy Y.F. Huang
 * Created on March 29, 2013, 7:22 PM
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

namespace MCARDS {
int rank[4] = {0, 1, 2, 3};
int color[444], value[444];
int dp[444][444];
int order[444];

bool cmp(int a, int b) {
  return rank[color[a]] < rank[color[b]]
          || (rank[color[a]] == rank[color[b]] && value[a] < value[b]);
}

void solve(int test_num) {
  int cols, len;
  scanf("%d %d", &cols, &len);
  len *= cols;
  for (int i = 1; i <= len; i++) {
    scanf("%d %d", color + i, value + i);
    color[i]--;
  }
  int ans = 1 << 20;
  do {
    for (int i = 1; i <= len; i++)
      order[i] = i;
    sort(order + 1, order + len + 1, cmp);
    memset(dp, 0, sizeof (dp));
    for (int i = 1; i <= len; i++)
      for (int j = 1; j <= len; j++)
        if (color[i] == color[order[j]] && value[i] == value[order[j]])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    ans = min(ans, len - dp[len][len]);
  } while (next_permutation(rank, rank + cols));
  printf("%d\n", ans);
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
  MCARDS::solve();
  return 0;
}

