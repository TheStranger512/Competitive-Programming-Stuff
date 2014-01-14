/* Solved
 * Hermes - dp
 * File:   ioi0411.cpp
 * Author: Andy Y.F. Huang
 * Created on July 19, 2012, 12:38 AM
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
namespace ioi0411 {
const int k_maxlen = 20010, k_maxcoord = 2010;
int x[k_maxlen], y[k_maxlen];
int preva[k_maxcoord] = {0}, prevb[k_maxcoord] = {0};
int dpx[k_maxcoord], dpy[k_maxcoord];
//a[c] - end up at x[i], c after alinging i points
//b[c] - end up at c, y[i] ""       ""    "  ""

inline int dist(int i, int j)  {
  return abs(i - j);
}

inline int min(int i, int j) {
  return i < j ? i : j;
}

void solve(const int test_num) {
  int len;
  scanf("%d", &len);
  x[0] = 1000, y[0] = 1000;
  for (int i = 1; i <= len; i++) {
    scanf("%i %i", &x[i], &y[i]);
    x[i] += 1000, y[i] += 1000;
  }
  for (int c = 0; c < k_maxcoord; c++) {
    preva[c] = dist(c, y[0]);
    prevb[c] = dist(c, x[0]);
  }
  for (int i = 1; i <= len; i++) {
    for (int c = 0; c < k_maxcoord; c++) {
      dpx[c] = min(prevb[x[i]] + dist(y[i - 1], c), preva[c] + dist(x[i - 1], x[i]));
      dpy[c] = min(preva[y[i]] + dist(x[i - 1], c), prevb[c] + dist(y[i - 1], y[i]));
    }
    memcpy(preva, dpx, sizeof (dpx));
    memcpy(prevb, dpy, sizeof (dpy));
  }
  int ans = 1 << 25;
  for (int c = 0; c < k_maxcoord; c++) {
    ans = min(ans, dpx[c]);
    ans = min(ans, dpy[c]);
  }
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}

} ;

int main() {
  ioi0411::solve();
  return 0;
}

