/* Solved
 * 7259. Light Switching
 * File:   LITE.cpp
 * Author: Andy Y.F. Huang
 * Created on November 22, 2012, 11:44 PM
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
namespace LITE {
int tree[1 << 19] = {0}, lazy[1 << 19] = {0};
int len, quests;

inline int left(int node) {
  return node << 1;
}

inline int right(int node) {
  return (node << 1) + 1;
}

/**
 * updates children
 */
void prop(int node, int start, int end) {
  if (!lazy[node]) return;
  lazy[node] = 0;
  int mid = (start + end) / 2;
  lazy[left(node)] ^= 1;
  lazy[right(node)] ^= 1;
  tree[left(node)] = (mid - start + 1) - tree[left(node)];
  tree[right(node)] = (end - mid) - tree[right(node)];
}

int query(int node, int start, int end, int qi, int qj) {
  if (qi > end || qj < start) return 0;
  if (qi <= start && end <= qj) return tree[node];
  prop(node, start, end);
  int mid = (start + end) >> 1;
  return query(left(node), start, mid, qi, qj) + query(right(node), mid + 1, end, qi, qj);
}

void update(int node, int start, int end, int ui, int uj) {
  if (ui > end || uj < start) return;
  if (ui <= start && end <= uj) {
    lazy[node] ^= 1;
    tree[node] = (end - start + 1) - tree[node];
  }
  else {
    prop(node, start, end);
    int mid = (start + end) >> 1;
    update(left(node), start, mid, ui, uj);
    update(right(node), mid + 1, end, ui, uj);
    tree[node] = tree[left(node)] + tree[right(node)];
  }
}

void solve(int test_num) {
  scanf("%d %d", &len, &quests);
  for (int q = 0; q < quests; q++) {
    int type, a, b;
    scanf("%d %d %d", &type, &a, &b);
    if (type == 0) {
      update(1, 1, len, a, b);
    }
    else {
      printf("%d\n", query(1, 1, len, a, b));
    }
    //plnarr(tree + 1, tree + len + len);
  }
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
  LITE::solve();
  return 0;
}

