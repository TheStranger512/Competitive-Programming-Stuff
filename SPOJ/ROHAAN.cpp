/* Solved
 * 15285. Defend The Rohan
 * File:   ROHAAN.cpp
 * Author: Andy Y.F. Huang
 * Created on July 23, 2013, 12:30 AM
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

namespace ROHAAN {
int dist[50][50];

void solve(int test_num) {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      scanf("%d", dist[i] + j);
  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  int Q, res = 0;
  scanf("%d", &Q);
  for (int q = 0, a, b; q < Q; q++) {
    scanf("%d %d", &a, &b);
    res += dist[--a][--b];
  }
  printf("Case #%d: %d\n", test_num, res);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  ROHAAN::solve();
  return 0;
}

