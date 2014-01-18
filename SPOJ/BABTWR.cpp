/* Solved
 * 100. Tower of Babylon
 * File:   BABTWR.cpp
 * Author: Andy Y.F. Huang
 * Created on August 31, 2012, 1:47 AM
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
namespace BABTWR {

struct Block {
  int x, y, z;

  friend ostream& operator<<(ostream& out, const Block & b) {
    return out << '(' << b.x << ',' << b.y << ',' << b.z << ')';
  }

} ;

Block blocks[200];
int last[200], to[40000], next[40000], cost[40000], index = 0;
int dist[200], types;

void dfs(int cur) {
  for (int id = last[cur]; id != -1; id = next[id]) {
    if (dist[cur] + cost[id] < dist[to[id]]) {
      dist[to[id]] = dist[cur] + cost[id];
      dfs(to[id]);
    }
  }
}

void solve(int test_num) {
  index = 0;
  memset(last, 0xFF, sizeof (last));
  memset(dist, 0, sizeof (dist));
  int len = 0, order[3], ans = 0;
  for (int i = 0; i < types; i++) {
    int dims[3];
    scanf("%d %d %d", &dims[0], &dims[1], &dims[2]);
    order[0] = 0, order[1] = 1, order[2] = 2;
    do {
      blocks[len].x = dims[order[0]];
      blocks[len].y = dims[order[1]];
      blocks[len++].z = dims[order[2]];
    } while (next_permutation(order, order + 3));
  }
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (blocks[i].x > blocks[j].x && blocks[i].y > blocks[j].y) {
        to[index] = j;
        next[index] = last[i];
        cost[index] = -blocks[i].z; //negate edges to find longest path
        last[i] = index++;
      }
    }
  }
  for (int i = 0; i < len; i++)
    if (dist[i] == 0)
      dfs(i);
  for (int i = 0; i < len; i++)
    ans = max(ans, -dist[i] + blocks[i].z);
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d", &types);
    if (types == 0)
      break;
    solve(1);
  }
}
}

int main() {
  BABTWR::solve();
  return 0;
}

