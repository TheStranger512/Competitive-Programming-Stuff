/* Solved
 * 9643. He is Lazy
 * Shortest Path
 * File:   HEISLAZY.cpp
 * Author: Andy Y.F. Huang
 * Created on September 27, 2012, 8:41 PM
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
namespace HEISLAZY {
int catas, sx, sy, ex, ey;
double dist[110], cost[110][110];
int cx[110], cy[110], range[110];

inline double sqr(double a) {
  return a * a;
}

inline double getdist(double x1, double y1, double x2, double y2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

void solve(int test_num) {
  for (int i = 0; i < catas; i++)
    scanf("%d %d %d", &cx[i], &cy[i], &range[i]);
  for (int i = 0; i < catas; i++) {
    for (int j = 0; j < catas; j++) {
      double temp = getdist(cx[i], cy[i], cx[j], cy[j]);
      cost[i][j] = min(temp, abs(temp - range[i]));
    }
  }
  queue<int> q;
  for (int i = 0; i < catas; i++) {
    dist[i] = getdist(sx, sy, cx[i], cy[i]); //start to all catapults
    q.push(i);
  }
  //plnarr(dist, dist + catas);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < catas; i++) {
      if (dist[cur] + cost[cur][i] < dist[i]) {
        dist[i] = dist[cur] + cost[cur][i];
        q.push(i);
      }
    }
  }
  double ans = getdist(sx, sy, ex, ey);
  for (int i = 0; i < catas; i++) {
    double temp = getdist(cx[i], cy[i], ex, ey);
    ans = min(ans, temp + dist[i]);
    ans = min(ans, abs(temp - range[i]) + dist[i]);
  }
  printf("%.2lf\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d %d %d %d %d", &catas, &sx, &sy, &ex, &ey);
    if (catas == -1)
      break;
    solve(1);
  }
}
}

int main() {
  HEISLAZY::solve();
  return 0;
}

