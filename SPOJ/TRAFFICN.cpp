/* Solved
 * 3643. Traffic Network - dijkstra
 * File:   TRAFFICN.cpp
 * Author: Andy Y.F. Huang
 * Created on September 4, 2012, 9:02 PM
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
namespace TRAFFICN {

struct Node {
  int cur, dist0, dist1;

  Node(int cur, int dist0, int dist1) : cur(cur), dist0(dist0), dist1(dist1) { }

  bool operator<(const Node & n) const {
    return dist0 != n.dist0 ? dist0 > n.dist0 : dist1 > n.dist1;
  }
} ;

int last[10010], to[100810], next[100810], cost[100810];
int dist[10010][2]; //0 - no new roads, 1 - new road built
bool newroad[100810];
priority_queue<Node> q;
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

inline int next_int() {
  char c = 0;
  int ans = 0;
  while (c < '0') c = next_char();
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += char_to_int[c];
    c = next_char();
  }
  return ans;
}

void solve(int test_num) {
  memset(dist, 0x3F, sizeof (dist));
  memset(last, 0xFF, sizeof (last));
  memset(newroad, false, sizeof (newroad));
  int vertices, edges, propos, src, dest;
  vertices = next_int(), edges = next_int(), propos = next_int();
  src = next_int(), dest = next_int();
  //scanf("%d %d %d %d %d", &vertices, &edges, &propos, &src, &dest);
  for (int i = 0; i < edges; i++) {
    int start, end;
    start = next_int(), end = next_int(), cost[i] = next_int();
    //scanf("%d %d %d", &start, &end, &cost[i]);
    to[i] = end;
    next[i] = last[start];
    last[start] = i;
  }
  for (int i = 0, j = edges; i < propos; i++) {
    int start, end;
    start = next_int(), end = next_int(), cost[j] = next_int();
    //scanf("%d %d %d", &start, &end, &cost[i + edges]);
    cost[j + 1] = cost[j];
    newroad[j] = newroad[j + 1] = true;
    to[j] = end;
    next[j] = last[start];
    last[start] = j++;
    to[j] = start;
    next[j] = last[end];
    last[end] = j++;
  }
  dist[src][0] = 0;
  q.push(Node(src, 0, 123456789));
  while (!q.empty()) {
    int cur = q.top().cur, dist0 = q.top().dist0, dist1 = q.top().dist1;
    q.pop();
    if (dist0 > dist[cur][0] && dist1 > dist[cur][1])
      continue;
    for (int i = last[cur]; i != -1; i = next[i]) {
      if (newroad[i]) {
        int ndist1 = dist0 + cost[i];
        if (ndist1 < dist[to[i]][1]) {
          dist[to[i]][1] = ndist1;
          q.push(Node(to[i], dist[to[i]][0], ndist1));
        }
      }
      else {
        int ndist0 = dist0 + cost[i];
        int ndist1 = dist1 + cost[i];
        bool shorter = false;
        if (ndist0 < dist[to[i]][0]) {
          dist[to[i]][0] = ndist0;
          shorter = true;
        }
        if (ndist1 < dist[to[i]][1]) {
          dist[to[i]][1] = ndist1;
          shorter = true;
        }
        if (shorter)
          q.push(Node(to[i], dist[to[i]][0], dist[to[i]][1]));
      }
    }
  }
  if (dist[dest][0] >= 123456789 || dist[dest][1] >= 123456789)
    puts("-1");
  else
    printf("%d\n", min(dist[dest][0], dist[dest][1]));
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
  TRAFFICN::solve();
  return 0;
}

