/* Solved
 * 3753. GONDOR - true dijkstras
 * File:   GONDOR.cpp
 * Author: Andy Y.F. Huang
 * Created on September 4, 2012, 4:58 PM
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
namespace GONDOR {

struct Node {
  int cur;
  double dist;

  Node(int cur, double dist) : cur(cur), dist(dist) { }

  bool operator<(const Node & n) const {
    return dist > n.dist;
  }
} ;

int x[110], y[110], to[110][110], arrows[110];
priority_queue<Node> q;
bool lit[110] = {false};
double reached[110];

inline double getdist(int i, int j) {
  return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

void solve(int test_num) {
  int sparks;
  scanf("%d", &sparks);
  for (int i = 0; i < sparks; i++) {
    reached[i] = 1e10;
    scanf("%d %d %d", &x[i], &y[i], &arrows[i]);
    for (int j = 0; j < sparks - 1; j++) {
      scanf("%d", &to[i][j]);
      to[i][j]--;
    }
  }
  q.push(Node(0, 0));
  while (!q.empty()) {
    int cur = q.top().cur;
    double cdist = q.top().dist;
    q.pop();
    if (lit[cur])
      continue;
    reached[cur] = cdist;
    lit[cur] = true;
    for (int i = 0; i < sparks - 1 && arrows[cur] > 0; i++)
      if (!lit[to[cur][i]])
        q.push(Node(to[cur][i], cdist + getdist(cur, to[cur][i]))), arrows[cur]--;
  }
  for (int i = 0; i < sparks; i++)
    printf("%.6lf\n", reached[i]);
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
  GONDOR::solve();
  return 0;
}

