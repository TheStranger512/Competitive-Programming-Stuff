/* Solved
 * IOI '05 - Nowy Sacz, Poland
 * Mountains
 * File:   ioi0513.cpp
 * Author: Andy Y.F. Huang
 * Created on November 17, 2012, 6:54 PM
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
namespace ioi0513 {
#define sent -(1 << 30)
int vals[222222];
char op[111111];
int args[111111][3];
int sum[1 << 20] = {0}, high[1 << 20] = {0}, lazy[1 << 20] = {0};
int from, to;

inline int left(int node) {
  return node << 1;
}

inline int right(int node) {
  return (node << 1) + 1;
}

void prog(int node, int start, int end) {
  if (lazy[node] == sent) return;
  int mid = (start + end) >> 1;
  lazy[left(node)] = lazy[right(node)] = lazy[node];
  sum[left(node)] = lazy[node] * (vals[mid] - vals[start]);
  sum[right(node)] = lazy[node] * (vals[end] - vals[mid]);
  high[left(node)] = max(0, sum[left(node)]);
  high[right(node)] = max(0, sum[right(node)]);
  lazy[node] = sent;
}

/*
 * [vals[start], vals[end]] (points)
 */
void update(int node, int start, int end, int diff) {
  if (from > vals[end] || to - 1 < vals[start])
    return;
  if (from - 1 <= vals[start] && vals[end] <= to) {
    sum[node] = diff * (vals[end] - vals[start]);
    high[node] = max(0, sum[node]);
    lazy[node] = diff;
    return;
  }
  prog(node, start, end);
  int mid = (start + end) >> 1;
  update(left(node), start, mid, diff);
  update(right(node), mid, end, diff);
  sum[node] = sum[left(node)] + sum[right(node)];
  high[node] = max(high[left(node)], sum[left(node)] + high[right(node)]);
}

int find(int node, int start, int end, int val) {
  if (val >= high[node]) return vals[end];
  //pln(node, vals[start], vals[end], val);
  if (end - start == 1) {//is leaf
    if (sum[node] == 0) return vals[end];
    int diff = sum[node] / (vals[end] - vals[start]);
    return val / diff + vals[start];
  }
  prog(node, start, end);
  int mid = (start + end) >> 1;
  if (val < high[left(node)])
    return find(left(node), start, mid, val);
  else
    return find(right(node), mid, end, val - sum[left(node)]);
}

void solve(int test_num) {
  for (int i = 0; i < (1 << 20); i++)
    lazy[i] = sent;
  int len, qcnt = 0, valcnt = 0;
  scanf("%d", &len);
  vals[valcnt++] = 0;
  vals[valcnt++] = len;
  for (; ; qcnt++) {
    scanf("%s %d", op + qcnt, &args[qcnt][0]);
    if (op[qcnt] == 'E')
      break;
    if (op[qcnt] == 'I') {
      scanf("%d %d", &args[qcnt][1], &args[qcnt][2]);
      vals[valcnt++] = args[qcnt][0] - 1;
      vals[valcnt++] = args[qcnt][1];
    }
  }
  sort(vals, vals + valcnt);
  valcnt = unique(vals, vals + valcnt) - vals;
  //plnarr(vals, vals + valcnt);
  for (int q = 0; q < qcnt; q++) {
    if (op[q] == 'I') {
      from = args[q][0], to = args[q][1];
      update(1, 0, valcnt - 1, args[q][2]);
    }
    else {
      int ans = find(1, 0, valcnt - 1, args[q][0]);
      printf("%d\n", ans);
    }
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
  ioi0513::solve();
  return 0;
}

