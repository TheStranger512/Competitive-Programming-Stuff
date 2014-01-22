/* Solved
 * Chef and Segments
 * File:   CHMOD.cpp
 * Author: Andy Y.F. Huang
 * Created on August 2, 2013, 11:30 AM
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

namespace CHMOD {
#define SIZE 25
const int PRIMES[SIZE] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                          47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
typedef long long ll;
int tree[1 << 18][SIZE];
int MOD;

ll fpow(ll base, int e) {
  ll ans = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ans = ans * base % MOD;
    base = base * base % MOD;
  }
  return ans;
}

void add(int* r, int* a, int* b) {
  for (int i = 0; i < SIZE; i++)
    r[i] = a[i] + b[i];
}

void solve(int test_num) {
  int N, off;
  scanf("%d", &N);
  off = 1;
  while (off < N) off <<= 1;
  for (int i = 0, x; i < N; i++) {
    scanf("%d", &x);
    for (int j = 0; j < SIZE; j++)
      for (; x % PRIMES[j] == 0; x /= PRIMES[j])
        tree[off + i][j]++;
  }
  for (int i = off - 1; i > 0; i--)
    add(tree[i], tree[i + i], tree[i + i + 1]);
  int Q, res[25];
  scanf("%d", &Q);
  for (int q = 0, l, r; q < Q; q++) {
    scanf("%d %d %d", &l, &r, &MOD);
    l--, r--;
    memset(res, 0, sizeof (res));
    for (l += off, r += off + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) add(res, res, tree[l++]);
      if (r & 1) add(res, res, tree[--r]);
    }
    ll ans = 1;
    for (int i = 0; i < SIZE; i++)
      ans = ans * fpow(PRIMES[i], res[i]) % MOD;
    printf("%d\n", (int) ans);
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
  CHMOD::solve();
  return 0;
}

