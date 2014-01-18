/* Solved
 * 15. The Shortest Path - dijkstras
 * File:   SHPATH.cpp
 * Author: Andy Y.F. Huang
 * Created on July 21, 2012, 6:40 PM
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
#include <list>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace SHPATH {
const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
const unsigned int char_to_int[58] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                      11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                                      21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                                      31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                                      41, 42, 43, 44, 45, 46, 47,
                                      0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
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

inline void next_str(char* str) {
  char c;
  do {
    c = next_char();
  } while (c <= ' ');
  do {
    *str++ = c;
    c = next_char();
  } while (c > ' ');
  *str = '\0';
}

inline int next_int() {
  char c;
  do {
    c = next_char();
  } while (c <= '-');
  int ans = 0;
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += char_to_int[c];
    c = next_char();
  }
  return ans;
}

struct Edge {
  int to;
  int cost;

  Edge(int to, int cost) : to(to), cost(cost) { }

  bool operator<(const Edge & o) const {
    return cost > o.cost;
  }
} ;

struct Compare {

  bool operator()(const char* a, const char* b) const {
    return strcmp(a, b) < 0;
  }
} ;

priority_queue<Edge> q;
int last[10010], to[200010], next[200010], weight[200010], index;
int dist[10010];
char names[10010][15];

int dijk(int start, int end) {
  while (!q.empty())
    q.pop();
  memset(dist, 0x3F, sizeof (dist));
  dist[start] = 0;
  q.push(Edge(start, 0));
  while (!q.empty()) {
    Edge cur = q.top();
    q.pop();
    if (cur.cost > dist[cur.to])
      continue;
    if (cur.to == end)
      return cur.cost;
    for (int i = last[cur.to]; i != -1; i = next[i]) {
      int nto = to[i];
      int ncost = dist[cur.to] + weight[i];
      if (ncost < dist[nto]) {
        dist[nto] = ncost;
        q.push(Edge(nto, ncost));
      }
    }
  }
  assert(false);
  return -1337;
}

void solve(int test_num) {
  static char start[20];
  static char end[20];
  int cities = next_int();
  index = 0;
  map<const char*, int, Compare> hash;
  for (int i = 0; i < cities; i++) {
    next_str(names[i]);
    hash[names[i]] = i;
    last[i] = -1;
    int degree = next_int();
    while (degree--) {
      int tow, cost;
      tow = next_int() - 1;
      cost = next_int();
      to[index] = tow;
      next[index] = last[i];
      weight[index] = cost;
      last[i] = index++;
    }
  }
  int queries = next_int();
  while (queries--) {
    next_str(start);
    next_str(end);
    printf("%d\n", dijk(hash[start], hash[end]));
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests = next_int();
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  SHPATH::solve();
  return 0;
}


