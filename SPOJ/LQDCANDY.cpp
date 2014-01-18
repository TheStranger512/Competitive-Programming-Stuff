/* Solved
 * 8995. CANDY
 * File:   LQDCANDY.cpp
 * Author: Andy Y.F. Huang
 * Created on September 22, 2012, 11:35 PM
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
namespace LQDCANDY {

void solve(int test_num) {
  unsigned long long n;
  scanf("%llu", &n);
  int len;
  for (len = 63; ; len--)
    if (1LLu << len & n)
      break;
  len++;
  for (int i = 0; i < len - 1; i++) {
    if (1LLu << i & n) {
      printf("%llu %d\n", 1LLu << len, len - i);
      return;
    }
  }
  len--;
  printf("%llu 0\n", 1LLu << len);
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
  LQDCANDY::solve();
  return 0;
}

