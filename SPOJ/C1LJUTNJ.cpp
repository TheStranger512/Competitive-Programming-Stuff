/* Solved
 * 7881. Ljutnja
 * File:   C1LJUTNJ.cpp
 * Author: Andy Y.F. Huang
 * Created on September 23, 2012, 6:42 PM
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
namespace C1LJUTNJ {
int need[100100];

void solve(int test_num) {
  int have, len;
  long long ans = 0, sum = 0;
  scanf("%d %d", &have, &len);
  for (int i = 0; i < len; i++) {
    scanf("%d", &need[i]);
    sum += need[i];
  }
  sort(need, need + len);
  sum -= have;
  for (int i = 0; i < len; i++) {
    long long take = min((long long) need[i], sum / (len - i));
    ans += take * take;
    sum -= take;
  }
  printf("%lld\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  C1LJUTNJ::solve();
  return 0;
}

