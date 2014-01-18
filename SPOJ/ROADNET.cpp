/* Solved
 * 178. Road net - floyd-warshall
 * File:   ROADNET.cpp
 * Author: Andy Y.F. Huang
 * Created on August 31, 2012, 1:27 AM
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
namespace ROADNET {
int dist[210][210];
bool good[210][210];

void solve(int test_num) {
  int towns;
  scanf("%d", &towns);
  for (int i = 1; i <= towns; i++)
    for (int j = 1; j <= towns; j++)
      scanf("%d", &dist[i][j]), good[i][j] = true;
  for (int k = 1; k <= towns; k++)
    for (int i = 1; i <= towns; i++)
      for (int j = 1; j <= towns; j++)
        if (i != j && i != k && j != k && dist[i][k] + dist[k][j] == dist[i][j])
          good[i][j] = false;
  for (int i = 1; i <= towns; i++)
    for (int j = i + 1; j <= towns; j++)
      if (good[i][j])
        printf("%d %d\n", i, j);
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
  ROADNET::solve();
  return 0;
}

