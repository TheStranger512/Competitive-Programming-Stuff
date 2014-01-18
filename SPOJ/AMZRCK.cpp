/* Solved
 * 11932. Amz Rock
 * File:   AMZRCK.cpp
 * Author: Andy Y.F. Huang
 * Created on August 6, 2012, 12:40 AM
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
namespace AMZRCK {
int fib[50];
void init() {
  fib[0] = 1, fib[1] = 2;
  for (int i = 2; i < 50; i++)
    fib[i] = fib[i - 2] + fib[i - 1];
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  init();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++) {
    int n;
    scanf("%d", &n);
    printf("%d\n", fib[n]);
  }
}
}

int main() {
  AMZRCK::solve();
  return 0;
}

