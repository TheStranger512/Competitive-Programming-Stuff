/*
 * Solved
 * 4206. Fast Maximum Matching
 * File:   MATCHING.cpp
 * Author: Andy Y.F. Huang
 * Created on July 31, 2012, 4:41 PM
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
namespace MATCHING {
const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
unsigned int bytes_read = 0;
unsigned int input_index = 0;

inline char next_char() {
  if (input_index == bytes_read) {
    bytes_read = fread(input_buffer, sizeof (char) , buffer_size, stdin);
    input_buffer[bytes_read] = '\0'; //sentinel
    input_index = 0;
  }
  return input_buffer[input_index++];
}

inline int next_int() {
  char c;
  do {
    c = next_char();
  } while (c <= ' ');
  int ans = 0;
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += c - '0';
    c = next_char();
  }
  return ans;
}

template <size_t MAXL, size_t MAXR, size_t MAXE> struct BipartiteMatcher {
  #define NIL MAXL
  static const int INF = 13371337;
  int matchleft[MAXL + 1], matchright[MAXR], edgecnt, leftcnt, rightcnt;
  int last[MAXL], to[MAXE], next[MAXE];
  int dist[MAXL + 1], queue[MAXL];

  void init(int boys, int girls) {
    memset(last, -1, sizeof (last));
    edgecnt = 0;
    leftcnt = boys;
    rightcnt = girls;
  }

  void addedge(int boy, int girl) {
    to[edgecnt] = girl;
    next[edgecnt] = last[boy];
    last[boy] = edgecnt++;
  }

  bool bfs() {
    int qf = 0, qb = 0;
    for (int v = 0; v < leftcnt; v++)
      if (matchleft[v] == NIL)
        dist[queue[qb++] = v] = 0;
      else dist[v] = INF;
    for (dist[NIL] = INF; qf < qb; qf++)
      for (int at = queue[qf], e = last[at]; e > -1; e = next[e])
        if (dist[matchright[to[e]]] == INF)
          dist[queue[qb++] = matchright[to[e]]] = dist[at] + 1;
    return dist[NIL] != INF;
  }

  bool dfs(int at) {
    if (at == NIL) return true;
    for (int e = last[at]; e > -1; e = next[e])
      if (dist[matchright[to[e]]] == dist[at] + 1 && dfs(matchright[to[e]])) {
        matchleft[at] = to[e];
        matchright[to[e]] = at;
        return true;
      }
    dist[at] = INF;
    return false;
  }

  int go() {
    fill(matchleft, matchleft + leftcnt, NIL);
    fill(matchright, matchright + rightcnt, NIL);
    int matches = 0;
    for (int v = 0; v < leftcnt; v++)
      for (int e = last[v]; e > -1; e = next[e])
        if (matchright[to[e]] == NIL) {
          matchright[to[e]] = v;
          matchleft[v] = to[e];
          matches++;
          break;
        }
    while (bfs())
      for (int v = 0; v < leftcnt; v++)
        if (matchleft[v] == NIL && dfs(v))
          matches++;
    return matches;
  }
} ;

BipartiteMatcher < 50002, 50002, 155000 > bpm;

void solve(int test_num) {
  int cows = next_int(), bulls = next_int(), edges = next_int();
  bpm.init(cows, bulls);
  for (int i = 0; i < edges; i++) {
    int cow = next_int() - 1;
    int bull = next_int() - 1;
    bpm.addedge(cow, bull);
  }
  printf("%d\n", bpm.go());
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  MATCHING::solve();
  return 0;
}

