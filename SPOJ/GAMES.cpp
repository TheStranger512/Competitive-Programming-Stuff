/* Solved
 * 12448. HOW MANY GAMES
 * File:   GAMES.cpp
 * Author: Andy Y.F. Huang
 * Created on October 20, 2012, 3:20 PM
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
namespace GAMES {
char avg[25];

void solve(int test_num) {
  scanf("%s", avg);
  char* dot = strchr(avg, '.');
  if (dot == NULL) {
    puts("1");
    return;
  }
  int num = atoi(dot + 1), den = 1, digits = strlen(dot + 1);
  for (int i = 0; i < digits; i++)
    den *= 10;
  den /= __gcd(den, num);
  printf("%d\n", den);
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
  GAMES::solve();
  return 0;
}

