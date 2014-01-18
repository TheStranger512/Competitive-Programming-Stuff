/*
 * Solved
 * 2179. ICPC Scoreboard
 * File:   ICPCS.cpp
 * Author: Andy Y.F. Huang
 * Created on January 13, 2013, 12:08 AM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ICPCS {

struct Team {
  int id, pts, pen;

  bool operator<(const Team & t) const {
    if (pts != t.pts) return pts > t.pts;
    return pen < t.pen;
  }

  friend ostream& operator<<(ostream& out, const Team & t) {
    return out << '(' << t.id << ',' << t.pts << ',' << t.pen << ')';
  }
} ;

Team orig[111], order[111];
int wrongs[111], pts[111], pen[111], rank[111];
int teams, probs;
char str[55];

bool check(int penfactor) {
  memset(order, 0, sizeof (order));
  for (int t = 0; t < teams; t++) {
    order[t].id = t;
    order[t].pts = pts[t];
    order[t].pen = pen[t] + penfactor * wrongs[t];
  }
  sort(order, order + teams);
  for (int crank = 1, i = 0; i < teams; crank++) {
    int j = i;
    while (j < teams && order[j].pts == order[i].pts && order[j].pen == order[i].pen)
      j++;
    for (; i < j; i++)
      if (rank[order[i].id] != crank)
        return false;
  }
  return true;
}

void solve(int test_num) {
  memset(orig, 0, sizeof (orig));
  memset(wrongs, 0, sizeof (wrongs));
  memset(pts, 0, sizeof (pts));
  memset(pen, 0, sizeof (pen));
  for (int t = 0; t < teams; t++) {
    orig[t].id = t;
    for (int p = 0; p < probs; p++) {
      int subs, ctime;
      scanf("%d/%s", &subs, str);
      if (str[0] == '-') continue;
      ctime = atoi(str);
      wrongs[t] += subs - 1;
      orig[t].pen += ctime + (subs - 1) * 20;
      orig[t].pts++;
      pts[t]++;
      pen[t] += ctime;
    }
  }
  sort(orig, orig + teams);
  //plnarr(orig, orig + teams);
  for (int crank = 1, i = 0; i < teams; crank++) {
    int j = i;
    while (j < teams && orig[j].pts == orig[i].pts && orig[j].pen == orig[i].pen)
      j++;
    while (i < j)
      rank[orig[i++].id] = crank;
  }
  //plnarr(rank, rank + teams);
  int ansup = 20, ansdown = 20;
  for (int low = 20, high = 1 << 20; low <= high; ) {
    int mid = (low + high) >> 1;
    if (check(mid)) {
      ansup = max(ansup, mid);
      low = mid + 1;
    }
    else high = mid - 1;
  }
  for (int low = 1, high = 20; low <= high; ) {
    int mid = (low + high) >> 1;
    if (check(mid)) {
      ansdown = min(ansdown, mid);
      high = mid - 1;
    }
    else low = mid + 1;
  }
  printf("%d ", ansdown);
  if (ansup == (1 << 20)) puts("*");
  else printf("%d\n", ansup);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d %d", &teams, &probs)) {
    if (teams == 0) break;
    solve(1);
  }
}
}

int main() {
  ICPCS::solve();
  return 0;
}

