/* Solved
 * 12557. Basic Routines
 * File:   CDC12_B.cpp
 * Author: Andy Y.F. Huang
 * Created on December 7, 2012, 10:09 PM
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
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace CDC12_B {

struct Activity {
  const char* name;
  int cost;

  bool operator<(const Activity & a) const {
    return strcmp(name, a.name) < 0;
  }
} ;

Activity acts[111111];
char name[111111][111];

bool cmp(const Activity& a, const Activity& b) {
  return a.cost < b.cost || (a.cost == b.cost && strcmp(a.name, b.name) < 0);
}

void solve(int test_num) {
  int len, energy;
  scanf("%d %d", &len, &energy);
  for (int i = 0; i < len; i++) {
    scanf("%s %d", name[i], &acts[i].cost);
    acts[i].name = name[i];
  }
  sort(acts, acts + len, cmp);
  int cnt = 0;
  for (int i = 0; i < len; i++) {
    if (acts[i].cost <= energy)
      energy = energy - acts[i].cost + (++cnt);
    else
      break;
  }
  sort(acts, acts + cnt);
  printf("Scenario #%d: %d\n", test_num, cnt);
  for (int i = 0; i < cnt; i++)
    printf("%s ", acts[i].name);
  putchar('\n');
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
  CDC12_B::solve();
  return 0;
}

