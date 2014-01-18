/* Solved
 * 10108. Distributing Ballot Boxes
 * File:   BALLOT.cpp
 * Author: Andy Y.F. Huang
 * Created on March 11, 2013, 1:46 PM
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

namespace BALLOT {
int len, boxes;
int ppl[555000];

void solve(int test_num) {
  for (int i = 0; i < len; i++)
    scanf("%d", ppl + i);
  int ans = (int) 5e6;
  for (int low = 1, high = (int) 5e6, mid; low <= high; ) {
    mid = (low + high) >> 1;
    long long total = 0;
    for (int i = 0; i < len; i++)
      total += (ppl[i] + mid - 1) / mid;
    if (total <= boxes) {
      ans = min(ans, mid);
      high = mid - 1;
    }
    else low = mid + 1;
  }
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (true) {
    scanf("%d %d", &len, &boxes);
    if (len == -1)
      break;
    solve(1);
  }
}
}

int main() {
  BALLOT::solve();
  return 0;
}

