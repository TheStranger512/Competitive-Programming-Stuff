/* Solved
 * SPOJ 702. Barn Expansion
 * File:   EXPAND.cpp
 * Author: Andy Y.F. Huang
 * Created on Aug 11, 2013, 11:09:05 PM
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

namespace EXPAND {
template <class T, size_t MAXSIZE> struct Indexer {
  T arr[MAXSIZE];
  int len;

  void push_back(const T & val) {
    arr[len++] = val;
  }

  void process() {
    sort(arr, arr + len);
    len = unique(arr, arr + len) - arr;
  }

  int get(const T & val) {
    return lower_bound(arr, arr + len, val) - arr;
  }
};

vector<pair<int, int> > x[55555], y[55555]; //(other coordinate, index)
Indexer<int, 55555> allx, ally;
int x1[25555], y1[25555], x2[25555], y2[25555];
bool bad[25555];

void insertx(int xx, int ya, int yb, int id) {
  x[xx].push_back(make_pair(ya, id));
  x[xx].push_back(make_pair(yb, id));
}

void inserty(int yy, int xa, int xb, int id) {
  y[yy].push_back(make_pair(xa, id));
  y[yy].push_back(make_pair(xb, id));
}

void go(const vector<pair<int, int> >& v, int a, int b, int id) {
  //[a, b]
  int from = lower_bound(v.begin(), v.end(), make_pair(a, -1)) - v.begin();
  int to = upper_bound(v.begin(), v.end(), make_pair(b, -1)) - v.begin();
  for (int i = from; i < to; i++) {
    if (v[i].second != id) {
      bad[id] = true;
      bad[v[i].second] = true;
    }
  }
}

void solve(int test_num) {
  allx.len = 0;
  ally.len = 0;
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d %d", x1 + i, y1 + i, x2 + i, y2 + i);
    allx.push_back(x1[i]);
    allx.push_back(x2[i]);
    ally.push_back(y1[i]);
    ally.push_back(y2[i]);
  }
  allx.process();
  ally.process();
  const int X = allx.len, Y = ally.len;
  for (int i = 0; i < X; i++)
    if (!x[i].empty())
      x[i].clear();
  for (int i = 0; i < Y; i++)
    if (!y[i].empty())
      y[i].clear();
  for (int i = 0; i < N; i++) {
    x1[i] = allx.get(x1[i]);
    x2[i] = allx.get(x2[i]);
    y1[i] = ally.get(y1[i]);
    y2[i] = ally.get(y2[i]);
    insertx(x1[i], y1[i], y2[i], i);
    insertx(x2[i], y1[i], y2[i], i);
    inserty(y1[i], x1[i], x2[i], i);
    inserty(y2[i], x1[i], x2[i], i);
  }
  for (int i = 0; i < X; i++)
    sort(x[i].begin(), x[i].end());
  for (int i = 0; i < Y; i++)
    sort(y[i].begin(), y[i].end());
  memset(bad, false, sizeof(bad));
  for (int i = 0; i < N; i++) {
    int a = x1[i], b = y1[i], m = x2[i], n = y2[i];
    go(x[a], b, n, i);
    go(x[m], b, n, i);
    go(y[b], a, m, i);
    go(y[n], a, m, i);
  }
  int res = count(bad, bad + N, false);
  printf("%d\n", res);
}

void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  EXPAND::solve();
  return 0;
}
