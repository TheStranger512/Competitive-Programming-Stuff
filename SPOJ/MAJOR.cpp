/* Solved
 * 6171. Majority - counting
 * File:   MAJOR.cpp
 * Author: Andy Huang
 * Created on June 4, 2012, 7:39 PM
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

#define max_num 2050
#define offset 1000
#define null -1

int cnt[max_num];

void solve() {
  memset(cnt, 0, sizeof (cnt));
  int nums;
  scanf("%d", &nums);
  int half = nums >> 1;
  int ans = null;
  while (nums--) {
    int temp;
    scanf("%d", &temp);
    temp += offset;
    cnt[temp]++;
    if (cnt[temp] > half)
      ans = temp;
  }
  if (ans == null)
    puts("NO");
  else
    printf("YES %d\n", ans - offset);
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

