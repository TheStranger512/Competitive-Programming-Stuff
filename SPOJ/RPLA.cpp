/* Solved
 * 11371. Answer the boss! - topological sort
 * File:   RPLA.cpp
 * Author: Andy Huang
 * Created on May 7, 2012, 1:56 PM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
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

using namespace std;

struct Point {
  int x;
  int y;

  Point(int x, int y) : x(x), y(y) {
  }

  Point() : x(0), y(0) {
  }

  bool operator<(const Point& pt) const {
    if (x != pt.x)
      return x < pt.x;
    else
      return y < pt.y;
  }

};

Point ans[1050];
short to[10050];
short next[10050];
short last[1050];
bool edgein[1050];

void dfs(int cur, int rank){
  ans[cur].x = rank;
  for (int id = last[cur]; id != -1; id = next[id]){
    int neigh = to[id];
    if (rank + 1 > ans[neigh].x)
      dfs(neigh, rank + 1);
  }
}

void solve() {
  int vertices ,edges, index = 0;
  scanf("%d %d", &vertices, &edges);
  for (int i = 0; i < vertices; i++){
    last[i] = -1;
    edgein[i] = false;
    ans[i].x = 0;
    ans[i].y = i;
  }
  for (int i = 0; i < edges; i++){
    int st, end;
    scanf("%d %d", &end, &st);
    edgein[end] = true;
    to[index] = end;
    next[index] = last[st];
    last[st] = index;
    index++;
  }
  for (int i = 0; i < vertices; i++){
    if (!edgein[i])
      dfs(i, 1);
  }
  sort(ans, ans + vertices);
  for (int i = 0; i < vertices; i++){
    printf("%d %d\n", ans[i].x, ans[i].y);
  }
}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int cases = 1; cases <= tests; cases++){
    printf("Scenario #%d:\n", cases);
    solve();
  }
  return 0;
}

