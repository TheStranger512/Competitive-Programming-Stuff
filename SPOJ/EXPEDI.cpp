/* Solved
 * 348. Expedition
 * File:   EXPEDI.cpp
 * Author: Andy Y.F. Huang
 * Created on August 27, 2012, 9:07 PM
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
namespace EXPEDI {

struct Stop {
  int dist, amount;

  bool operator<(const Stop & s) const {
    return amount < s.amount;
  }
} ;

bool cmp(const Stop& a, const Stop& b) {
  return a.dist > b.dist;
}

Stop stops[10010];
priority_queue<Stop> heap;

void solve(int test_num) {
  while (!heap.empty())
    heap.pop();
  int stores, start, fuel, passed = 0, ans = 0;
  scanf("%d", &stores);
  for (int i = 0; i < stores; i++)
    scanf("%d %d", &stops[i].dist, &stops[i].amount);
  sort(stops, stops + stores, cmp);
  scanf("%d %d", &start, &fuel);
  while (start > 0) {
    start -= fuel, fuel = 0;
    if (start <= 0)
      break;
    while (passed < stores && start <= stops[passed].dist)
      heap.push(stops[passed++]);
    if (heap.empty()) {
      puts("-1");
      return;
    }
    fuel += heap.top().amount, heap.pop();
    ans++;
  }
  printf("%d\n", ans);
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
  EXPEDI::solve();
  return 0;
}

