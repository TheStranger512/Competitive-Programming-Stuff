/* Solved
 * 1417. University Employees - A+B
 * File:   EMP.cpp
 * Author: Andy Huang
 * Created on May 21, 2012, 5:53 PM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
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

#ifdef AZN
#include "Azn.cpp"
#define pln(x) println(x)
#define pf(x) print(x);
#endif

using namespace std;

void solve() {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", a + b);
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}

