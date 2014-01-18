/* Solved
 * 10084. Fake Scoreboard
 * File:   FAKESCOR.cpp
 * Author: Andy Y.F. Huang
 * Created on May 22, 2013, 7:14 PM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

namespace FAKESCOR {
int cap[162][162], flow[162][162];
int q[165], prev[165];
int src, sink;
int teams, probs;

int augment() {
  memset(prev, -1, sizeof (prev));
  int qf = 0, qb = 0;
  q[qb++] = src;
  prev[src] = -2;
  for (int at, i; qf < qb; qf++)
    for (at = q[qf], i = 0; i <= sink; i++)
      if (flow[at][i] < cap[at][i] && prev[i] == -1)
        prev[q[qb++] = i] = at;
  if (prev[sink] == -1) return 0;
  for (int u = prev[sink], v = sink; u >= 0; v = u, u = prev[u]) {
    flow[u][v]++;
    flow[v][u]--;
  }
  return 1;
}

int maxflow() {
  int res = 0, t;
  while (true) {
    t = augment();
    if (t == 0) break;
    res += t;
  }
  return res;
}

void solve(int test_num) {
  memset(cap, 0, sizeof (cap));
  memset(flow, 0, sizeof (flow));
  src = teams + probs;
  sink = src + 1;
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < teams; i++) {
    scanf("%d", &cap[src][i]);
    sum1 += cap[src][i];
  }
  for (int j = 0; j < probs; j++) {
    scanf("%d", &cap[j + teams][sink]);
    sum2 += cap[j + teams][sink];
  }
  for (int i = 0; i < teams; i++)
    for (int j = 0; j < probs; j++)
      cap[i][j + teams] = 1;

  if (sum1 != sum2 || maxflow() != sum1) {
    puts("Impossible\n");
    return;
  }
  int total = 0, last = sum1;
  for (int i = 0; i < teams; i++) {
    for (int j = 0; j < probs; j++) {
      cap[i][j + teams] = 0;
      if (flow[i][j + teams] == 1) {
        //assert(flow[src][i] > 0 && flow[j + teams][sink] > 0);
        flow[i][j + teams]--;
        flow[src][i]--;
        flow[j + teams][sink]--;
        last--;
        last += augment();
      }
      if (total + last < sum1) {
        putchar('Y');
        total++;
        cap[j + teams][sink]--;
      }
      else putchar('N');
    }
    putchar('\n');
  }
  puts("");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d", &teams, &probs) != EOF)
    if (teams + probs > 0)
      solve(1);
}
}

int main() {
  FAKESCOR::solve();
  return 0;
}

