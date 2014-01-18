/* Solved
 * 9969. Road Network
 * File:   RDNWK.cpp
 * Author: Andy Y.F. Huang
 * Created on September 30, 2012, 5:26 PM
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

namespace RDNWK {
int dist[151][150][150];

void solve(int test_num) {
  int size;
  memset(dist, 0x3F, sizeof (dist));
  scanf("%d", &size);
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      scanf("%d", &dist[0][i][j]);
      if (dist[0][i][j] == -1)
        dist[0][i][j] = 0x3F3F3F3F;
      dist[0][j][i] = dist[0][i][j];
    }
    dist[0][i][i] = 0;
  }
  //plnarr(dist[0], size, size);
  int rankcnt;
  scanf("%d", &rankcnt);
  for (int i = 1, best; i <= rankcnt; i++) {
    scanf("%d", &best);
    best--;
    for (int a = 0; a < size; a++)
      for (int b = 0; b < size; b++) {
        dist[i][a][b] = min(dist[i][a][b], dist[i - 1][a][best] + dist[i - 1][best][b]);
        dist[i][a][b] = min(dist[i][a][b], dist[i - 1][a][b]);
      }
  }
  int quests;
  scanf("%d", &quests);
  printf("Case %d:", test_num);
  for (int q = 0; q < quests; q++) {
    int k, src, dest;
    scanf("%d %d %d", &k, &src, &dest);
    int res = dist[k][--src][--dest];
    printf(" %d", res > (1 << 29) ? -1 : res);
  }
  putchar('\n');
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
  RDNWK::solve();
  return 0;
}

