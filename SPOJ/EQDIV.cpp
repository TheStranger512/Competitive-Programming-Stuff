/* Solved
 * 1000. Equidivisions
 * File:   EQDIV.cpp
 * Author: Andy Y.F. Huang
 * Created on April 25, 2013, 8:25 PM
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

namespace EQDIV {

template <class T, size_t MAXSIZE> struct Queue {
  T q[MAXSIZE], *qf, *qb;

  Queue() : qf(q), qb(q) { }

  void clear() {
    qf = qb = q;
  }

  void push(T val) {
    *qb++ = val;
  }

  bool empty() {
    return qf >= qb;
  }

  int size() {
    return qb - qf;
  }

  void pop() {
    qf++;
  }

  T front() {
    return *qf;
  }

} ;

typedef pair<int, int> Node;
const char* DELIMS = " \r\t\n";
const int DR[4] = {1, 0, -1, 0};
const int DC[4] = {0, 1, 0, -1};
char temp[1111];
int size;
bool vis[111][111];
int num[111][111];
Queue<Node, 111 > q;

void solve(int test_num) {
  memset(vis, false, sizeof (vis));
  memset(num, -1, sizeof (num));
  for (int c = 1; c < size; c++) {
    gets(temp);
    char* p = strtok(temp, DELIMS);
    for (int i = 0; i < size; p = strtok(NULL, DELIMS), i++) {
      int a = atoi(p);
      p = strtok(NULL, DELIMS);
      int b = atoi(p);
      num[a][b] = c;
    }
  }
  for (int r = 1; r <= size; r++)
    for (int c = 1; c <= size; c++)
      if (num[r][c] == -1)
        num[r][c] = size;
  bool ok = true;
  for (int r = 1; r <= size; r++) {
    for (int c = 1; c <= size; c++) {
      if (vis[r][c]) continue;
      q.clear();
      int col = num[r][c], cnt = 0;
      q.push(Node(r, c));
      vis[r][c] = true;
      for (int rr, cc; !q.empty(); q.pop(), cnt++) {
        rr = q.front().first;
        cc = q.front().second;
        for (int d = 0, nr, nc; d < 4; d++) {
          nr = rr + DR[d];
          nc = cc + DC[d];
          if (num[nr][nc] == col && !vis[nr][nc]) {
            vis[nr][nc] = true;
            q.push(Node(nr, nc));
          }
        }
      }
      if (cnt != size)
        ok = false;
    }
  }
  if (ok) puts("good");
  else puts("wrong");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (gets(temp) != NULL) {
    size = atoi(strtok(temp, DELIMS));
    if (size <= 0) break;
    solve(1);
  }
}
}

int main() {
  EQDIV::solve();
  return 0;
}

