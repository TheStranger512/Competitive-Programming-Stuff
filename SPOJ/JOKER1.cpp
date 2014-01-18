/* Solved
 * 13875. Knifes Are Fun
 * File:   JOKER1.cpp
 * Author: Andy Y.F. Huang
 * Created on February 26, 2013, 12:03 AM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace JOKER1 {
#define mod 1000000007
int lim[77];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d", lim + i);
  sort(lim, lim + len);
  long long ans = 1;
  for (int i = 0; i < len; i++)
    ans = ans * max(lim[i ] - i, 0) % mod;
  printf("%lld\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
  puts("KILL BATMAN");
}
}

int main() {
  JOKER1::solve();
  return 0;
}

