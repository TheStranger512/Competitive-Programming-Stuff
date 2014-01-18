/* Solved
 * 2815. Increasing Subsequences - bit and coordinate compression
 * File:   INCSEQ.cpp
 * Author: Andy Y.F. Huang
 * Created on September 2, 2012, 11:59 PM
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
namespace INCSEQ {
const int k_maxk = 55, k_maxlen = 10010, k_mod = 5000000;
int tree[k_maxk][k_maxlen];
int val[k_maxlen], order[k_maxlen];

void update(int arr[], int pos, int val) {
  for (int i = pos; i < k_maxlen; i += i&-i) {
    arr[i] += val;
    if (arr[i] >= k_mod)
      arr[i] -= k_mod;
  }
}

int query(int arr[], int pos) {
  int ans = 0;
  for (int i = pos; i > 0; i -= i&-i) {
    ans += arr[i];
    if (ans >= k_mod)
      ans -= k_mod;
  }
  return ans;
}

bool cmp(int a, int b) {
  return val[a] < val[b];
}

void solve(int test_num) {
  memset(tree, 0, sizeof (tree));
  int len, k, curhash = 1;
  scanf("%d %d", &len, &k);
  for (int i = 0; i < len; i++) {
    scanf("%d", &val[i]);
    order[i] = i;
  }
  sort(order, order + len, cmp);
  for (int i = 0; i < len; ) {
    int cur = val[order[i]];
    while (i < len && val[order[i]] == cur)
      val[order[i++]] = curhash;
    curhash++;
  }
  //plnarr(val, val + len);
  for (int i = 0; i < len; i++) {
    int cur = val[i], lim = min(k, cur);
    for (int j = 2; j <= lim; j++) {
      int sum = query(tree[j - 1], cur - 1);
      //pln(i, j, sum);
      if (sum != 0)
        update(tree[j], cur, sum);
    }
    update(tree[1], cur, 1);
  }
  printf("%d\n", query(tree[k], k_maxlen));
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
  INCSEQ::solve();
  return 0;
}

