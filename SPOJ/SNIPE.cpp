/*
 * Solved
 * 10421. Run, Snipe, Run
 * File:   SNIPE.cpp
 * Author: Andy Y.F. Huang
 * Created on January 19, 2013, 1:38 PM
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
namespace SNIPE {
const int k_max_len = 1010;
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
  int matches = 0;
  for (int i = 0; i < guys; i++) {
    memset(seen, false, sizeof (seen));
    if (matchLeft[i] != -1)
      matches++;
    else
      matches += canMatch(i);
  }
  return matches;
}

int len;
pair<int, int> pts[1111];//(east, north)

void solve(int test_num) {
  memset(matchLeft, 0xFF, sizeof (matchLeft));
  memset(matchRight, 0xFF, sizeof (matchRight));
  memset(degree, 0, sizeof (degree));
  for (int i = 0; i < len; i++)
    scanf("%d %d", &pts[i].first, &pts[i].second);
  sort(pts, pts + len);
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < i; j++) {
      if (pts[j].first <= pts[i].first && pts[j].second <= pts[i].second) {
        graph[j][degree[j]++] = i;
        if (matchLeft[j] == -1 && matchRight[i] == -1) {
          matchLeft[j] = i;
          matchRight[i] = j;
        }
      }
    }
  }
  printf("%d\n", len - maxMatching(len));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (true) {
    scanf("%d", &len);
    if (len == 0) break;
    solve(1);
  }
}
}

int main() {
  SNIPE::solve();
  return 0;
}

