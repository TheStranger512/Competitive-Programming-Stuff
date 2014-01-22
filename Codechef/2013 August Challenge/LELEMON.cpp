/* Solved
 * August Challenge 2013
 * Little Elephant and Lemonade
 * File:   LELEMON.cpp
 * Author: Andy Y.F. Huang
 * Created on August 2, 2013, 10:58 AM
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

namespace LELEMON {
int order[11111];
vector<int> vol[111];

void solve(int test_num) {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++)
    cin >> order[i];
  for (int i = 0, cnt; i < N; i++) {
    cin >> cnt;
    vol[i].resize(cnt);
    for (int j = 0; j < cnt; j++)
      cin >> vol[i][j];
    sort(vol[i].begin(), vol[i].end());
  }
  int res = 0;
  for (int i = 0; i < M; i++) {
    int cur = order[i];
    if (!vol[cur].empty()) {
      res += vol[cur].back();
      vol[cur].pop_back();
    }
  }
  cout << res << endl;
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
  LELEMON::solve();
  return 0;
}

