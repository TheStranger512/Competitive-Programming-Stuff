/* Solved
 * 7185. Bye Bye Cakes - simple math
 * File:   BYECAKES.cpp
 * Author: Andy Huang
 * Created on June 2, 2012, 11:15 PM
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
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#define pln(x) println(x)
#define pf(x) print(x)
#define plnarr(i, j) println(i, j)
#endif

using namespace std;

#define len 4

void solve(int* have, int* need) {
  int cakes = 0;
  for (int i = 0; i < len; i++)
    cakes = max(cakes, (int) ceil((double) (have[i]) / need[i]));
  for (int i = 0; i < len; i++)
    printf("%d ", cakes * need[i] - have[i]);
  puts("");

}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int have[4];
  int need[4];
  while (true) {
    for (int i = 0; i < 4; i++)
      scanf("%d", &have[i]);
    for (int j = 0; j < 4; j++)
      scanf("%d", &need[j]);
    if (have[0] != -1)
      solve(have, need);
    else
      break;
  }
  return 0;
}

