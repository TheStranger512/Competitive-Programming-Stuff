/* Solved
 * 7101. Charly And Nito
 * File:   CANDN.cpp
 * Author: Andy Y.F. Huang
 * Created on February 15, 2013, 1:32 PM
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

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace CANDN {
typedef pair<int, int> Node;
int vertices, bar, charlie, nito, edges;
int distb[5555], distc[5555], distn[5555];
int last[5555], to[333000], next[333000], len[333000];

void dijk(int* dist, int start) {
  memset(dist, 0x3F, sizeof (int) * 5555);
  priority_queue<Node, vector<Node>, greater<Node> > q;
  dist[start] = 0;
  q.push(Node(0, start));
  for (; !q.empty(); q.pop()) {
    int at = q.top().second, cdist = q.top().first;
    if (cdist > dist[at])
      continue;
    for (int id = last[at]; id != -1; id = next[id]) {
      if (cdist + len[id] < dist[to[id]]) {
        dist[to[id]] = cdist + len[id];
        q.push(Node(dist[to[id]], to[id]));
      }
    }
  }
}

void solve(int test_num) {
  memset(last, -1, sizeof (last));
  for (int e = 0; e < edges; e++) {
    int a, b;
    scanf("%d %d %d", &a, &b, len + e);
    to[e] = a;
    next[e] = last[b];
    last[b] = e;
    len[e + edges] = len[e];
    to[e + edges] = b;
    next[e + edges] = last[a];
    last[a] = e + edges;
  }
  dijk(distb, bar);
  dijk(distc, charlie);
  dijk(distn, nito);
  int best = bar;
  for (int v = 1; v <= vertices; v++)
    if (distc[v] + distb[v] == distc[bar] && distn[v] + distb[v] == distn[bar] && distb[v] > distb[best])
      best = v;
  printf("%d %d %d\n", distb[best], distc[best], distn[best]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (true) {
    scanf("%d %d %d %d %d", &vertices, &bar, &charlie, &nito, &edges);
    if (vertices == -1)
      break;
    solve(1);
  }
}
}

int main() {
  CANDN::solve();
  return 0;
}

