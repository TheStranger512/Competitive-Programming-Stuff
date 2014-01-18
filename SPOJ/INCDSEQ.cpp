/* Solved
 * 2817. Distinct Increasing Subsequences - bit
 * File:   INCDSEQ.cpp
 * Author: Andy Y.F. Huang
 * Created on September 4, 2012, 11:22 AM
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
namespace INCDSEQ {
const int k_max_len = 10010, k_max_k = 55, k_mod = 5000000;
int val[k_max_len], tree[k_max_k][k_max_len];
int prev[k_max_k][k_max_len];
int order[k_max_len];

void update(int arr[], int pos, int val) {
  for (int i = pos; i < k_max_len; i += i&-i) {
    arr[i] += val;
    if (arr[i] >= k_mod)
      arr[i] -= k_mod;
  }
}

int query(int arr[], int pos) {
  if (arr == tree[0])
    return 1;
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
  memset(prev, 0, sizeof (prev));
  memset(tree, 0, sizeof (tree));
  int len, k;
  scanf("%d %d", &len, &k);
  for (int i = 0; i < len; i++) {
    scanf("%d", &val[i]);
    order[i] = i;
  }
  sort(order, order + len, cmp);
  for (int i = 0, curhash = 1; i < len; ) {
    int cur = val[order[i]];
    while (i < len && val[order[i]] == cur)
      val[order[i++]] = curhash;
    curhash++;
  }
  for (int i = 0; i < len; i++) {
    int cur = val[i];
    for (int j = 1; j <= k; j++) {
      int sum = query(tree[j - 1], cur - 1);
      if (sum != prev[j - 1][cur - 1]) {
        int temp = sum;
        temp -= prev[j - 1][cur - 1];
        if (temp < 0)
          temp += k_mod;
        prev[j - 1][cur - 1] = sum;
        update(tree[j], cur, temp);
      }
    }
  }
  printf("%d\n", query(tree[k], k_max_len));
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
  INCDSEQ::solve();
  return 0;
}

