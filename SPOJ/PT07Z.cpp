/* Solved
 * 1437. Longest path in a tree
 * File:   PT07Z.cpp
 * Author: Andy Y.F. Huang
 * Created on August 8, 2012, 4:50 PM
 */

#include <cstdio>
#include <cstring>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace PT07Z {
int index, last[10010], to[20010], next[20010], dist[10010];

void dfs(int cur, int depth) {
  dist[cur] = depth;
  for (int i = last[cur]; i != -1; i = next[i])
    if (depth + 1 < dist[to[i]])
      dfs(to[i], depth + 1);
}

void addedge(int start, int end) {
  to[index] = end;
  next[index] = last[start];
  last[start] = index++;
  to[index] = start;
  next[index] = last[end];
  last[end] = index++;
}

void solve(int test_num) {
  memset(last, 0xFF, sizeof (last));
  memset(dist, 0x3F, sizeof (dist));
  int nodes, maxnode = 0, ans = 0;
  index = 0;
  scanf("%d", &nodes);
  for (int i = 0; i < nodes - 1; i++) {
    int start, end;
    scanf("%d %d", &start, &end);
    addedge(--start, --end);
  }
  dfs(0, 0);
  for (int i = 0; i < nodes; i++)
    if (dist[i] > dist[maxnode])
      maxnode = i;
  //plnarr(dist, dist + nodes);
  memset(dist, 0x3F, sizeof (dist));
  dfs(maxnode, 0);
  for (int i = 0; i < nodes; i++)
    if (dist[i] > ans)
      ans = dist[i];
  printf("%d\n", ans);
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
  PT07Z::solve();
  return 0;
}

