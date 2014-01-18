/* Solved
 * 1868. Making Money - math
 * File:   MKMONEY.cpp
 * Author: Andy Y.F. Huang
 * Created on September 8, 2012, 11:44 PM
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
namespace MKMONEY {
double prin, interest;
int comps;

void solve(int test_num) {
  int ans = (int) (prin * 100.0 + 1e-6);
  for (int i = 0; i < comps; i++)
    ans = (int) floor(ans * (1 + interest / 100.0 / comps) + 1e-6);
  printf("Case %d. $%.2lf at %.2lf%% APR compounded %d times yields $%.2lf\n",
         test_num, prin, interest, comps, ans / 100.0);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  for (int i = 1; ; i++) {
    scanf("%lf %lf %d", &prin, &interest, &comps);
    if (comps == 0)
      break;
    solve(i);
  }
}
}

int main() {
  MKMONEY::solve();
  return 0;
}

