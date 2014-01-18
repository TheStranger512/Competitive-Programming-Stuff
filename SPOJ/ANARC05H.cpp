/* Solved
 * 4564. Chop Ahoy! Revisited! - recursion / dp
 * File:   ANARC05H.cpp
 * Author: Andy Y.F. Huang
 * Created on September 11, 2012, 9:48 PM
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
namespace ANARC05H {
char str[50];
int len;

int rec(int pos, int prev) {
  if (pos == len)
    return 1;
  int ans = 0, sum = 0;
  for (int i = pos; i < len; i++) {
    sum += str[i] - '0';
    if (sum >= prev)
      ans += rec(i + 1, sum);
  }
  return ans;
}

void solve(int test_num) {
  len = strlen(str);
  printf("%d. %d\n", test_num, rec(0, 0));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  for (int i = 1; ; i++) {
    scanf("%s", str);
    if (str[0] == 'b')
      break;
    solve(i);
  }
}
}

int main() {
  ANARC05H::solve();
  return 0;
}

