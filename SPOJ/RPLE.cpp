/* Solved
 * 11375. Espionage - simple graph theory
 * File:   RPLE.cpp
 * Author: Andy Huang
 * Created on May 7, 2012, 1:47 PM
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

using namespace std;

unsigned char ppl[1050]; // 0 - no-one, 1 - spy, 2 - spied on

void solve() {
  int vertices, edges;
  scanf("%d %d", &vertices, &edges);
  memset(ppl, 0, sizeof(ppl));
  bool bad = false;
  for (int i = 0; i < edges; i++){
    int spy, spied;
    scanf("%d %d", &spy, &spied);
    if (ppl[spy] == 2 || ppl[spied] == 1)
      bad = true;
    ppl[spy] = 1;
    ppl[spied] = 2;
  }
  if (bad)
    puts("spied");
  else
    puts("spying");
}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int cases = 1; cases <= tests; cases++){
    printf("Scenario #%d: ", cases);
    solve();
  }
  return 0;
}

