/* Solved
 * 709. The day of the competitors
 * File:   NICEDAY.cpp
 * Author: Andy Y.F. Huang
 * Created on June 2, 2013, 12:34 PM
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

namespace NICEDAY {
typedef pair<int, int> Point;
set<Point> good;
set<Point>::iterator it;
pair<int, Point> ppl[111000];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d %d %d", &ppl[i].first, &ppl[i].second.first, &ppl[i].second.second);
  sort(ppl, ppl + len);
  good.clear();
  int res = 0;
  for (int i = 0; i < len; i++) {
    Point cur = ppl[i].second;
    it = good.lower_bound(cur);
    if (it != good.begin() && (--it)->second < cur.second)
      continue;
    res++;
    for (it = good.lower_bound(cur); it != good.end(); ) {
      if (it->second > cur.second)
        good.erase(it++);
      else break;
    }
    good.insert(cur);
  }
  printf("%d\n", res);
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
}
}

int main() {
  NICEDAY::solve();
  return 0;
}

