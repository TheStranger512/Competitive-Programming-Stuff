/* Solved
 * 3377. A Bug’s Life - testing bipartiteness
 * File:   BUGLIFE.cpp
 * Author: Andy Y.F. Huang
 * Created on July 31, 2012, 6:57 PM
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

namespace Int_Input {
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
  char c;
  do {
    c = next_char();
  } while (c <= ' ');
  int ans = 0;
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += char_to_int[c];
    c = next_char();
  }
  return  ans;
}
}

using namespace std;
using namespace Int_Input;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace BUGLIFE {
const int k_max_bugs = 2010;
int graph[k_max_bugs][k_max_bugs], degree[k_max_bugs];
int label[k_max_bugs];

void solve(int test_num) {
  printf("Scenario #%d:\n", test_num);
  memset(degree, 0, sizeof (degree));
  memset(label, 0xFF, sizeof (label));
  int bugs = next_int(), interactions = next_int();
  while (interactions--) {
    int a = next_int(), b = next_int();
    graph[a][degree[a]++] = b;
    graph[b][degree[b]++] = a;
  }
  queue<int> q;
  for (int bug = 1; bug <= bugs; bug++) {
    if (label[bug] != -1)
      continue;
    label[bug] = 0;
    q.push(bug);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int i = 0; i < degree[cur]; i++) {
        int to = graph[cur][i];
        if (label[to] == label[cur]) {
          puts("Suspicious bugs found!");
          return;
        }
        if (label[to] == -1) {
          label[to] = (label[cur] ^ 1);
          q.push(to);
        }
      }
    }
  }
  puts("No suspicious bugs found!");
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
  BUGLIFE::solve();
  return 0;
}

