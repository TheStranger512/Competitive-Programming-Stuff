/* Solved
 * 243. Stable Marriage Problem
 * File:   STABLEMP.cpp
 * Author: Andy Y.F. Huang
 * Created on August 11, 2012, 10:39 PM
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
 * Unsolved
 * @author Andy Y.F. Huang
 */
namespace STABLEMP {
const int k_max_size = 510;
int boyslikes[k_max_size][k_max_size], temp[k_max_size][k_max_size];
int girlsorder[k_max_size][k_max_size], proposed[k_max_size];
int matchboys[k_max_size], matchgirls[k_max_size];
queue<int> single;

void solve(int test_num) {
  memset(matchboys, 0xFF, sizeof (matchboys));
  memset(matchgirls, 0xFF, sizeof (matchgirls));
  memset(proposed, 0, sizeof (proposed));
  int size;
  scanf("%d", &size);
  for (int i = 1; i <= size; i++) {
    int girl;
    scanf("%d", &girl);
    for (int j = 1; j <= size; j++)
      scanf("%d", &temp[girl][j]);
  }
  for (int i = 1; i <= size; i++)
    for (int j = 1; j <= size; j++)
      girlsorder[i][temp[i][j]] = j;
  for (int i = 1; i <= size; i++) {
    int boy;
    scanf("%d", &boy);
    for (int j = 1; j <= size; j++) {
      scanf("%d", &boyslikes[boy][j]);
    }
  }
  for (int i = 1; i <= size; i++)
    single.push(i);
  while (!single.empty()) {
    int boy = single.front(), girl = boyslikes[boy][++proposed[boy]];
    single.pop();
    if (matchgirls[girl] == -1) {
      matchgirls[girl] = boy;
      matchboys[boy] = girl;
    }
    else if (girlsorder[girl][boy] < girlsorder[girl][matchgirls[girl]]){
      single.push(matchgirls[girl]); //dumped
      matchboys[single.back()] = -1;
      matchboys[boy] = girl;
      matchgirls[girl] = boy;
    }
    else
      single.push(boy); //rejected
  }
  for (int i = 1; i <= size; i++)
    printf("%d %d\n", i, matchboys[i]);
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
  STABLEMP::solve();
  return 0;
}

