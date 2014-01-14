/* Solved
 * PEG IOI '11 - Pattaya, Thailand
 * Race
 * File:   ioi1112.cpp
 * Author: Andy Y.F. Huang
 * Created on Aug 26, 2013, 5:33:13 PM
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

using namespace std;

namespace ioi1112 {
int head[200222], to[400111], pred[400111], len[400111];
int size[200222], big[200222];
int best[1 << 20], hash[1 << 20];
bool del[200222];
int N, K;
queue<int> q;
vector<int> all;
vector<pair<int, int> > dist; //# of edges, dist

void dfs1(int at, int par) {
  all.push_back(at);
  size[at] = 1;
  big[at] = 0;
  for (int e = head[at]; e; e = pred[e])
    if (to[e] != par && !del[to[e]]) {
      dfs1(to[e], at);
      size[at] += size[to[e]];
      big[at] = max(big[at], size[to[e]]);
    }
}

void dfs2(int at, int par, int cnt, int di) {
  if (di > K)
    return;
  dist.push_back(make_pair(cnt, di));
  for (int e = head[at]; e; e = pred[e])
    if (to[e] != par && !del[to[e]])
      dfs2(to[e], at, cnt + 1, di + len[e]);
}

void addedge(int a, int b, int l) {
  static int E = 2;
  len[E] = l;
  to[E] = b;
  pred[E] = head[a];
  head[a] = E++;
}

void solve(int test_num) {
  memset(head, 0, sizeof(head));
  scanf("%d %d", &N, &K);
  for (int e = 1, a, b, l; e < N; e++) {
    scanf("%d %d %d", &a, &b, &l);
    addedge(a, b, l);
    addedge(b, a, l);
  }
  int res = N;
  memset(best, 0, sizeof(best));
  memset(hash, -1, sizeof(hash));
  memset(del, false, sizeof (del));
  q.push(0);
  for (; !q.empty(); q.pop()) {
    int at = q.front();
    all.clear();
    dfs1(at, -1);
    int centroid = -1;
    for (int& x : all)
      if (max(big[x], (int) all.size() - size[x]) <= (int) all.size() / 2)
        centroid = x;
    del[centroid] = true;
    best[0] = 0;
    hash[0] = centroid;
    for (int e = head[centroid]; e; e = pred[e])
      if (!del[to[e]]) {
        dist.clear();
        dfs2(to[e], centroid, 1, len[e]);
        for (pair<int, int>& x : dist)
          if (hash[K - x.second] == centroid)
            res = min(res, x.first + best[K - x.second]);
        for (pair<int, int>& x : dist)
          if (hash[x.second] != centroid) {
            hash[x.second] = centroid;
            best[x.second] = x.first;
          } else
            best[x.second] = min(best[x.second], x.first);
        q.push(to[e]);
      }
  }
  printf("%d\n", res == N ? -1 : res);
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
  ioi1112::solve();
  return 0;
}
