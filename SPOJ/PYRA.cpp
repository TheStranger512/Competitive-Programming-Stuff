/* Solved
 * 6288. Treeramids
 * File:   PYRA.cpp
 * Author: Andy Y.F. Huang
 * Created on September 9, 2012, 11:55 PM
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
namespace PYRA {
int last[10010], to[20010], next[20010], ans;
bool moi[10010];

int dfs(int cur) {
  moi[cur] = true;
  int width = 0;
  for (int i = last[cur]; i != -1; i = next[i])
    if (!moi[to[i]])
      width += dfs(to[i]) + 1;
  ans += width + 1;
  return width + 1;
}

void solve(int test_num) {
  memset(last, 0xFF, sizeof (last));
  memset(moi, false, sizeof (moi));
  int nodes, index = 0;
  ans = 0;
  scanf("%d", &nodes);
  for (int i = 0; i < nodes - 1; i++) {
    int start, end;
    scanf("%d %d", &start, &end);
    to[index] = end;
    next[index] = last[start];
    last[start] = index++;
    to[index] = start;
    next[index] = last[end];
    last[end] = index++;
  }
  dfs(0);
  printf("%d\n", ans);
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
  PYRA::solve();
  return 0;
}

