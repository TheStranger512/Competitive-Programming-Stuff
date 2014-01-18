/* Solved
 * 12471. DIE HARD
 * File:   DIEHARD.cpp
 * Author: Andy Y.F. Huang
 * Created on November 22, 2012, 4:09 PM
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
namespace DIEHARD {

struct Node {
  int hp, armor, id;

  Node(int hp, int armor, int id) : hp(hp), armor(armor), id(id) { }
} ;
int dist[1555][1555][3];
const int dhp[] = {3, -5, -20}, dar[] = {2, -10, 5};

void solve(int test_num) {
  memset(dist, 0, sizeof (dist));
  int hp, armor, id;
  scanf("%d %d", &hp, &armor);
  queue<Node> q;
  for (int i = 0; i < 3; i++) {
    q.push(Node(hp, armor, i));
  }
  int ans = 0;
  while (!q.empty()) {
    hp = q.front().hp, armor = q.front().armor, id = q.front().id;
    q.pop();
    ans = max(ans, dist[hp][armor][id]);
    for (int i = 0; i < 3; i++) {
      if (i == id) continue;
      int nhp = hp + dhp[i], nar = armor + dar[i];
      if (nhp <= 0 || nar <= 0) continue;
      if (dist[hp][armor][id] + 1 > dist[nhp][nar][i]) {
        dist[nhp][nar][i] = dist[hp][armor][id] + 1;
        q.push(Node(nhp, nar, i));
      }
    }
  }
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
  DIEHARD::solve();
  return 0;
}

