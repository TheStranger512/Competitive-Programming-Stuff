/* Solved
 * 13511. Determine the vismin value !
 * File:   KOSPC13B.cpp
 * Author: Andy Y.F. Huang
 * Created on February 14, 2013, 9:50 PM
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

namespace KOSPC13B {
typedef pair<int, int> Student; //number, position
Student studs[111222];
long long vismin[111000];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%d", &studs[i].first);
    studs[i].second = i;
  }
  sort(studs, studs + len, greater<Student > ());
  int high = studs[0].second, low = high;
  for (int i = 0; i < len; ) {
    int j = i;
    while (j < len && studs[j].first == studs[i].first) {
      high = max(high, studs[j].second);
      low = min(low, studs[j].second);
      j++;
    }
    for (; i < j; i++)
      vismin[studs[i].second] = 1LL * studs[i].first * max(high - studs[i].second, studs[i].second - low);
  }
  while (true) {
    int a;
    long long val;
    scanf("%d %lld", &a, &val);
    if (a == 0 && val == 0)
      break;
    a--;
    if (val < vismin[a]) printf("%lld\n", vismin[a] - val);
    else if (val == vismin[a]) puts("Maximum");
    else puts("Not possible");
  }
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
  KOSPC13B::solve();
  return 0;
}

