/* Solved
 * 12277. The Trip
 * File:   OPCTRIP.cpp
 * Author: Andy Y.F. Huang
 * Created on October 17, 2012, 9:37 PM
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
namespace OPCTRIP {

void solve(int test_num) {
  int regions, friends;
  long long ans = 0;
  scanf("%d %d", &regions, &friends);
  int temp, limit, icecost, buscost;
  for (int r = 0; r < regions; r++) {
    scanf("%d %d %d %d", &temp, &limit, &icecost, &buscost);
    limit -= temp;
    if (friends <= limit)
      ans += buscost;
    else {
      long long onebus = buscost + 1LL * friends * icecost;
      long long allhappy;
      if (limit <= 0)
        allhappy = onebus;
      else
        allhappy = 1LL * ((friends + limit - 1) / limit) * buscost;
      ans += min(allhappy, onebus);
    }
  }
  printf("%lld\n", ans);
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
  OPCTRIP::solve();
  return 0;
}

