/* Solved
 * 8132. Street Trees - gcd
 * File:   STREETR.cpp
 * Author: Andy Huang
 * Created on June 10, 2012, 11:20 PM
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

#define max_n 100050

int diff[max_n];

inline int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

void solve() {
  int n, prev = 0, g;
  long long ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int cur;
    scanf("%d", &cur);
    if (i) 
      diff[i - 1] = cur - prev;
    if (i == 2)
      g = gcd(diff[i -1], diff[i - 2]);
    else
      g = gcd(g, diff[i - 1]);
    prev = cur;
  }
  for (int i = 0; i < n - 1; i++) 
    ans += diff[i] / g - 1;
  printf("%lld\n", ans);
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}

