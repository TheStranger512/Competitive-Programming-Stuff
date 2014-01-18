/* Solved
 * 1435. Vertex Cover
 * File:   PT07X.cpp
 * Author: Andy Y.F. Huang
 * Created on August 10, 2012, 11:02 PM
 */

#include <cstdio>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace PT07X {
const int k_max_size = 100010;
bool marked[k_max_size] = {0}, visited[k_max_size] = {0};
int last[k_max_size] = {0}, to[k_max_size << 1], next[k_max_size << 1];
int ans = 0;

void addedge(int start, int end) {
  static int index = 1;
  to[index] = end;
  next[index] = last[start];
  last[start] = index++;
  to[index] = start;
  next[index] = last[end];
  last[end] = index++;
}

void dfs(int cur) {
  visited[cur] = true;
  for (int i = last[cur]; i != 0; i = next[i]) {
    if (!visited[to[i]]) {
      dfs(to[i]);
      if (!marked[cur] && !marked[to[i]]) {
        marked[cur] = true;
        ans++;
      }
    }
  }
}

void solve(int test_num) {
  int nodes;
  scanf("%d", &nodes);
  for (int i = 0; i < nodes; i++) {
    int start, end;
    scanf("%d %d", &start, &end);
    addedge(start, end);
  }
  dfs(1);
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
  PT07X::solve();
  return 0;
}

