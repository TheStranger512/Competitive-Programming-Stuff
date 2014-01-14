/* Solved
 * IOI '11 - Pattaya, Thailand
 * Crocodile's Underground City
 * File:   ioi1121.cpp
 * Author: Andy Y.F. Huang
 * Created on Aug 26, 2013, 6:25:09 PM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
#include <tuple>

using namespace std;

namespace ioi1121 {
typedef pair<int, int> Edge;
int d1[100111], d2[100111];
bool vis[100111];
vector<Edge> adj[100111];
priority_queue<Edge> q;

void solve(int test_num) {
  memset(d1, 0x3F, sizeof(d1));
  memset(d2, 0x3F, sizeof(d2));
  int V, E, K;
  scanf("%d %d %d", &V, &E, &K);
  for (int e = 0, a, b, c; e < E; e++) {
    scanf("%d %d %d", &a, &b, &c);
    adj[a].push_back(Edge(b, c));
    adj[b].push_back(Edge(a, c));
  }
  for (int i = 0, v; i < K; i++) {
    scanf("%d", &v);
    d1[v] = d2[v] = 0;
    q.push(Edge(0, v));
  }
  memset(vis, false, sizeof(vis));
  for (int at; !q.empty();) {
    at = q.top().second;
    q.pop();
    if (vis[at])
      continue;
    vis[at] = true;
    for (Edge& e : adj[at]) {
      bool upd = false;
      int nd = d2[at] + e.second;
      if (nd < d1[e.first]) {
        upd = true;
        d2[e.first] = d1[e.first];
        d1[e.first] = nd;
      } else if (nd < d2[e.first]) {
        upd = true;
        d2[e.first] = nd;
      }
      if (upd)
        q.push(Edge(-d2[e.first], e.first));
    }
  }
  printf("%d\n", d2[0]);
}

void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  solve(1);
}
}

int main() {
  ioi1121::solve();
  return 0;
}
