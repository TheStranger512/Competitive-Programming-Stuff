/* Solved
 * 203. Potholers
 * File:   POTHOLE.cpp
 * Author: Andy Y.F. Huang
 * Created on July 31, 2012, 9:11 PM
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
namespace POTHOLE {
const int k_max_vertices = 210, k_max_edges = 40000;
long long flow[k_max_vertices][k_max_vertices] = {0};
long long excess[k_max_vertices] = {0};
int queue[k_max_vertices << 3], height[k_max_vertices] = {0};
bool active[k_max_vertices] = {false};
int last[k_max_vertices], to[k_max_edges], next[k_max_edges];

long long maxflow(int source, int sink, int vertices) {
  memset(height, 0, sizeof (height));
  memset(excess, 0, sizeof (excess));
  memset(active, false, sizeof (active));
  height[source] = vertices;
  int qf = 0, qb = 0;
  for (int i = last[source]; i != -1; i = next[i]) {
    int v = to[i];
    excess[v] = flow[source][v], excess[source] -= flow[source][v];
    flow[v][source] += flow[source][v]; //push to capacity
    flow[source][v] = 0; //flow[source][v] -= flow[source][v];
    if (v != sink)
      queue[qb++] = v, active[v] = true;
  }
  while (qf < qb) {
    int u = queue[qf], minheight = -1;
    for (int i = last[u]; i != -1 && excess[u] > 0 ; i = next[i]) {
      int v = to[i];
      if (flow[u][v] <= 0)
        continue;
      if (height[u] > height[v]) {
        long long temp = min(excess[u], flow[u][v]);
        excess[u] -= temp, excess[v] += temp;
        flow[u][v] -= temp, flow[v][u] += temp;
        if (!active[v] && v != source && v != sink)
          active[v] = true, queue[qb++] = v;
      }
      else if (minheight == -1)
        minheight = height[v];
      else
        minheight = min(minheight, height[v]);
    }
    if (excess[u] != 0)
      height[u] = minheight + 1;
    else
      active[u] = false, qf++;
  }
  long long total = 0;
  for (int i = last[sink]; i != -1; i = next[i])
    total += flow[sink][to[i]];
    //total += (flow[sink][to[i]] - flow[to[i]][sink]) >> 1;
  return total;
}

void solve(int test_num) {
  const int inf = 123456;
  memset(flow, 0, sizeof (flow));
  memset(last, 0xFF, sizeof (last));
  int vertices;
  scanf("%d", &vertices);
  for (int i = 0, j = 0; i < vertices - 1; i++) {
    int degree;
    scanf("%d", &degree);
    while (degree--) {
      int adj;
      scanf("%d", &adj);
      to[j] = --adj;
      next[j] = last[i];
      last[i] = j++;
      to[j] = i;
      next[j] = last[adj];
      last[adj] = j++;
      if (i == 0 || adj == vertices - 1)
        flow[i][adj] = 1;
      else
        flow[i][adj] = inf;
    }
  }
  printf("%lld\n", maxflow(0, vertices - 1, vertices));
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
  POTHOLE::solve();
  return 0;
}

