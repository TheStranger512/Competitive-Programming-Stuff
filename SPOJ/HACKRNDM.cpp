/* Solved
 * 9734. Hacking the random number generator - hashing
 * File:   HACKRNDM.cpp
 * Author: Andy Huang
 * Created on June 3, 2012, 3:27 PM
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

#define max_size 1000050

set<int> moi;
int nums[max_size];

void solve() {
  int n, diff, ans = 0;
  scanf("%d %d", &n, &diff);
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
    moi.insert(nums[i]);
  }
  for (int i = 0; i < n; i++) {
    int cur = nums[i];
    if (cur - diff >= 0)
      ans += moi.count(cur - diff);
  }
  printf("%d", ans);
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}

