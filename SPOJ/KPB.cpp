/* Solved
 * 12071. Point Blank - math, probabilities
 * File:   KPB.cpp
 * Author: Andy Y.F. Huang
 * Created on August 30, 2012, 11:28 PM
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
namespace KPB {
int pos[25];

void solve(int test_num) {
  int players, rounds;
  double ans = 0;
  scanf("%d %d", &players, &rounds);
  for (int i = 0; i < rounds; i++) {
    int sum = 0;
    for (int j = 0; j < players; j++) {
      scanf("%d", &pos[j]);
      sum += pos[j];
    }
    double prob = 1.0 * sum / players / 100.0;
    double orig = prob;
    for (int i = 1; i < players; i++)
      prob *= orig;
    ans += prob;
  }
  printf("%.6lf\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  KPB::solve();
  return 0;
}

