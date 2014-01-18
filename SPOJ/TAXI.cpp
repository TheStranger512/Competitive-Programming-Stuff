/* Solved
 * 377. Taxi
 * File:   TAXI.cpp
 * Author: Andy Y.F. Huang
 * Created on July 31, 2012, 4:17 PM
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
namespace TAXI {
const int k_max_len = 410;
int matchLeft[k_max_len], matchRight[k_max_len];
bool seen[k_max_len];
int graph[k_max_len][k_max_len], degree[k_max_len];

bool canMatch(int guy) {
  for (int i = 0; i < degree[guy]; i++) {
    if (seen[graph[guy][i]])
      continue;
    int girl = graph[guy][i];
    seen[girl] = true;
    if (matchRight[girl] < 0 || canMatch(matchRight[girl])) {
      matchLeft[guy] = girl;
      matchRight[girl] = guy;
      return true;
    }
  }
  return false;
}

int maxMatching(int guys) {
  memset(matchLeft, 0xFF, sizeof (matchLeft));
  memset(matchRight, 0xFF, sizeof (matchRight));
  int matches = 0;
  for (int i = 0; i < guys; i++) {
    memset(seen, false, sizeof (seen));
    matches += canMatch(i);
  }
  return matches;
}

void solve(int test_num) {
  memset(degree, 0, sizeof (degree));
  int ppl, taxis, speed, limit, px[k_max_len], py[k_max_len];
  scanf("%d %d %d %d", &ppl, &taxis, &speed, &limit);
  for (int i = 0; i < ppl; i++)
    scanf("%d %d", &px[i], &py[i]);
  for (int i = 0; i < taxis; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    for (int j = 0; j < ppl; j++) {
      int dist = abs(px[j] - x) + abs(py[j] - y);
      if (dist * 200 <= speed * limit)
        graph[i][degree[i]++] = j;
    }
  }
  printf("%d\n", maxMatching(taxis));
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
  TAXI::solve();
  return 0;
}

