/* Solved
 * 12323. Minimum Knight moves !!!
 * File:   NAKANJ.cpp
 * Author: Andy Y.F. Huang
 * Created on December 24, 2012, 6:00 PM
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
namespace NAKANJ {
const int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
char a[5], b[5];
int dist[10][10];

void solve(int test_num) {
  scanf("%s %s", a, b);
  int sr = a[1] - '0', sc = a[0] - 'a' + 1;
  int er = b[1] - '0', ec = b[0] - 'a' + 1;
  queue<pair<int, int> > q;
  q.push(make_pair(sr, sc));
  memset(dist, 0x3F, sizeof (dist));
  dist[sr][sc] = 0;
  while (!q.empty()) {
    int r = q.front().first, c = q.front().second;
    q.pop();
    for (int d = 0; d < 8; d++) {
      int nr = r + dy[d], nc = c + dx[d];
      if (nr < 1 || nr > 8 || nc < 1 || nc > 8) continue;
      if (dist[r][c] + 1 < dist[nr][nc]) {
        dist[nr][nc] = dist[r][c] + 1;
        q.push(make_pair(nr, nc));
      }
    }
  }
  printf("%d\n", dist[er][ec]);
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
  NAKANJ::solve();
  return 0;
}

