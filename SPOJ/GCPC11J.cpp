/* Solved
 * 9126. Time to live
 * File:   GCPC11J.cpp
 * Author: Andy Y.F. Huang
 * Created on August 15, 2012, 3:32 PM
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
namespace GCPC11J {
const int k_max_size = 100100;
int last[k_max_size], to[k_max_size << 1], next[k_max_size << 1], index;
int dist[k_max_size];

void dfs(int cur) {
  for (int id = last[cur]; id != -1; id = next[id]) {
    if (dist[cur] + 1 < dist[to[id]]) {
      dist[to[id]] = dist[cur] + 1;
      dfs(to[id]);
    }
  }
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
  index = 0;
  int vertices;
  scanf("%d", &vertices);
  for (int i = 0; i < vertices - 1; i++) {
    int start, end;
    scanf("%d %d", &start, &end);
    addedge(start, end);
  }
  dist[0] = 0;
  dfs(0);
  int node = 0;
  for (int i = 0; i < vertices; i++)
    if (dist[i] > dist[node])
      node = i;
  memset(dist, 0x3F, sizeof (dist));
  dist[node] = 0;
  dfs(node);
  for (int i = 0; i < vertices; i++)
    if (dist[i] > dist[node])
      node = i;
  printf("%d\n", dist[node] / 2 + dist[node] % 2);
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
  GCPC11J::solve();
  return 0;
}

