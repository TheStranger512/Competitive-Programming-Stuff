/* Solved
 * 12959. Basic Grapes Instinct
 * File:   VPL0_B.cpp
 * Author: Andy Y.F. Huang
 * Created on December 10, 2012, 9:01 PM
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
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace VPL0_B {
vector<int> plot[1111];

int digitlen(int i) {
  return i < 10 ? 1 : i < 100 ? 2 : i < 1000 ? 3 : 4;
}

void solve(int test_num) {
  int len, stem;
  for (int i = 0; i <= 1000; i++)
    plot[i].clear();
  scanf("%d %d", &len, &stem);
  for (int i = 0; i < len; i++) {
    int val;
    scanf("%d", &val);
    plot[val / stem].push_back(val % stem);
  }
  printf("Scenario #%d:\n\n", test_num);
  int maxlen = 0;
  for (int i = 0; i <= 1000; i++)
    if (plot[i].size())
      maxlen = max(maxlen, digitlen(i));
  for (int i = 0; i <= 1000; i++) {
    if (plot[i].size()) {
      for (int j = 0; j < maxlen - digitlen(i); j++)
        putchar(' ');
      sort(plot[i].begin(), plot[i].end());
      printf("%d |", i);
      for (int j = 0; j < (int) plot[i].size(); j++)
        printf(" %d", plot[i][j]);
      puts("\n");
    }
  }
  putchar('\n');
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
  VPL0_B::solve();
  return 0;
}

