/* Solved
 * SPOJ 861. Counting inversions
 * using Sqrt N Blocks
 * File:   SWAPS.cpp
 * Author: Andy Y.F. Huang
 * Created on Aug 20, 2013, SH:20:55 PM
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

namespace SWAPS {
const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
unsigned int bytes_read = 0;
unsigned int input_index = 0;

inline char next_char() {
  if (input_index == bytes_read) {
    bytes_read = fread(input_buffer, sizeof(char), buffer_size, stdin);
    input_buffer[bytes_read] = '\0'; //sentinel
    input_index = 0;
  }
  return input_buffer[input_index++];
}

inline int next_int() {
  char c = 0;
  int ans = 0;
  while (c < '-')
    c = next_char();
  for (; c >= '0'; c = next_char())
    ans = (ans << 1) + (ans << 3) + c - '0';
  return ans;
}

const int SIZE = 512, SH = 9;
int arr[250111];
int tree[50111];
int bit[SIZE][50111];
int N, Q;

void update(int x, int y, int val) {
  for (++x; x < SIZE; x += x & -x)
    for (int i = y; i <= 50000; i += i & -i)
      bit[x][i] += val;
}

int get(int x, int y) {
  int res = 0;
  for (++x; x > 0; x -= x & -x)
    for (int i = y; i > 0; i -= i & -i)
      res += bit[x][i];
  return res;
}

int query_less(int l, int val) {
  //# of vals < val in [l,N)
  int res = 0, i = l;
  for (; i < N && (i & 511); i++)
    res += arr[i] < val;
  if (i == N)
    return res;
  int bls = ((N - i) >> SH);
  i >>= SH;
  //pln(l, bls, i, i + bls - 1, (i + bls) << SH);
  res += get(i + bls - 1, val - 1) - get(i - 1, val - 1);
  for (i = (i + bls) << SH; i < N; i++)
    res += arr[i] < val;
  return res;
}

int query_gre(int r, int val) {
  //# of val > val in [0, r]
  int res = 0, i = 0;
  for (; i <= r && (i & 511); i++)
    res += arr[i] > val;
  if (i > r)
    return res;
  int bls = ((r + 1 - i) >> SH);
  i >>= SH;
  //pln(r, i, i + bls - 1, (i + bls) << SH);
  res += SIZE * bls - get(i + bls - 1, val) + get(i - 1, val);
  for (i = (i + bls) << SH; i <= r; i++)
    res += arr[i] > val;
  return res;
}

void solve(int test_num) {
  N = next_int();
  for (int i = 0; i < N; i++)
    arr[i] = next_int();
  long long res = 0;
  for (int i = 0; i < N; i++) {
    res += i;
    for (int x = arr[i]; x > 0; x -= x & -x)
      res -= tree[x];
    for (int x = arr[i]; x <= 50000; x += x & -x)
      tree[x]++;
    update(i >> SH, arr[i], 1);
  }
  Q = next_int();
  for (int q = 0, p, v; q < Q; q++) {
    p = next_int();
    v = next_int();
    //scanf("%d %d", &p, &v);
    --p;
    res -= query_gre(p - 1, arr[p]);
    res -= query_less(p + 1, arr[p]);
    update(p >> SH, arr[p], -1);
    update(p >> SH, v, 1);
    arr[p] = v;
    res += query_gre(p - 1, v);
    res += query_less(p + 1, v);
    printf("%lld\n", res);
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
  SWAPS::solve();
  return 0;
}


