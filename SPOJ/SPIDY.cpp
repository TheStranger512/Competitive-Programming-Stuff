/* Solved
 * 12249. Spiderman vs Sandman - bfs
 * File:   SPIDY.cpp
 * Author: Andy Y.F. Huang
 * Created on September 22, 2012, 1:11 PM
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
namespace SPIDY {

struct Node {
  int side, high;

  Node(int side, int high) : side(side), high(high) { }
} ;

const int k_inf = 12345678;
int height, jumplen;
char build[2][100010];
int dist[2][100010];
queue<Node> q;

void solve(int test_num) {
  scanf("%d %d %s%s", &height, &jumplen, build[0], build[1]);
  memset(dist, 0x3F, sizeof (dist));
  q.push(Node(0, 0));
  dist[0][0] = 0;
  while (!q.empty()) {
    int side = q.front().side, high = q.front().high, cdist = dist[side][high];
    q.pop();
    if (cdist > high) {
      dist[side][high] = k_inf;
      continue;
    }
    int up = high + 1;
    if (up >= height) {
      dist[0][height] = dist[1][height] = cdist + 1;
      break;
    }
    if (build[side][up] != 'X' && cdist + 1 < dist[side][up]) {
      dist[side][up] = cdist + 1;
      q.push(Node(side, up));
    }
    int down = high - 1;
    if (down >= 0 && build[side][down] != 'X' && cdist + 1 < dist[side][down]) {
      dist[side][down] = cdist + 1;
      q.push(Node(side, down));
    }
    int nhigh = high + jumplen;
    if (nhigh >= height)  {
      dist[0][height] = dist[1][height] = cdist + 1;
      break;
    }
    if (build[side ^ 1][nhigh] != 'X' && cdist + 1 < dist[side ^ 1][nhigh]) {
      dist[side ^ 1][nhigh] = cdist + 1;
      q.push(Node(side ^ 1, nhigh));
    }
  }
  int ans = min(dist[0][height], dist[1][height]);
  if (ans >= k_inf)
    puts("NO");
  else
    printf("%d\n", ans);
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
  SPIDY::solve();
  return 0;
}

