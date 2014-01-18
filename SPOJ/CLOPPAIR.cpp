/*
 * 8725. Closest Point Pair
 * File:   CLOPPAIR.cpp
 * Author: Andy Y.F. Huang
 * Created on August 23, 2012, 9:39 PM
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
namespace CLOPPAIR {

struct Point {
  int x, y, id;

  bool operator<(const Point & p) const {
    return x < p.x;
  }
} ;

bool cmpy(const Point& a, const Point& b) {
  return a.y < b.y;
}

Point pts[50050], aux[50050];
long long ans;
int ansi, ansj;

long long dist(const Point& a, const Point& b) {
  return (1LL * a.x - b.x) * (a.x - b.x) + (1LL * a.y - b.y) * (a.y - b.y);
}

void rec(int left, int right) {
  if (right - left <= 7) {
    for (int i = left; i <= right; i++) {
      for (int j = i + 1; j <= right; j++) {
        long long temp = dist(pts[i], pts[j]);
        if (temp < ans) {
          ans = temp;
          ansi = pts[i].id;
          ansj = pts[j].id;
        }
      }
    }
    sort(pts + left, pts + right + 1, cmpy);
  }
  else {
    int mid = (left + right) >> 1;
    rec(left, mid);
    rec(mid + 1, right);
    for (int i = left, j = mid + 1, z = left; z <= right; z++) {
      if (j > right || i <= mid && pts[i].y < pts[j].y)
        aux[z] = pts[i++];
      else
        aux[z] = pts[j++];
    }
    for (int i = left; i <= right; i++)
      pts[i] = aux[i];
    for (int i = left; i <= right - 5; i++) {
      for (int j = i + 1; j < i + 6; j++) {
        long long temp = dist(pts[i], pts[j]);
        if (temp < ans) {
          ans = temp;
          ansi = pts[i].id;
          ansj = pts[j].id;
        }
      }
    }
  }
}

void solve(int test_num) {
  ans = 1LL << 50;
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++, pts[i].id = i)
    scanf("%d %d", &pts[i].x, &pts[i].y);
  sort(pts, pts + len);
  rec(0, len - 1);
  printf("%d %d %.6f", min(ansi, ansj), max(ansi, ansj), sqrt(ans));
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
  CLOPPAIR::solve();
  return 0;
}

