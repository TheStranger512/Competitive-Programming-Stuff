/* Solved
 * 4226. Japan
 * File:   MSE06H.cpp
 * Author: Andy Y.F. Huang
 * Created on July 30, 2012, 11:17 PM
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
namespace MSE06H {
struct Road {
  int left, right;

  bool operator<(const Road& o) const {
    if (o.left != left)
      return left < o.left;
    else
      return right < o.right;
  }

};

const int k_max_len = 1010;
long long tree[k_max_len];
Road roads[k_max_len * k_max_len];

void update(int pos, int val, int size) {
  for (int i = pos; i < size; i |= (i + 1))
    tree[i] += val;
}

long long query(int pos) {
  long long ans = 0;
  for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
    ans += tree[i];
  return ans;
}

void solve(int test_num) {
  memset(tree, 0, sizeof (tree));
  int west, east, size;
  long long ans = 0;
  scanf("%d %d %d", &west, &east, &size);
  for (int i = 0; i < size; i++)
    scanf("%d %d", &roads[i].left, &roads[i].right);
  sort(roads, roads + size);
  for (int i = 0; i < size; i++) {
    ans += i - query(roads[i].right);
    update(roads[i].right, 1, east + 1);
  }
  printf("Test case %d: %lld\n", test_num, ans);
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
  MSE06H::solve();
  return 0;
}

