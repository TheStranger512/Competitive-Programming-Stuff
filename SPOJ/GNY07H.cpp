/* Solved
 * 2530. Tiling a Grid With Dominoes - OEIS A005178
 * File:   GNY07H.cpp
 * Author: Andy Huang
 * Created on May 26, 2012, 8:38 PM
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

#ifdef AZN
#include "Azn.cpp"
#define pln(x) println(x)
#define pf(x) print(x);
#endif

using namespace std;

long long ans[1050];

void solve() {
  ans[0] = 1;
  ans[1] = 1;
  ans[2] = 5;
  ans[3] = 11;
  for (int i = 4; i <= 1000; i++)
    ans[i] = ans[i - 1] + 5LL * ans[i - 2] + ans[i - 3] - ans[i - 4];
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int term;
    scanf("%d", &term);
    printf("%d %lld\n", i, ans[term]);
  }

}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}

