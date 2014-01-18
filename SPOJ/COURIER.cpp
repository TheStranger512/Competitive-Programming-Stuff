/* Solved
 * 151. The Courier
 * File:   COURIER.cpp
 * Author: Andy Y.F. Huang
 * Created on August 28, 2012, 1:03 PM
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
namespace COURIER {
int graph[110][110];
int start[15], end[15], cities, parcels;
int dp[1 << 12][110];

int mindist(int mask, int pos) {
  if (dp[mask][pos] != -1)
    return dp[mask][pos];
  dp[mask][pos] = 1 << 30;
  for (int i = 0; i < parcels; i++) {
    if (1 << i & mask) {
      int delivcost = graph[start[i]][end[i]];
      for (int j = 0; j < parcels; j++)
        dp[mask][pos] = min(dp[mask][pos], mindist(1 << i ^ mask, start[j])
                            + graph[start[j]][start[i]] + delivcost
                            + graph[end[i]][pos]);
      for (int j = 0; j < parcels; j++)
        dp[mask][pos] = min(dp[mask][pos], mindist(1 << i ^ mask, end[j])
                            + graph[end[j]][start[i]] + delivcost
                            + graph[end[i]][pos]);
    }
  }
  return dp[mask][pos];
}

void solve(int test_num) {
  memset(graph, 0x3F, sizeof (graph));
  memset(dp, 0xFF, sizeof (dp));
  parcels = 0;
  int first, roads, requests;
  scanf("%d %d %d", &cities, &roads, &first);
  --first;
  for (int i = 0; i < cities; i++)
    graph[i][i] = 0;
  for (int i = 0; i < roads; i++) {
    int from, to, dist;
    scanf("%d %d %d", &from, &to, &dist);
    --from, --to;
    graph[from][to] = min(graph[from][to], dist);
    graph[to][from] = graph[from][to];
  }
  scanf("%d", &requests);
  for (int i = 0; i < requests; i++) {
    int from, to, amount;
    scanf("%d %d %d", &from, &to, &amount);
    --from, --to;
    for (int j = 0; j < amount; j++)
      start[parcels] = from, end[parcels++] = to;
  }
  for (int k = 0; k < cities; k++)
    for (int i = 0; i < cities; i++)
      for (int j = 0; j < cities; j++)
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
  for (int i = 0; i < cities; i++)
    dp[0][i] = graph[first][i]; //base cases
  printf("%d\n", mindist((1 << parcels) - 1, first));
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
  COURIER::solve();
  return 0;
}

