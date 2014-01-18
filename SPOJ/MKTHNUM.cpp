/*
 * Solved
 * 3946. K-th Number
 * File:   MKTHNUM.cpp
 * Author: Andy Y.F. Huang
 * Created on March 6, 2013, 11:06 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace MKTHNUM {
int arr[111000];
int* tree[333000];
int size[333000];
int from, to, val;

#define lch (node<<1)
#define rch ((node<<1)+1)
#define mid ((start+end)>>1)

void build(int node, int start, int end) {
  if (start == end) {
    size[node] = 1;
    tree[node] = new int[1];
    tree[node][0] = arr[start];
    return;
  }
  build(lch, start, mid);
  build(rch, mid + 1, end);
  size[node] = size[lch] + size[rch];
  tree[node] = new int[size[node]];
  merge(tree[lch], tree[lch] + size[lch], tree[rch], tree[rch] + size[rch], tree[node]);
}

int query(int node, int start, int end) {
  if (from > end || to < start) return 0;
  if (from <= start && end <= to)
    return upper_bound(tree[node], tree[node] + size[node], val) - tree[node];
  return query(lch, start, mid) + query(rch, mid + 1, end);
}

void solve(int test_num) {
  int len, quests;
  scanf("%d %d", &len, &quests);
  for (int i = 0; i < len; i++)
    scanf("%d", arr + i);
  build(1, 0, len - 1);
  sort(arr, arr + len);
  for (int q = 0, rank; q < quests; q++) {
    scanf("%d %d %d", &from, &to, &rank);
    from--, to--;
    int ans = len;
    for (int low = 0, high = len - 1, md, temp; low <= high; ) {
      md = (low + high) >> 1;
      val = arr[md];
      temp = query(1, 0, len - 1);
      if (temp >= rank) {
        ans = min(ans, md);
        high = md - 1;
      }
      else low = md + 1;
    }
    printf("%d\n", arr[ans]);
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
  MKTHNUM::solve();
  return 0;
}

