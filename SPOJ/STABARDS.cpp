/*
 * Solved
 * 3111. Stabards
 * File:   STABARDS.cpp
 * Author: Andy Y.F. Huang
 * Created on March 3, 2013, 11:24 AM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace STABARDS {
int genders, len;
char adj[111][111];
int gender[111];
const int k_max_len = 111;
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
  for (int i = 0; i < genders; i++)
    scanf("%s", adj[i]);
  for (int i = 0; i < len; i++)
    scanf("%d", gender + i);
  memset(degree, 0, sizeof (degree));
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (adj[gender[i]][gender[j]] == 'C')
        graph[i][degree[i]++] = j;
      else if (adj[gender[i]][gender[j]] == 'D')
        graph[j][degree[j]++] = i;
    }
  }
  printf("%d\n", maxMatching(len));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (true) {
    scanf("%d %d", &genders, &len);
    if (genders == 0 && len == 0)
      break;
    solve(1);
  }
}
}

int main() {
  STABARDS::solve();
  return 0;
}

