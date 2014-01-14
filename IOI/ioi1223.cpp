/* Solved
 * IOI '12 - Sirmione/Montichiari, Italy
 * Jousting Tournament
 * File:   ioi1223.cpp
 * Author: Andy Y.F. Huang
 * Created on Aug 21, 2013, 7:07:35 PM
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

namespace ioi1223 {
#define MAX 100001
int st[MAX], ed[MAX];
int sum[MAX], bit[MAX];
int id[MAX];
int best[MAX]; //most wins at ith position
int N, C, R;

void update(int pos, int val) {
  for (int i = pos; i <= N; i += i & -i)
    bit[i] += val;
}

int lowerbound(int val) {
  int res = 0;
  for (int b = 1 << 16; b > 0; b >>= 1)
    if (res + b <= N && bit[res + b] < val)
      val -= bit[res += b];
  return res + 1;
}

void solve(int test_num) {
  scanf("%d %d %d", &N, &C, &R);
  for (int i = 1; i < N; i++) {
    scanf("%d", sum + i);
    if (sum[i] > R)
      sum[i] = 1;
    else
      sum[i] = 0;
    sum[i] += sum[i - 1];
  }
  for (int i = 0; i < C; i++)
    scanf("%d %d", st + i, ed + i);
  memset(bit, 0, sizeof(bit));
  memset(best, 0, sizeof(best));
  for (int i = 1; i <= N; i++) {
    update(i, 1);
    id[i] = i;
  }
  int res = 0, resp = 1;
  for (int c = 0; c < C; c++) {
    int wins = 0, winpos, pos;
    ++ed[c], ++st[c];
    bool canwin = sum[lowerbound(ed[c] + 1) - 2] - sum[lowerbound(st[c]) - 1] == 0;
    for (int i = ed[c]; i >= st[c]; i--) {
      pos = lowerbound(i);
      if (i > st[c])
        update(pos, -1);
      if (best[pos] + 1 >= wins) {
        wins = best[pos] + 1;
        winpos = id[pos];
      }
    }
    //pos = position of winner
    id[pos] = winpos;
    best[pos] = wins;
    if (wins > res && canwin) {
      res = wins;
      resp = N;
    }
    if (wins == res && canwin)
      resp = min(resp, winpos);
  }
  printf("%d\n", resp - 1);
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
  ioi1223::solve();
  return 0;
}
