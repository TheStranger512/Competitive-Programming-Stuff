/* Solved
 * 2524. Conversions - simple math
 * File:   GNY07B.cpp
 * Author: Andy Huang
 * Created on May 21, 2012, 6:17 PM
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
  float val;
  char str[10];
  double ans = 0.0;
  scanf("%f %s", &val, str);
  const char *unit;
  if (strcmp(str, "kg") == 0){
    ans = val * 2.2046;
    unit = "lb";
  }
  else if (strcmp(str, "l") == 0){
    ans = val * 0.2642;
    unit = "g";
  }
  else if (strcmp(str, "lb") == 0){
    ans = val * 0.4536;
    unit = "kg";
  }
  else{
    ans = val * 3.7854;
    unit = "l";
  }
  printf("%.4f %s\n", ans, unit);
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++){
    printf("%d ", i);
    solve();
  }
  return 0;
}

