/* Solved
 * 10401. Aliens at the train
 * File:   ALIEN.cpp
 * Author: Andy Y.F. Huang
 * Created on October 27, 2012, 1:23 PM
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
namespace ALIEN {
int len, limit;
int cnt[111111] = {0};

int least(int width) {
  int ans = 1 << 20;
  for (int i = 1; i + width - 1 <= len; i++)
    ans = min(ans, cnt[i + width - 1] - cnt[i - 1]);
  return ans;
}

void solve(int test_num) {
  scanf("%d %d", &len, &limit);
  for (int i = 1; i <= len; i++) {
    scanf("%d", &cnt[i]);
    cnt[i] += cnt[i - 1];
  }
  int ans = 0, ppl = 0;
  for (int low = 1, high = len; low <= high; ) {
    int mid = (low + high) >> 1;
    int temp = least(mid);
    if (temp <= limit) {
      if (mid > ans) {
        ans = mid;
        ppl = temp;
      }
      low = mid + 1;
    }
    else
      high = mid - 1;
  }
  printf("%d %d\n", ppl, ans);
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
  ALIEN::solve();
  return 0;
}

