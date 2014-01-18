/* Solved
 * 5732. Paradox
 * 2-SAT problem
 * File:   PARADOX.cpp
 * Author: Andy Y.F. Huang
 * Created on April 2, 2013, 10:35 PM
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

namespace PARADOX {

template <class T, size_t MAXSIZE> struct Stack {
  T arr[MAXSIZE], *first;

  Stack() {
    first = arr;
  }

  bool empty() {
    return first == arr;
  }

  int size() {
    return first - arr;
  }

  void clear() {
    first = arr;
  }

  void push(T val) {
    *first++ = val;
  }

  T top() {
    return *(first - 1);
  }

  void pop() {
    first--;
  }

} ;
#define INF (1 << 30)
int len;
int last[222], to[222], next[222];
int label[222], low[222], comp[222];
char str[11];
int edgecnt = 0;
Stack<int, 222 > stck;

int nextnum() {
  static int NUM = 0;
  return NUM++;
}

void scc(int at) {
  label[at] = low[at] = nextnum();
  stck.push(at);
  for (int e = last[at]; e > -1; e = next[e]) {
    if (label[to[e]] == -1) scc(to[e]);
    low[at] = min(low[at], low[to[e]]);
  }
  if (label[at] == low[at]) {
    comp[at] = at;
    low[at] = INF;
    for (; stck.top() != at; stck.pop()) {
      comp[stck.top()] = at;
      low[stck.top()] = INF;
    }
    stck.pop();
  }
}

void addedge(int a, int b) {
  to[edgecnt] = b;
  next[edgecnt] = last[a];
  last[a] = edgecnt++;
}

void solve(int test_num) {
  memset(label, -1, sizeof (label));
  memset(last, -1, sizeof (last));
  edgecnt = 0;
  for (int i = 1, b; i <= len; i++) {
    scanf("%d %s", &b, str);
    addedge(i, str[0] == 't' ? b : b + len);
    addedge(i + len, str[0] == 't' ? b + len : b);
  }
  for (int i = 1; i <= len + len; i++)
    if (label[i] == -1)
      scc(i);
  for (int i = 1; i <= len; i++)
    if (comp[i] == comp[i + len]) {
      puts("PARADOX");
      return;
    }
  puts("NOT PARADOX");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%d", &len) != EOF)
    if (len != 0)
      solve(1);

}
}

int main() {
  PARADOX::solve();
  return 0;
}

