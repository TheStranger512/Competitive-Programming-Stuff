/* Solved
 * 1027. Fool the Police
 * File:   FPOLICE.cpp
 * Author: Andy Y.F. Huang
 * Created on August 9, 2012, 5:54 PM
 */

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace FPOLICE {
const int k_max_len = 110, k_max_limit = 255;
int risk[k_max_len][k_max_len], dist[k_max_len][k_max_len];
int dp[k_max_len][k_max_limit];

void solve(int test_num) {
  int stations, limit;
  scanf("%d %d", &stations, &limit);
  for (int i = 0; i < stations; i++)
    for (int j = 0; j < stations; j++)
      scanf("%d", &dist[i][j]);
  for (int i = 0; i < stations; i++)
    for (int j = 0; j < stations; j++)
      scanf("%d", &risk[i][j]);
  memset(dp, 0x3F, sizeof (dp));
  dp[0][0] = 0;
  for (int i = 1; i <= limit; i++) {
    for (int j = 0; j < stations; j++) {
      for (int k = 0; k < stations; k++) {
        if (i - dist[k][j] < 0)
          continue;
        dp[j][i] = min(dp[j][i], dp[k][i - dist[k][j]] + risk[k][j]);
      }
    }
  }
  int minrisk = 1234567890, mindist = minrisk;
  for (int i = 0; i <= limit; i++)
    if (dp[stations - 1][i] < minrisk)
      minrisk = dp[stations - 1][mindist = i];
  if (minrisk >= 1000000)
    puts("-1");
  else
    printf("%d %d\n", minrisk, mindist);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  FPOLICE::solve();
  return 0;
}

