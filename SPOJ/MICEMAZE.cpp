/* Solved
 * 1845. Mice and Maze
 * File:   MICEMAZE.cpp
 * Author: Andy Y.F. Huang
 * Created on August 3, 2012, 11:26 PM
 */

#include <cstdio>
#include <cstring>
#include <algorithm>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace MICEMAZE {

void solve(int test_num) {
  int size, end, limit, edges, ans = 0;
  scanf("%d %d %d %d", &size, &end, &limit, &edges);
  int graph[size][size];
  memset(graph, 0x3F, sizeof (graph));
  for (int i = 0; i < edges; i++) {
    int from, to, cost;
    scanf("%d %d %d", &from, &to, &cost);
    graph[--from][--to] = cost;
  }
  for (int k = 0; k < size; k++)
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
  graph[--end][end] = 0;
  for (int i = 0; i < size; i++)
    ans += graph[i][end] <= limit;
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
  MICEMAZE::solve();
  return 0;
}

