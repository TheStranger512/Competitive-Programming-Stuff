/* Solved
 * 338. Roads
 * File:   ROADS.cpp
 * Author: Andy Y.F. Huang
 * Created on August 9, 2012, 6:26 PM
 */

#include <cstdio>
#include <queue>
#include <cassert>
#include <cstring>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ROADS {
struct Node {
  int pos, spent;

  Node (int pos, int spent) : pos(pos), spent(spent){
  }
};
const int k_max_vertices = 101, k_max_edges = 10010, k_max_limit = 10010;
int last[k_max_vertices], to[k_max_edges], next[k_max_edges];
int len[k_max_edges], toll[k_max_edges];
int dp[k_max_vertices][k_max_limit];
queue<Node> q;

void solve(int test_num) {
  memset(last, 0xFF, sizeof (last));
  memset(dp, 0x3F, sizeof (dp));
  int vertices, limit, edges;
  scanf("%d %d %d", &limit, &vertices, &edges);
  for (int i = 0; i < edges; i++) {
    int start, end;
    scanf("%d %d %d %d", &start, &end, &len[i], &toll[i]);
    to[i] = --end;
    next[i] = last[--start];
    last[start] = i;
  }
  dp[0][0] = 0;
  q.push(Node(0, 0));
  while (!q.empty()) {
    Node cur = q.front();
    q.pop();
    for (int i = last[cur.pos]; i != -1; i = next[i]) {
      int nspent = cur.spent + toll[i];
      int nlen = dp[cur.pos][cur.spent] + len[i];
      if (nspent <= limit && nlen < dp[to[i]][nspent]) {
        dp[to[i]][nspent] = nlen;
        q.push(Node(to[i], nspent));
      }
    }
  }
  int minlen = 123456789;
  for (int i = 0; i <= limit; i++)
    minlen = min(minlen, dp[vertices - 1][i]);
  if (minlen >= 10000000)
    puts("-1");
  else
    printf("%d\n", minlen);
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
  ROADS::solve();
  return 0;
}

