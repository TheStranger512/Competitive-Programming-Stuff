/* Solved
 * 1419. A Game with Numbers - game theory - x % 10 == 0 is losing position
 * File:   NGM.cpp
 * Author: Andy Y.F. Huang
 * Created on August 30, 2012, 10:25 PM
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
namespace NGM {

void solve(int test_num) {
  int start;
  scanf("%d", &start);
  if (start % 10)
    printf("1\n%d", start % 10);
  else
    puts("2");
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
  NGM::solve();
  return 0;
}

