/* Solved
 * 14156. Movie Theatre Madness
 * File:   THEATRE.cpp
 * Author: Andy Y.F. Huang
 * Created on May 27, 2013, 4:32 PM
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

namespace THEATRE {
#define MOD 1000000007
int h[100111];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  long long ans = 1;
  stack<int> st;
  for (int i = 0; i < len; i++)
    scanf("%d", h + i);
  for (int i = len - 1; i >= 0; i--) {
    while (!st.empty() && st.top() <= h[i])
      st.pop();
    if (!st.empty())
      ans = ans * st.top() % MOD;
    st.push(h[i]);
  }
  printf("%lld\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  THEATRE::solve();
  return 0;
}

