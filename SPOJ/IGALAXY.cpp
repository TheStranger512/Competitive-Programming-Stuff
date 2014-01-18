/* Solved
 * 11952. Intergalactic Highways - bfs
 * File:   IGALAXY.cpp
 * Author: Andy Y.F. Huang
 * Created on August 9, 2012, 12:02 AM
 */

#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace IGALAXY {

struct Compare {

  bool operator()(const char* a, const char* b) const {
    return strcmp(a, b) < 0;
  }
} ;

vector<int> graph[10010];
int dist[10010], prev[10010], path[10010];
char namea[100010][60], nameb[100010][60];
const char* idtoname[10010];
map<const char*, int, Compare> hash;
map<const char*, int, Compare>::iterator iter;

void bfs(int test_num, int start, int end) {
  queue<int> q;
  memset(dist, 0x3F, sizeof (dist));
  memset(prev, 0xFF, sizeof (prev));
  dist[start] = 1;
  q.push(start);
  while (!q.empty()) {
    int cur = q.front(), cdist = dist[cur];
    q.pop();
    for (unsigned i = 0; i < graph[cur].size(); i++) {
      if (cdist + 1 < dist[graph[cur][i]]) {
        dist[graph[cur][i]] = cdist + 1;
        prev[graph[cur][i]] = cur;
        q.push(graph[cur][i]);
      }
    }
  }
  if (prev[end] == -1) {
    printf("Scenario #%d: -1\n", test_num);
    return;
  }
  int len = 0, cur = end;
  while (cur != -1) {
    path[len++] = cur;
    cur = prev[cur];
  }
  printf("Scenario #%d: %d\n", test_num, dist[end]);
  printf("%s", idtoname[path[len - 1]]);
  for (int i = len - 2; i >= 0; i--)
    printf(" %s", idtoname[path[i]]);
  putchar('\n');
}

void solve(int test_num) {
  hash.clear();
  for (int i = 0; i <= 10000; i++)
    if (graph[i].size() > 0)
      graph[i].clear();
  int edges, cur = 1;
  char start[100], end[100];
  scanf("%d", &edges);
  for (int i = 0; i < edges; i++) {
    scanf("%s %s", namea[i], nameb[i]);
    hash[namea[i]] = -1;
    hash[nameb[i]] = -1;
  }
  scanf("%s %s", start, end);
  for (iter = hash.begin(); iter != hash.end(); ++iter) {
    idtoname[cur] = iter->first;
    iter->second = cur++;
  }
  if (!hash.count(start) || !hash.count(end)) {
    printf("Scenario #%d: -1\n", test_num);
    return;
  }
  for (int i = 0; i < edges; i++) {
    int a = hash[namea[i]];
    int b = hash[nameb[i]];
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = 1; i <= cur; i++)
    if (graph[i].size() > 0)
      sort(graph[i].begin(), graph[i].end());
  bfs(test_num, hash[start], hash[end]);
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
  IGALAXY::solve();
  return 0;
}

