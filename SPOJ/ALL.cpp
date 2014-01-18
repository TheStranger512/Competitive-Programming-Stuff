/* Solved
 * 1774. All Discs Considered
 * Topological sort
 * File:   ALL.cpp
 * Author: Andy Y.F. Huang
 * Created on September 28, 2012, 7:55 PM
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
namespace ALL {
int size[3], edges;
int last[2][50050], todvd[111111], toid[111111], next[111111], deg[2][50050];
int origdeg[2][50050], q[2][55555];

void solve(int test_num) {
  memset(last, 0xFF, sizeof (last));
  memset(origdeg, 0, sizeof (origdeg));
  for (int e = 0; e < edges; e++) {
    int a, b, dvd1 = 0, dvd2 = 0;
    scanf("%d %d", &b, &a);
    if (a > size[0])
      a -= size[0], dvd1 = 1;
    if (b > size[0])
      b -= size[0], dvd2 = 1;
    todvd[e] = dvd2;
    toid[e] = b;
    next[e] = last[dvd1][a];
    last[dvd1][a] = e;
    origdeg[dvd2][b]++;
  }
  int ans = 1 << 20, qb[2], qf[2];
  const int total = size[0] + size[1];
  for (int stdvd = 0; stdvd < 2; stdvd++) {
    int changes = 1, cur = stdvd, done = 0;
    qb[0] = qb[1] = qf[0] = qf[1] = 0;
    memcpy(deg, origdeg, sizeof (origdeg));
    for (int i = 1; i <= size[0]; i++)
      if (deg[0][i] == 0)
        q[0][qb[0]++] = i;
    for (int i = 1; i <= size[1]; i++)
      if (deg[1][i] == 0)
        q[1][qb[1]++] = i;
    //    pln(qf[0], qb[0]);
    //    pln(qf[1], qb[1]);
    while (done < total) {
      while (qf[cur] < qb[cur]) {
        int curid = q[cur][qf[cur]++];
        //pln("at", cur, cur == 0 ? curid : curid + size[0]);
        //assert(deg[cur][curid] == 0);
        done++;
        for (int idx = last[cur][curid]; idx != -1; idx = next[idx]) {
          int ndvd = todvd[idx], nid = toid[idx];
          deg[ndvd][nid]--;
          if (deg[ndvd][nid] == 0)
            q[ndvd][qb[ndvd]++] = nid;
        }
      }
      cur ^= 1;
      changes++;
    }
    ans = min(ans, changes);
  }
  printf("%d\n", ans);
}

void solve() {
  //const char* k_file = "C:/Users/Windows/Documents/Compsci/ACM-ICPC/2004 - University of Ulm Local Contest/ALL.in";
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  //freopen(k_file, "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d %d %d", &size[0], &size[1], &edges);
    if (size[0] == 0 && size[1] == 0 && edges == 0)
      break;
    solve(1);
  }
}
}

int main() {
  ALL::solve();
  return 0;
}

