/* Solved
 * Codechef August 2013 Cookoff
 * Chef and The Divisibility Queries
 * File:   DIVQUERY.cpp
 * Author: Andy Y.F. Huang
 * Created on Aug 18, 2013, 12:28:59 PM
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

using namespace std;

namespace DIVQUERY {
vector<int> pos[100001];

void solve(int test_num) {
  int N, Q;
  scanf("%d %d", &N, &Q);
  for (int i = 1, a; i <= N; i++) {
    scanf("%d", &a);
    for (int j = 1; j * j <= a; j++) {
      if (a % j == 0) {
        pos[j].push_back(i);
        if (j * j != a)
          pos[a / j].push_back(i);
      }
    }
  }
  for (int q = 0, l, r, k; q < Q; q++) {
    scanf("%d %d %d", &l, &r, &k);
    int res = upper_bound(pos[k].begin(), pos[k].end(), r)
        - lower_bound(pos[k].begin(), pos[k].end(), l);
    printf("%d\n", res);
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
  DIVQUERY::solve();
  return 0;
}
