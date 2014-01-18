/* Solved
 * 13091. Snakes and Ladders
 * File:   PCPC12E.cpp
 * Author: Andy Y.F. Huang
 * Created on December 28, 2012, 6:37 PM
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
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <cstddef>
#include <utility>
#include <valarray>
#include <cstdlib>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace PCPC12E {
int rows, cols, snakes, ladders;
int dist[11111], to[11111];

void solve(int test_num) {
  memset(dist, 0x3F, sizeof (dist));
  memset(to, 0xFF, sizeof (to));
  dist[0] = 0;
  for (int s = 0; s < snakes; s++) {
    int a, b;
    scanf("%d %d", &a, &b);
    to[a] = b;
  }
  for (int l = 0; l < ladders; l++) {
    int a, b;
    scanf("%d %d", &a, &b);
    to[a] = b;
  }
  queue<int> q;
  q.push(0);
  for (; !q.empty(); q.pop()) {
    int cur = q.front();
    if (to[cur] > 0) {
      if (dist[cur] < dist[to[cur]]) {
        dist[to[cur]] = dist[cur];
        q.push(to[cur]);
      }
      dist[cur] = 1 << 30;
      continue;
    }
    for (int s = 1; s <= 6; s++) {
      if (cur + s <= rows * cols && dist[cur] + 1 < dist[cur + s]) {
        dist[cur + s] = dist[cur] + 1;
        q.push(cur + s);
      }
    }
  }
  printf("%d\n", dist[rows * cols] > 1e6 ? -1 : dist[rows * cols]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (scanf("%d %d %d %d", &rows, &cols, &snakes, &ladders) != EOF)
    solve(1);
}
}

int main() {
  PCPC12E::solve();
  return 0;
}

