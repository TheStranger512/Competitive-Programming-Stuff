/* Solved
 * 12563. Halt The War
 * File:   CDC12_H.cpp
 * Author: Andy Y.F. Huang
 * Created on December 8, 2012, 10:13 AM
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
namespace CDC12_H {
long long tree[1 << 18], lazy[1 << 18];
char str[55];
int from, to;

void prog(int node, int start, int end) {
  if (!lazy[node]) return;
  int mid = (start + end) >> 1;
  lazy[node + node] += lazy[node];
  lazy[node + node + 1] += lazy[node];
  tree[node + node] += 1LL * (mid - start + 1) * lazy[node];
  tree[node + node + 1] += 1LL * (end - mid) * lazy[node];
  lazy[node] = 0;
}

long long query(int node, int start, int end) {
  if (from > end || to < start) return 0;
  if (from <= start && end <= to) return tree[node];
  prog(node, start, end);
  int mid = (start + end) >> 1;
  return query(node + node, start, mid) + query(node + node + 1, mid + 1, end);
}

void update(int node, int start, int end) {
  if (from > end || to < start) return;
  if (from <= start && end <= to) {
    lazy[node]++;
    tree[node] += end - start + 1;
    return;
  }
  prog(node, start, end);
  int mid = (start + end) >> 1;
  update(node + node, start, mid);
  update(node + node + 1, mid + 1, end);
  tree[node] = tree[node + node] + tree[node + node + 1];
}

void solve(int test_num) {
  memset(lazy, 0, sizeof (lazy));
  memset(tree, 0, sizeof (tree));
  int len, quests, size = 1;
  scanf("%d %d", &len, &quests);
  while (size < len)
    size <<= 1;
  printf("Scenario #%d:\n", test_num);
  for (int q = 0; q < quests; q++) {
    scanf("%s %d %d", str, &from, &to);
    from--, to--;
    if (str[0] == 'a') printf("%lld\n", query(1, 0, size - 1));
    else update(1, 0, size - 1), puts("OK");
  }
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
  CDC12_H::solve();
  return 0;
}

