/*
 * Solved
 * 7556. B - Stock Charts
 * File:   HASTOCK.cpp
 * Author: Andy Y.F. Huang
 * Created on January 24, 2013, 7:48 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace HASTOCK {
const int k_max_len = 110;
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

int price[111][111];

void solve(int test_num) {
  memset(degree, 0, sizeof (degree));
  int len, pts;
  scanf("%d %d", &len, &pts);
  for (int i = 0; i < len; i++)
    for (int x = 0; x < pts; x++)
      scanf("%d", &price[i][x]);
  for (int i = 0; i < len; i++)
    for (int j = 0; j < len; j++) {
      bool ok = true;
      for (int x = 0; x < pts; x++)
        if (price[j][x] <= price[i][x])
          ok = false;
      if (ok) graph[i][degree[i]++] = j;
    }
  printf("Case #%d: %d\n", test_num, len - maxMatching(len));
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
  HASTOCK::solve();
  return 0;
}

