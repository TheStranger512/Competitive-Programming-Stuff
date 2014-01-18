/* Solved
 * 26. Build the Fence - convex hull
 * File:   BSHEEP.cpp
 * Author: Andy Huang
 * Created on May 21, 2012, 1:39 PM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
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

template <typename Type> inline void pf(Type x) {
  #ifdef DEBUG
  std::cout << x;
  #endif
}

template <typename Type> inline void pln(Type x) {
  #ifdef DEBUG
  std::cout << x << std::endl;
  #endif
}

using namespace std;

struct Point {
  int x;
  int y;
  int index;

  Point(int x, int y, int index) : x(x), y(y) {
    this->index = index;
  }

  Point() {
  }

  bool operator<(const Point & pt) const {
    if (x != pt.x)
      return x < pt.x;
    else
      return y < pt.y;
  }

};

const int MAXSHEEP = 100010;
set<Point> moi;
Point sheep[MAXSHEEP];
Point hull[MAXSHEEP];
int sheeps, stindex, lenhull;

int CrossProduct(Point a, Point b, Point c) {
  return (a.x - b.x) * (a.y - c.y) - (a.x - c.x) * (a.y - b.y);
}

void findhull(int len) {
  sort(sheep, sheep + len);
  int k = 0;
  int start = 0;
  int minx = 100000;
  int miny = 100000;
  for (int i = 0; i < len; i++) {
    Point p = sheep[i];
    while (k - start >= 2 && CrossProduct(hull[k - 2], hull[k - 1], p) <= 0)
      k--;
    int x = p.x;
    int y = p.y;
    if (y < miny) {
      miny = y;
      minx = x;
      stindex = k;
    }
    else if (y == miny && x < minx) {
      minx = x;
      stindex = k;
    }
    hull[k++] = p;
  }
  k--;
  start = k;
  for (int i = len - 1; i >= 0; i--) {
    Point p = sheep[i];
    while (k - start >= 2 && CrossProduct(hull[k - 2], hull[k - 1], p) <= 0)
      k--;
    int x = p.x;
    int y = p.y;
    if (y < miny) {
      miny = y;
      minx = x;
      stindex = k;
    }
    else if (y == miny && x < minx) {
      minx = x;
      stindex = k;
    }
    hull[k++] = p;
  }
  k--;
  lenhull = k;
}

double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve() {
  moi.clear();
  scanf("%d", &sheeps);
  int sheeplen = 0;
  for (int i = 0; i < sheeps; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    Point p(x, y, i + 1);
    if (moi.count(p))
      continue;
    moi.insert(p);
    sheep[sheeplen++] = p;
  }
  if (sheeplen == 1) {
    printf("0.00\n1\n\n");
    return;
  }
  findhull(sheeplen);
  stringstream ss;
  double circum = 0.0;
  for (int i = stindex, j = 0; j < lenhull; j++, i = (i + 1) % lenhull) {
    double x1 = hull[i].x;
    double y1 = hull[i].y;
    double x2 = hull[(i + 1) % lenhull].x;
    double y2 = hull[(i + 1) % lenhull].y;
    circum += dist(x1, y1, x2, y2);
    ss << hull[i].index;
    ss << " ";
  }
  printf("%.2f\n", circum);
  printf("%s\n\n", ss.str().c_str());
}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  while (tests--)
    solve();
  return 0;
}

