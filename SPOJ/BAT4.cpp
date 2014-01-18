/* Solved
 * 13646. BATMAN4
 * File:   BAT4.cpp
 * Author: Andy Y.F. Huang
 * Created on June 21, 2013, 8:55 PM
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

namespace BAT4 {
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int h[22][22];
int vals[444];
int dist[22][22];

void solve(int test_num) {
  memset(h, 0x3F, sizeof (h));
  int size, lim, high = -1;
  scanf("%d %d", &size, &lim);
  for (int i = 1; i <= size; i++)
    for (int j = 1; j <= size; j++) {
      scanf("%d", &h[i][j]);
      high = max(high, h[i][j]);
    }
  int res = -1, take, low;
  for (low = h[1][1], high += h[1][1]; low <= high; ) {
    int mid = (low + high) >> 1;
    memset(dist, 0x3F, sizeof (dist));
    dist[1][1] = h[1][1];
    queue<pair<int, int> > q;
    q.push(make_pair(1, 1));
    for (int r, c, d; !q.empty(); q.pop()) {
      r = q.front().first;
      c = q.front().second;
      for (d = 0; d < 4; d++) {
        int nr = r + dx[d];
        int nc = c + dy[d];
        if (h[nr][nc] - h[r][c] <= mid &&
                dist[r][c] + abs(h[nr][nc] - h[r][c]) < dist[nr][nc]) {
          dist[nr][nc] = dist[r][c] + abs(h[nr][nc] - h[r][c]);
          q.push(make_pair(nr, nc));
        }
      }
    }
    if (dist[size][size] <= lim) {
      res = mid;
      take = dist[size][size];
      high = mid - 1;
    }
    else low = mid + 1;
  }
  if (~res) printf("YES : %d %d\n", res, lim - take);
  else puts("NO");
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
  BAT4::solve();
  return 0;
}

