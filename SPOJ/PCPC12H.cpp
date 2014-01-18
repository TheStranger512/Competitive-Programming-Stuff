/* Solved
 * 13094. Beggars
 * File:   PCPC12H.cpp
 * Author: Andy Y.F. Huang
 * Created on December 28, 2012, 10:52 PM
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
namespace PCPC12H {

struct Mosque {
  int pos, time, money;

  bool operator<(const Mosque & m) const {
    return time < m.time;
  }
} ;

Mosque places[111];
long long dp[111][111];
int len;
bool adj[111][111];

void solve(int test_num) {
  memset(adj, false, sizeof (adj));
  for (int i = 1; i <= len; i++)
    scanf("%d %d %d", &places[i].pos, &places[i].time, &places[i].money);
  sort(places + 1, places + len + 1);
  memset(dp, 0, sizeof (dp));
  long long ans = 0;
  for (int i = 1; i <= len; i++)
    for (int j = 1; j < i; j++)
      if (places[i].time - places[j].time >= abs(places[i].pos - places[j].pos))
        adj[j][i] = true;
  for (int i = 1; i <= len; i++)
    adj[0][i] = true;
  for (int k = 1; k <= len; k++) {
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        if (adj[j][k])
          dp[i][k] = max(dp[i][k], dp[i][j] + places[k].money);
        if (adj[i][k])
          dp[k][j] = max(dp[k][j], dp[i][j] + places[k].money);
      }
    }
  }
  //plnarr(dp, len + 1, len + 1);
  for (int i = 1; i <= len; i++)
    ans = max(ans, *max_element(dp[i], dp[i] + len + 1));
  printf("%lld\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (true) {
    scanf("%d", &len);
    if (len == 0) break;
    solve(1);
  }
}
}

int main() {
  PCPC12H::solve();
  return 0;
}

