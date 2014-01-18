/* Solved
 * 8002. Horrible Queries - segment tree with lazy propagation
 * File:   HORRIBLE.cpp
 * Author: Andy Y.F. Huang
 * Created on September 7, 2012, 10:55 PM
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
#include <ctime>
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
namespace HORRIBLE {
const int k_max_len = 100010;
long long tree[3 * k_max_len], lazy[3 * k_max_len];
long long aux[k_max_len];

void update(int node, int start, int end, int ui, int uj, int val) {
  if (ui > end || uj < start)
    return;
  if (ui <= start && end <= uj)
    lazy[node] += val;
  else {
    tree[node] += 1LL * val * (min(end, uj) - max(start, ui) + 1);
    update(node << 1, start, (start + end) >> 1, ui, uj, val);
    update((node << 1) + 1, ((start + end) >> 1) + 1, end, ui, uj, val);
  }
}

long long query(int node, int start, int end, int qi, int qj) {
  if (qi > end || qj < start)
    return 0;
  if (qi <= start && end <= qj)
    return lazy[node] * (end - start + 1) + tree[node];
  tree[node] += lazy[node] * (end - start + 1);
  lazy[node << 1] += lazy[node], lazy[(node << 1) + 1] += lazy[node];
  lazy[node] = 0;
  return query(node << 1, start, (start + end) >> 1, qi, qj)
          + query((node << 1) + 1, ((start + end) >> 1) + 1, end, qi, qj);
}

void slowupdate(int start, int end, int val) {
  for (int i = start; i <= end; i++)
    aux[i] += val;
}

long long slowquery(int start, int end) {
  long long ans = 0;
  for (int i = start; i <= end; i++)
    ans += aux[i];
  return ans;
}

void solve(int test_num) {
  memset(tree, 0, sizeof (tree));
  memset(lazy, 0, sizeof (lazy));
  #ifdef AZN
  memset(aux, 0, sizeof (aux));
  #endif
  int len, queries;
  scanf("%d %d", &len, &queries);
  for (int i = 1; i <= queries; i++) {
    int type, start, end, val;
    scanf("%d %d %d", &type, &start, &end);
    start--, end--;
    if (start > end)
      swap(start, end);
    if (type == 0) {
      scanf("%d", &val);
      update(1, 0, len - 1, start, end, val);
      #ifdef AZN
      slowupdate(start, end, val);
      #endif
    }
    else {
      long long ans = query(1, 0, len - 1, start, end);
      printf("%lld\n", ans);
      #ifdef AZN
      long long realans = slowquery(start, end);
      if (ans != realans) {
        pln(i, start, end, ans, realans);
        assert(false);
      }
      #endif
    }
    //plnarr(aux, aux + len);
  }
}

void makecase() {
  srand(time(NULL));
  freopen("input.txt", "w", stdout);
  int len = 1000, queries = 1000;
  printf("1\n%d %d\n", len, queries);
  for (int q = 0; q < queries; q++) {
    int type, start, end, val;
    type = rand() % 2;
    start = rand() % len + 1;
    end = rand() % len + 1;
    if (end < start)
      swap(start, end);
    if (type == 0) {
      val = rand() % 1000 + 1;
      printf("0 %d %d %d\n", start, end, val);
    }
    else
      printf("1 %d %d\n", start, end);
  }
}

void solve() {
  #ifdef AZN
  //makecase();
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
  HORRIBLE::solve();
  return 0;
}

