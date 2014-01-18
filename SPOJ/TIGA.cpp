/* Solved
 * 12523. Nuts Frenzy
 * To calculate sum of all factors in a number
 * see http://mathforum.org/library/drmath/view/71550.html
 * File:   TIGA.cpp
 * Author: Andy Y.F. Huang
 * Created on October 20, 2012, 12:58 PM
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
namespace TIGA {

void solve(int test_num) {
  int i, nuts, f;
  scanf("%d %d %d", &nuts, &i, &f);
  int a = (nuts + i - 1) / i;
  int b;
  if (nuts < f)
    b = nuts;
  else
    b = (nuts + nuts / f - 1) / (nuts / f);
  int lim = (int) sqrt(nuts), temp = nuts;
  long long sum = 1;
  for (int p = 2; p <= lim; p++) {
    int cnt = 0;
    while (temp % p == 0) {
      cnt++;
      temp /= p;
    }
    //pln(p, cnt);
    int temp2 = p, sum2 = 1;
    for (int i = 0; i < cnt; i++) {
      sum2 += temp2;
      temp2 *= p;
    }
    sum *= sum2;
  }
  if (temp != 1)
    sum *= temp + 1;
  //pln(sum);
  sum--; //delete factor of one
  sum -= nuts; //delete trivial factor
  if (sum <= 0)
    sum = 1;
  int c = (nuts + sum - 1) / sum;
  if (c <= 0)
    c = 1;
  printf("%d %d %d\n", a, b, c);
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
  TIGA::solve();
  return 0;
}

