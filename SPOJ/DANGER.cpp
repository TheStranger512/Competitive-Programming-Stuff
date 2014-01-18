/* Solved
 * 1786. In Danger
 * File:   DANGER.cpp
 * Author: Andy Y.F. Huang
 * Created on August 27, 2012, 11:42 PM
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
namespace DANGER {

void solve(int test_num, const char* str) {
  int num = (str[0] - '0') * 10 + (str[1] - '0');
  for (int i = 0; i < str[3] - '0'; i++)
    num *= 10;
  for (int bit = 30; bit >= 0; bit--) {
    if (1 << bit & num) {
      printf("%d\n", 2 * (num - (1 << bit)) + 1);
      return;
    }
  }
  assert(false);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    char str[10];
    scanf("%s", str);
    if (strcmp(str, "00e0") == 0)
      break;
    solve(1, str);
  }
}
}

int main() {
  DANGER::solve();
  return 0;
}

