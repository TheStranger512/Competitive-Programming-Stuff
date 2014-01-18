/* Solved
 * 7741. Sequence
 * File:   BOI7SEQ.cpp
 * Author: Andy Y.F. Huang
 * Created on May 12, 2013, 3:45 PM
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

namespace BOI7SEQ {

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  long long res = 0;
  int prev;
  scanf("%d", &prev);
  for (int i = 1, next; i < len; i++) {
    scanf("%d", &next);
    res += max(prev, next);
    prev = next;
  }
  printf("%lld\n", res);
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
  BOI7SEQ::solve();
  return 0;
}

