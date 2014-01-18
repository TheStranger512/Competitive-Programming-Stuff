/* Solved
 * 30. Bytelandian Blingors Network - MST
 * File:   BLINNET.cpp
 * Author: Andy Huang
 * Created on May 21, 2012, 12:51 AM
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

template <typename Type> inline void pf(Type x) {
  #ifdef DEBUG
  std::cout << x;
  #endif
}

template <typename Type> inline void pln(Type x) {
  #ifdef DEBUG
  std::cout << x << std::endl;
  #endif
}

using namespace std;

struct Edge {
  short to;
  short from;
  int cost;

  Edge(short to, short from, int cost) : to(to), from(from), cost(cost) {
  }

  bool operator<(const Edge & other) const {
    return cost < other.cost;
  }

};

vector<Edge> edges;
int vertex[10050];
int numVertices;
char cityname[50];

void unite(int root1, int root2) {
  if (vertex[root2] < vertex[root1])
    vertex[root1] = root2;
  else {
    if (vertex[root1] == vertex[root2])
      vertex[root1]--;
    vertex[root2] = root1;
  }
}

int find(int x) {
  if (vertex[x] < 0)
    return x;
  vertex[x] = find(vertex[x]);
  return vertex[x];
}

int kruskals() {
  sort(edges.begin(), edges.end());
  for (int i = 0; i <= numVertices; i++)
    vertex[i] = -1;
  int totalcost = 0;
  int cur = 0;
  int len = edges.size();
  while (cur < len) {
    int a = -1;
    int b = -1;
    while (cur < len && (a = find(edges[cur].from)) == (b = find(edges[cur].to)))
      cur++;
    if (cur == len)
      break;
    totalcost += edges[cur].cost;
    unite(a, b);
  }
  return totalcost;
}

void solve() {
  edges.clear();
  scanf("%d", &numVertices);
  for (short i = 1; i <= numVertices; i++) {
    int degree;
    scanf("%s %d", cityname, &degree);
    while (degree--) {
      int to, cost;
      scanf("%d %d", &to, &cost);
      edges.push_back(Edge(to, i, cost));
    }
  }
  printf("%d\n", kruskals());
}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  while (tests--)
    solve();
  return 0;
}

