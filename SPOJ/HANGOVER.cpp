/* Solved
 * 902. Hangover - simple iteration
 * File:   HANGOVER.cpp
 * Author: Andy Huang
 * Created on May 26, 2012, 10:35 AM
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

void solve(float len) {
  float cur = 0.0;
  int cards = 0;
  while (cur < len){
    cards++;
    cur += 1.0 / (cards + 1);
  }
  printf("%d card(s)\n", cards);
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  float len;
  while (scanf("%f", &len)){
    if (len == 0)
      break;
    solve(len);
  }
  return 0;
}

