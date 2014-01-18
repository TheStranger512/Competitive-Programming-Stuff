/* Solved
 * 913. Query on a tree II
 * File:   QTREE2.cpp
 * Author: Andy Y.F. Huang
 * Created on December 5, 2012, 11:23 PM
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
namespace QTREE2 {
#define lim 11111
int depth[lim], dist[lim], parent[15][lim], timein[lim], timeout[lim];
int last[lim], to[lim << 1], next[lim << 1], cost[lim << 1];
int azn;
char buf[55];

inline bool isanc(int a, int b) {
  return timein[a] <= timein[b] && timeout[a] >= timeout[b];
}

int getlca(int a, int b) {
  if (isanc(a, b))
    return a;
  for (int i = 14; i >= 0; i--)
    if (!isanc(parent[i][a], b))
      a = parent[i][a];
  return parent[0][a];
}

int kthancestor(int v, int k) {
  int ans = v;
  for (int i = 14; i >= 0; i--)
    if (depth[v] - depth[parent[i][ans]] <= k)
      ans = parent[i][ans];
  return ans;
}

void dfs(int cur) {
  timein[cur] = ++azn;
  for (int id = last[cur]; id; id = next[id])
    if (!timein[to[id]]) {
      parent[0][to[id]] = cur;
      depth[to[id]] = depth[cur] + 1;
      dist[to[id]] = dist[cur] + cost[id];
      dfs(to[id]);
    }
  timeout[cur] = ++azn;
}

void solve(int test_num) {
  memset(last, 0, sizeof (last));
  memset(timein, 0, sizeof (timein));
  depth[1] = dist[1] = azn = 0;
  parent[0][1] = 1;
  int len;
  scanf("%d", &len);
  for (int i = 1; i < len; i++) {
    int a;
    scanf("%d %d %d", &a, &to[i], &cost[i]);
    next[i] = last[a];
    last[a] = i;
    to[i + len] = a;
    cost[i + len] = cost[i];
    next[i + len] = last[to[i]];
    last[to[i]] = i + len;
  }
  dfs(1);
  for (int i = 1; i <= 14; i++)
    for (int j = 1; j <= len; j++)
      parent[i][j] = parent[i - 1][parent[i - 1][j]];
  while (true) {
    int a, b;
    scanf("%s", buf);
    if (buf[1] == 'O')
      break;
    scanf("%d %d", &a, &b);
    if (buf[1] == 'I')
      printf("%d\n", dist[a] + dist[b] - 2 * dist[getlca(a, b)]);
    else {
      int lca = getlca(a, b), kth;
      scanf("%d", &kth);
      if (depth[a] - depth[lca] >= kth)
        printf("%d\n", kthancestor(a, kth - 1));
      else {
        int nodes = depth[a] + depth[b] - 2 * depth[getlca(a, b)] + 1;
        printf("%d\n", kthancestor(b, nodes - kth));
      }
    }
  }
  //  plnarr(depth + 1, depth + len + 1);
  //  plnarr(dist + 1, dist + len + 1);

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
  QTREE2::solve();
  return 0;
}

