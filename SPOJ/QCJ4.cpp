/* Solved
 * 6044. Minimum Diameter Circle
 * File:   QCJ4.cpp
 * Author: Andy Y.F. Huang
 * Created on September 3, 2012, 4:57 PM
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
namespace QCJ4 {

struct Point {
  int x, y;

  double dist(const Point & p) const {
    return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
  }

  friend ostream& operator<<(ostream& out, const Point & p ) {
    return out << '(' << p.x << ',' << p.y << ')';
  }
} ;

const double eps = 1e-8;
int len;
Point pts[350];

inline double dist(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

inline double crossProduct(const Point& a, const Point& b, const Point& c) {
  return abs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
}

void solve(int test_num) {
  scanf("%d", &len);
  double ans = 0.0;
  for (int i = 0; i < len; i++)
    scanf("%d %d", &pts[i].x, &pts[i].y);
  for (int i = 0; i < len; i++)  //cirle with two points
    for (int j = i + 1; j < len; j++)
      ans = max(ans, sqrt(pts[i].dist(pts[j])));
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      for (int k = j + 1; k < len; k++) {
        double a = pts[i].dist(pts[j]);
        double b = pts[i].dist(pts[k]);
        double c = pts[j].dist(pts[k]);
        if (c > a + b || b > a + c || a > b + c) //obtuse triangle
          continue;
        a = sqrt(a), b = sqrt(b), c = sqrt(c);
        ans = max(ans, a * b * c / crossProduct(pts[i], pts[j], pts[k]));
      }
    }
  }
  printf("%.2f\n", ans);
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
  QCJ4::solve();
  return 0;
}

