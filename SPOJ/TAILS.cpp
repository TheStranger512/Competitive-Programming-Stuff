/* Solved
 * 8594. Tails all the way
 * File:   TAILS.cpp
 * Author: Andy Y.F. Huang
 * Created on October 23, 2012, 8:31 PM
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

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace TAILS {
int dist[1 << 20];
queue<int> q;

void solve(int test_num) {
  memset(dist, 0x3F, sizeof (dist));
  int bit, start = 0;
  for (int i = 19; i >= 0; i--) {
    scanf("%d", &bit);
    start |= bit << i;
  }
  //printf("%x\n", start);
  //3 << 18 = 786432
  dist[start] = 0;
  q.push(start);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur == 0)
      break;
    if (dist[cur] + 1 < dist[cur ^ 3]) {
      dist[cur ^ 3] = dist[cur] + 1;
      q.push(cur ^ 3);
    }
    if (dist[cur] + 1 < dist[786432 ^ cur]) {
      dist[786432 ^ cur] = dist[cur] + 1;
      q.push(786432 ^ cur);
    }
    for (int bit = 0; bit < 18; bit++) {
      if (dist[cur] + 1 < dist[7 << bit ^ cur]) {
        dist[7 << bit ^ cur] = dist[cur] + 1;
        q.push(7 << bit ^ cur);
      }
    }
  }
  printf("%d\n", dist[0]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  TAILS::solve();
  return 0;
}

