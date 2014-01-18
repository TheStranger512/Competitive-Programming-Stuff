/* Solved
 * 739. The Moronic Cowmpouter - weird math
 * File:   NEG2.cpp
 * Author: Andy Y.F. Huang
 * Created on August 30, 2012, 11:44 PM
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
namespace NEG2 {

void solve(int test_num) {
  int n, len = 0;
  char ans[1010];
  scanf("%d", &n);
  if (n == 0) {
    putchar('0');
    return;
  }
  while (n != 0) {
    if (n % 2 != 0)
      ans[len++] = '1', n--;
    else
      ans[len++] = '0';
    n /= -2;
  }
  while (len > 1 && ans[len - 1] == '0')
    len--;
  for (int i = len - 1; i >= 0; i--)
    putchar(ans[i]);
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
  NEG2::solve();
  return 0;
}

