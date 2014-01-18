/* Solved
 * 14864. Sales
 * File:   SALES.cpp
 * Author: Andy Y.F. Huang
 * Created on May 11, 2013, 8:26 PM
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

namespace SALES {
int budget, len, days, offset;
int tree[99999][55];
int val[33333];

void calc(int* x, int* l, int* r) {
  static int temp[55];
  memset(temp, 0, sizeof (temp));
  for (int b = 0; b <= budget; b++)
    for (int bb = 0; bb + b <= budget; bb++)
      temp[b + bb] = max(temp[b + bb], l[b] + r[bb]);
  memcpy(x, temp, sizeof (temp));
}

void update(int pos, int ncost) {
  int i = (pos + offset);
  memset(tree[i], 0, sizeof (tree[i]));
  for (int b = ncost; b <= budget; b++)
    tree[i][b] = val[pos];
  for (i >>= 1; i > 0; i >>= 1)
    calc(tree[i], tree[i << 1], tree[i << 1 | 1]);
}

int get(int l, int r) {
  static int res[55];
  memset(res, 0, sizeof (res));
  for (l += offset, r += offset + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) calc(res, res, tree[l++]);
    if (r & 1) calc(res, res, tree[--r]);
  }
  return res[budget];
}

void solve(int test_num) {
  memset(tree, 0, sizeof (tree));
  scanf("%d %d %d", &budget, &len, &days);
  //assert(budget <= 50 && len <= 30000);
  offset = 1;
  while (offset < len) offset <<= 1;
  for (int i = 1, cost; i <= len; i++) {
    scanf("%d %d", &cost, val + i);
    for (int c = cost; c <= budget; c++)
      tree[i + offset][c] = val[i];
  }
  for (int i = offset - 1; i > 0; i--)
    calc(tree[i], tree[i << 1], tree[i << 1 | 1]);
  for (int q = 0; q < days; q++) {
    int card, cost, l, r;
    scanf("%d %d %d %d", &card, &cost, &l, &r);
    //assert(1 <= card && card <= len);
    update(card, cost);
    printf("%d\n", get(l, r));
  }
  //plnarr(tree[1], tree[1] + budget + 1);
}

void makecase() {
  srand(time(NULL));
  freopen("input.txt", "w", stdout);
  int B = 50, N = 10000, D = 1000;
  printf("%d %d %d\n", B, N, D);
  for (int i = 0; i < N; i++)
    printf("%d %d\n", rand() % B + 1, rand() % 1000 + 1);
  for (int q = 0; q < D; q++) {
    printf("%d %d ", rand() % N + 1, rand() % B + 1);
    int l = rand() % N + 1, r = l - 1;
    while (r < l) r = rand() % N + 1;
    printf("%d %d\n", l, r);
  }
}

void solve() {
  #ifdef AZN
  makecase();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  SALES::solve();
  return 0;
}

