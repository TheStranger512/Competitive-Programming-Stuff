/* Solved
 * 11895. DONALDO
 * File:   DONALDO.cpp
 * Author: Andy Y.F. Huang
 * Created on August 8, 2012, 5:08 PM
 */

#include <cstdio>
#include <algorithm>
#include <queue>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace DONALDO {
queue<int> ends;
int times[20010];

void solve(int test_num) {
  int len, interval, ans = 0;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    int hours, mins, secs;
    scanf("%d:%d:%d", &hours, &mins, &secs);
    times[i] = hours * 3600 + mins * 60 + secs;
  }
  scanf("%d", &interval);
  sort(times, times + len);
  for (int i = 0; i < len; i++) {
    int cur = times[i];
    if (ends.empty() || cur < ends.front())
      ans++;
    else
      ends.pop();
    ends.push(cur + interval);
  }
  while (!ends.empty())
    ends.pop();
  printf("Case %d: %d\n", test_num, ans);
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
  DONALDO::solve();
  return 0;
}

