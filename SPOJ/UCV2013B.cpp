/* Solved
 * 15430. Alice in Amsterdam, I mean Wonderland
 * File:   UCV2013B.cpp
 * Author: Andy Y.F. Huang
 * Created on July 29, 2013, 3:33 AM
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

namespace UCV2013B {
#define INF 0x3ffffff7
int N;
int g[111][111];
char name[111][25];

void solve(int test_num) {
  if (N == 0)
    return;
  for (int i = 0; i < N; i++) {
    scanf("%s", name[i]);
    for (int j = 0; j < N; j++) {
      scanf("%d", g[i] + j);
      if (g[i][j] == 0)
        g[i][j] = INF;
    }
  }
  for (int i = 0; i < N; i++)
    if (g[i][i] > 0)
      g[i][i] = 0;
  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        if (g[i][k] != INF && g[k][j] != INF)
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  int Q;
  scanf("%d", &Q);
  printf("Case #%d:\n", test_num);
  for (int q = 0, a, b; q < Q; q++) {
    scanf("%d %d", &a, &b);
    bool bad = false;
    for (int k = 0; k < N; k++) {
      if (g[k][k] < 0 && g[a][k] != INF) {
        puts("NEGATIVE CYCLE");
        bad = true;
        break;
      }
    }
    if (!bad) {
      printf("%s-%s ", name[a], name[b]);
      if (g[a][b] >= INF)
        puts("NOT REACHABLE");
      else
        printf("%d\n", g[a][b]);
    }
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  for (int t = 1; scanf("%d", &N) != EOF; t++)
    solve(t);
}
}

int main() {
  UCV2013B::solve();
  return 0;
}

