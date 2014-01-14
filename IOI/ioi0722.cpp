/* Solved
 * IOI '07 - Zagreb, Croatia
 * Pairs
 * File:   ioi0722.cpp
 * Author: Andy Y.F. Huang
 * Created on September 30, 2012, 12:13 AM
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
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ioi0722 {
const int k_offset = 150;
int type, coord[111111][4], dist, len, maxlim;
int order[111111], bit1d[155555] = {0}, bit3d[301][301][301];

bool cmp(int a, int b) {
  return coord[a][0] < coord[b][0];
}

void update3d(int x, int y, int z, int val) {
  x += k_offset, y += k_offset, z += k_offset;
  int i, j, k;
  for (i = x; i <= maxlim; i += i&-i)
    for (j = y; j <= maxlim; j += j&-j)
      for (k = z; k <= maxlim; k += k&-k)
        bit3d[i][j][k] += val;
}

int query3d(int x, int y, int z) {
  if (x <= 0 || y <= 0 || z <= 0)
    return 0;
  if (x > maxlim) x = maxlim;
  if (y > maxlim) y = maxlim;
  if (z > maxlim) z = maxlim;
  int i, j, k, ans = 0;
  for (i = x; i > 0; i -= i&-i)
    for (j = y; j > 0; j -= j&-j)
      for (k = z; k > 0; k -= k&-k)
        ans += bit3d[i][j][k];
  return ans;
}

int getsum3d(int x1, int y1, int z1, int x2, int y2, int z2) {
  x1 += k_offset, y1 += k_offset, z1 += k_offset;
  x2 += k_offset, y2 += k_offset, z2 += k_offset;
  return + query3d(x2, y2, z2)
          - query3d(x1 - 1, y2, z2) - query3d(x2, y1 - 1, z2) - query3d(x2, y2, z1 - 1)
          + query3d(x1 - 1, y1 - 1, z2) + query3d(x1 - 1, y2, z1 - 1) + query3d(x2, y1 - 1, z1 - 1)
          - query3d(x1 - 1, y1 - 1, z1 - 1);
}

void solve3d() {
  maxlim = 300;
  for (int i = 0, x, y, z; i < len; i++) {
    scanf("%d %d %d", &x, &y, &z);
    coord[i][0] = x + y + z;
    coord[i][1] = x - y - z;
    coord[i][2] = x - y + z;
    coord[i][3] = x + y - z;
    order[i] = i;
  }
  sort(order, order + len, cmp);
  long long ans = 0;
  for (int i = 0, head = 0; i < len; i++) {
    int cur = order[i];
    while (head < i && coord[order[head]][0] + dist < coord[cur][0]) {
      update3d(coord[order[head]][1], coord[order[head]][2], coord[order[head]][3], -1);
      head++;
    }
    ans += getsum3d(coord[cur][1] - dist, coord[cur][2] - dist, coord[cur][3] - dist,
                    coord[cur][1] + dist, coord[cur][2] + dist, coord[cur][3] + dist);
    update3d(coord[cur][1], coord[cur][2], coord[cur][3], 1);
  }
  printf("%lld\n", ans);
}

void update1d(int pos, int val) {
  for (int i = pos; i <= maxlim; i += i&-i)
    bit1d[i] += val;
}

int query1d(int pos) {
  int ans = 0;
  for (int i = min(pos, maxlim); i > 0; i -= i&-i)
    ans += bit1d[i];
  return ans;
}

void solve2d() {
  maxlim <<= 1;
  for (int i = 0, x, y; i < len; i++) {
    scanf("%d %d", &x, &y);
    coord[i][0] = x - y;
    coord[i][1] = x + y;
    order[i] = i;
  }
  sort(order, order + len, cmp);
  //  for (int i = 0; i < len; i++)
  //    pln(coord[order[i]][0], coord[order[i]][1]);
  long long ans = 0;
  for (int head = 0, i = 0; i < len; i++) {
    int cur = order[i];
    while (head < i && coord[order[head]][0] + dist < coord[cur][0]) {
      update1d(coord[order[head]][1], -1);
      head++;
    }
    ans += query1d(coord[cur][1] + dist) - query1d(coord[cur][1] - dist - 1);
    update1d(coord[cur][1], 1);
  }
  printf("%lld\n", ans);
}

void solve1d() {
  for (int i = 0; i < len; i++) {
    scanf("%d", &coord[i][0]);
    order[i] = i;
  }
  sort(order, order + len, cmp);
  int head = 0;
  long long ans = 0;
  for (int i = 0; i < len; i++) {
    while (head < i && coord[order[head]][0] + dist < coord[order[i]][0])
      head++;
    ans += i - head;
  }
  printf("%lld\n", ans);
}

void solve(int test_num) {
  scanf("%d %d %d %d", &type, &len, &dist, &maxlim);
  if (type == 1)
    solve1d();
  else if (type == 2)
    solve2d();
  else
    solve3d();
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  ioi0722::solve();
  return 0;
}

