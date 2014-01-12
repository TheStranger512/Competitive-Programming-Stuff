/* Solved
 * 11985. Gao on a tree
 * File:   GOT.cpp
 * Author: Andy Y.F. Huang
 * Created on January 23, 2013, 2:00 PM
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

namespace GOT {
#define MAXLOG 16
#define MAX 100100
int len, quests;
int last[MAX], to[2 * MAX], next[2 * MAX];
int label[MAX];
int timein[MAX], timeout[MAX], top[MAX], pos[MAX], size[MAX], par[17][MAX];
int curtime, curpos, maxlog;
int vals[MAX];
int pool[MAX], *vec[MAX], cnt[MAX], *iptr;

bool isanc(int a, int b) {
  return timein[a] <= timein[b] && timeout[b] <= timeout[a];
}

int getlca(int a, int b) {
  if (isanc(a, b))
    return a;
  for (int i = maxlog; i >= 0; i--)
    if (!isanc(par[i][a], b))
      a = par[i][a];
  return par[0][a];
}

void dfs1(int at) {
  timein[at] = ++curtime;
  for (int id = last[at]; id > -1; id = next[id]) {
    if (to[id] != par[0][at]) {
      par[0][to[id]] = at;
      dfs1(to[id]);
      size[at] += size[to[id]];
    }
  }
  timeout[at] = ++curtime;
}

void dfs2(int at, int ctop) {
  top[at] = ctop;
  pos[at] = curpos++;
  int heavy = -1;
  for (int e = last[at]; e > -1; e = next[e])
    if (to[e] != par[0][at] && (heavy == -1 || size[to[e]] > size[heavy]))
      heavy = to[e];
  if (heavy == -1) return;
  dfs2(heavy, ctop);
  for (int e = last[at]; e > -1; e = next[e])
    if (to[e] != par[0][at] && to[e] != heavy)
      dfs2(to[e], to[e]);
}

bool have(int col, int l, int r) {
  int pos = lower_bound(vec[col], vec[col] + cnt[col], l) - vec[col];
  if (pos < cnt[col] && vec[col][pos] <= r)
    return true;
  else return false;
}

bool query(int a, int b, int col) {
  //b is ancestor of a
  while (top[a] != top[b]) {
    if (have(col, pos[top[a]], pos[a]))
      return true;
    a = par[0][top[a]];
  }
  return have(col, pos[b], pos[a]);
}

void solve(int test_num) {
  for (int i = 1; i <= len; i++) {
    scanf("%d", label + i);
    vals[i - 1] = label[i];
    last[i] = par[0][i] = -1;
    size[i] = 1;
    cnt[i - 1] = 0;
  }
  for (int i = 1; i < len; i++) {
    int start, end;
    scanf("%d %d", &start, &end);
    to[i] = end;
    next[i] = last[start];
    last[start] = i;
    to[i + len] = start;
    next[i + len] = last[end];
    last[end] = i + len;
  }
  sort(vals, vals + len);
  int valcnt = unique(vals, vals + len) - vals;
  curtime = curpos = 0;
  iptr = pool;
  par[0][1] = 1;
  maxlog = 1;
  while ((1 << (maxlog + 1)) <= len)
    maxlog <<= 1;
  dfs1(1);
  dfs2(1, 1);
  //pln(maxlog);
  for (int j = 1; j <= maxlog; j++)
    for (int i = 1; i <= len; i++)
      par[j][i] = par[j - 1][par[j - 1][i]];
  for (int i = 1; i <= len; i++) {
    label[i] = lower_bound(vals, vals + valcnt, label[i]) - vals;
    cnt[label[i]]++;
  }
  for (int v = 0; v < valcnt; v++) {
    vec[v] = iptr;
    iptr += cnt[v];
    cnt[v] = 0;
  }
  for (int i = 1; i <= len; i++)
    vec[label[i]][cnt[label[i]]++] = pos[i];
  for (int v = 0; v < valcnt; v++)
    sort(vec[v], vec[v] + cnt[v]);
  //plnarr(top + 1, top + len + 1);
  //plnarr(label + 1, label + len + 1);
  for (int q = 0; q < quests; q++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int index = lower_bound(vals, vals + valcnt, c) - vals;
    if (index >= valcnt || vals[index] != c)
      puts("NotFind");
    else {
      c = index;
      int lca = getlca(a, b);
      if (query(a, lca, c) || query(b, lca, c))
        puts("Find");
      else
        puts("NotFind");
    }
  }
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d", &len, &quests) != EOF)
    solve(1);
}
}

int main() {
  GOT::solve();
  return 0;
}

