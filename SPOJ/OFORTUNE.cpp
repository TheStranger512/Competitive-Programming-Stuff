/* Solved
 * 1697. Ohgas' Fortune - math
 * File:   OFORTUNE.cpp
 * Author: Andy Y.F. Huang
 * Created on September 8, 2012, 9:06 PM
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
namespace OFORTUNE {

int compound(int start, int years, double rate, int charge) {
  int cur = start;
  for (int i = 0; i < years; i++) {
    cur += (int) (rate * cur);
    cur -= charge;
  }
  return cur;
}

int simple(int start, int years, double rate, int charge) {
  int interest = 0, cur = start;
  for (int i = 0; i < years; i++) {
    interest += (int) (rate * cur);
    cur -= charge;
  }
  return cur + interest;
}

void solve(int test_num) {
  int start, years, ops;
  scanf("%d %d %d", &start, &years, &ops);
  int best = start;
  for (int i = 0; i < ops; i++) {
    int type, charge;
    double rate;
    scanf("%d %lf %d", &type, &rate, &charge);
    if (type == 0)
      best = max(best, simple(start, years, rate, charge));
    else
      best = max(best, compound(start, years, rate, charge));
  }
  printf("%d\n", best);
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
  OFORTUNE::solve();
  return 0;
}

