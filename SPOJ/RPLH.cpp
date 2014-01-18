/* Solved
 * 11494. Hard Launching - math
 * File:   RPLH.cpp
 * Author: Andy Huang
 * Created on May 7, 2012, 12:51 AM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
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

using namespace std;

const double g = 9.806;
const double PI = 3.14159;

void solve() {
  int dist, vi;
  scanf("%d %d", &dist, &vi);
  double maxtime = 2.0 * vi * sin(PI / 4.0) / g;
  if (maxtime * vi * cos(PI / 4.0) < dist) {
    puts("-1");
    return;
  }
  printf("%.2f\n", asin(g * dist / (vi * vi)) * 90.0 / PI);
}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int cases = 1; cases <= tests; cases++) {
    printf("Scenario #%d: ", cases);
    solve();
  }
  return 0;
}

