/*
 * Topcoder Marathon Match 82
 * File:   ColorLinker.cpp
 * Author: Andy Y.F. Huang
 * Created on Dec 13, 2013, 10:15:37 PM
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

struct ColorLinker {
  const static int MAXN = 61;
  const static int MAXC = 5;
  typedef vector<int> Vint;
  typedef pair<int, int> Point;
  vector<Point> pt[MAXC];
  int g[MAXN][MAXN];
  int N, PEN;

  static inline int bitcnt(int x) {
    return __builtin_popcount(x);
  }

  bool is_oob(int x, int y) {
    return min(x, y) < 0 || max(x, y) >= N;
  }

  int get_cost(int x, int y, int color) {
    const int C = bitcnt(g[x][y] | (1 << color));
    return C + C * (C - 1) * PEN;
  }

  void connect(Point a, Point b, int color, int& cost, vector<Point>& path) {
    static priority_queue<pair<int, Point> > q;
    static int dist[MAXN][MAXN];
    static Point pred[MAXN][MAXN];
    static const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
    //dbgln(a);
    //dbgln(b);
    while (!q.empty())
      q.pop();
    memset(dist, 0x3F, sizeof(dist));
    memset(pred, -1, sizeof(pred));
    dist[a.first][a.second] = 0;
    q.push(make_pair(0, a));
    for (; !q.empty();) {
      //pln(q.front().second);
      const int x = q.top().second.first, y = q.top().second.second;
      const int cdist = -q.top().first;
      q.pop();
      if (cdist > dist[x][y])
        continue;
      if (x == b.first && y == b.second)
        break;
      for (int d = 0; d < 4; d++) {
        const int nx = x + dx[d], ny = y + dy[d];
        if (!is_oob(nx, ny) && cdist + get_cost(nx, ny, color) < dist[nx][ny]) {
          dist[nx][ny] = cdist + get_cost(nx, ny, color);
          q.push(make_pair(-dist[nx][ny], Point(nx, ny)));
          pred[nx][ny] = Point(x, y);
        }
      }
    }
    //dbgln(dist[b.first][b.second]);
    cost += dist[b.first][b.second];
    for (Point p = b; p != a; p = pred[p.first][p.second])
      path.push_back(p);
    path.push_back(a);
  }

  void process(const int color, vector<Point>& pt) {
    //dbgln(pt);
    vector<Point> ord;
    int best = 1 << 30;
    for (int its = 0; its < 11; its++) {
      random_shuffle(pt.begin(), pt.end());
      int cost = 0;
      vector<Point> path;
      for (int i = 1; i < (int) pt.size(); i++)
        connect(pt[i - 1], pt[i], color, cost, path);
      //dbgln(cost);
      if (cost < best)
        ord = path;
    }
    for (const Point& p : ord)
      g[p.first][p.second] |= 1 << color;
  }

  Vint link(vector<string> grid, int penalty) {
    memset(g, 0, sizeof(g));
    N = grid.size();
    PEN = penalty;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        if (isdigit(grid[i][j])) {
          pt[grid[i][j] - '0'].push_back(Point(i, j));
          g[i][j] = 1 << (grid[i][j] - '0');
        }
    for (int c = 0; c < 5; c++)
      process(c, pt[c]);
    Vint res;
    for (int c = 0; c < 5; c++)
      for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
          if (1 << c & g[x][y]) {
            res.push_back(x);
            res.push_back(y);
            res.push_back(c);
          }
    return res;
  }
};

