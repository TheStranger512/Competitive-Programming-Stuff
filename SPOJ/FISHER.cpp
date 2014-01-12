/* Solved
 * 101. Fishmonger
 * File:   FISHER.cpp
 * Author: Andy Y.F. Huang
 * Created on August 9, 2012, 3:31 PM
 */

#include <cstdio>
#include <queue>
#include <cstring>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace FISHER {

struct Node {
  int cur, dist, toll;

  Node(int cur, int dist, int toll) : cur(cur), dist(dist), toll(toll) {
  }

  bool operator<(const Node & n) const {
    if (toll != n.toll)
      return toll > n.toll;
    return dist > n.dist;
  }
} ;

const int k_max_size = 55;
int cost[k_max_size][k_max_size], toll[k_max_size][k_max_size];
int dp[k_max_size][1010]; //i, j - minimum toll to get to town i at time j

void solve(int test_num, int towns, int limit) {
  for (int i = 0; i < towns; i++)
    for (int j = 0; j < towns; j++)
      scanf("%d", &cost[i][j]);
  for (int i = 0; i < towns; i++)
    for (int j = 0; j < towns; j++)
      scanf("%d", &toll[i][j]);
  memset(dp, 0x3F, sizeof (dp));
  dp[0][0] = 0;
  for (int j = 0; j <= limit; j++) {
    for (int i = 0; i < towns; i++) {
      for (int k = 0; k < towns; k++) {
        if (j - cost[k][i] < 0)
          continue;
        dp[i][j] = min(dp[i][j], dp[k][j - cost[k][i]] + toll[k][i]);
      }
    }
  }
  int mintoll = 123456789;
  int mintime = mintoll;
  for (int j = 0; j <= limit; j++) {
    if (dp[towns - 1][j] < mintoll) {
      mintoll = dp[towns - 1][j];
      mintime = j;
    }
  }
  printf("%d %d\n", mintoll, mintime);
}

//void makeCase() {
//  freopen("input.txt", "w", stdout);
//  srand(time(NULL));
//  int n = rand() % 50, t = rand() % 1000 + 1;
//  printf("%d %d\n", n, t);
//  for (int k = 0; k < 2; k++) {
//    for (int i = 0; i < n; i++) {
//      for (int j = 0; j < n; j++) {
//        if (i == j)
//          printf("0 ");
//        else
//          printf("%d ", rand() % 100);
//      }
//      putchar('\n');
//    }
//    putchar('\n');
//  }
//  puts("0 0");
//}

void solve() {
  #ifdef AZN
  //makeCase();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    int towns, limit;
    scanf("%d %d", &towns, &limit);
    if (towns == 0 && limit == 0)
      break;
    solve(1, towns, limit);
  }
}
}

int main() {
  FISHER::solve();
  return 0;
}

