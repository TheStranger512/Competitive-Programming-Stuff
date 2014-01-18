/*
 * Solved
 * 13042. Gandalf vs the Balrog
 * File:   AMR12B.cpp
 * Author: Andy Y.F. Huang
 * Created on January 25, 2013, 5:42 PM
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
namespace AMR12B {
int outdeg[1 << 20], indeg[1 << 20];

void solve(int test_num) {
  int moves, edges, x, y;
  scanf("%d %d", &moves, &edges);
  for (int i = 1; i <= moves; i++)
    indeg[i] = outdeg[i] = 0;
  for (int e = 0; e < edges; e++) {
    scanf("%d %d", &x, &y);
    outdeg[x]++;
    indeg[y]++;
  }
  for (int m = moves; m >= 1; m--) {
    if (outdeg[m] == moves - m && indeg[m] == 0) {
      printf("2 %d\n", m);
      return;
    }
  }
  puts("1");
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
  AMR12B::solve();
  return 0;
}

