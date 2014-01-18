/* Solved
 * 372. The Benefactor
 * File:   BENEFACT.cpp
 * Author: Andy Y.F. Huang
 * Created on August 8, 2012, 4:34 PM
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
namespace BENEFACT {
int index, last[50010], to[100010], next[100010], cost[100010], dist[50010];

void dfs(int cur, int cdist) {
  dist[cur] = cdist;
  for (int id = last[cur]; id != -1; id = next[id])
    if (cdist + cost[id] < dist[to[id]])
      dfs(to[id], cdist + cost[id]);
}

void addedge(int start, int end, int len) {
  to[index] = end;
  cost[index] = len;
  next[index] = last[start];
  last[start] = index++;
  to[index] = start;
  cost[index] = len;
  next[index] = last[end];
  last[end] = index++;
}

void solve(int test_num) {
  memset(last, 0xFF, sizeof (last));
  memset(dist, 0x3F, sizeof (dist));
  index = 0;
  int towns, node = 0, ans = 0;
  scanf("%d", &towns);
  for (int i = 0; i < towns - 1; i++) {
    int start, end, len;
    scanf("%d %d %d", &start, &end, &len);
    addedge(--start, --end, len);
  }
  dfs(0, 0);
  for (int i = 0; i < towns; i++)
    if (dist[i] > dist[node])
      node = i;
  memset(dist, 0x3F, sizeof (dist));
  dfs(node, 0);
  for (int i = 0; i < towns; i++)
    if (dist[i] > ans)
      ans = dist[i];
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
  BENEFACT::solve();
  return 0;
}

