/* Solved
 * 11515. I AM VERY BUSY - sorting intervals
 * File:   BUSYMAN.cpp
 * Author: Andy Huang
 * Created on June 15, 2012, 8:22 PM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
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

struct Event {
  int start;
  int end;

  bool operator<(const Event & pt) const {
    return end < pt.end;
  }

} ;

#define max_len 100050

Event events[max_len];

void solve() {
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d %d", &events[i].start, &events[i].end);
  sort(events, events + len);
  int ans = 0;
  int cur = -1;
  for (int i = 0; i < len; i++) {
    if (events[i].start >= cur) {
      cur = events[i].end;
      ans++;
    }
  }
  printf("%d\n", ans);
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  while (tests--)
    solve();
  return 0;
}

