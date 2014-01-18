/* Solved
 * 9655. Elevator Trouble
 * File:   ELEVTRBL.cpp
 * Author: Andy Y.F. Huang
 * Created on August 28, 2012, 10:11 PM
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
namespace ELEVTRBL {
int dist[1000010];
queue<int> q;

void solve(int test_num) {
  memset(dist, 0x3F, sizeof (dist));
  int floors, start, goal, up, down;
  scanf("%d %d %d %d %d", &floors, &start, &goal, &up, &down);
  dist[start] = 0;
  q.push(start);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur + up <= floors && dist[cur] + 1 < dist[cur + up])
      dist[cur + up] = dist[cur] + 1, q.push(cur + up);
    if (cur - down >= 1 && dist[cur] + 1 < dist[cur - down])
      dist[cur - down] = dist[cur] + 1, q.push(cur - down);
  }
  if (dist[goal] >= 1001200)
    puts("use the stairs");
  else
    printf("%d\n", dist[goal]);
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
  ELEVTRBL::solve();
  return 0;
}

