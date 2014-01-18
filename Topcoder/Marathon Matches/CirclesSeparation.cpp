/*
 * 2013 TCO Marathon Round 3
 * File:   CirclesSeparation.cpp
 * Author: Andy Y.F. Huang
 * Created on June 14, 2013, 11:57 PM
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
#define MAXTIME 0.95
#else
#define MAXTIME 8
#endif

using namespace std;

struct CirclesSeparation {
  typedef vector<double> VecD;
  double x[555], y[555], r[555], m[555];
  double temp[1111];
  double maxr, maxd;
  double midx, midy;
  int N;
  VecD res;
  double best;
  int order[555];

  void go() {
    int cols = rand() % 40 + 10, rows = N / cols;
    double cx = midx - cols * maxd / 2, cy = midy - rows * maxd / 2, cost = 0;
    for (int i = 0; i < N; i++) {
      if (i % cols == 0) {
        cx = -cols * maxd / 2;
        cy += maxd;
      }
      double xi = x[order[i]], yi = y[order[i]], mi = m[order[i]];
      cost += mi * hypot(xi - cx, yi - cy);
      temp[order[i] << 1] = cx;
      temp[order[i] << 1 | 1] = cy;
      cx += maxd;
    }
    if (cost < best)
      for (int i = 0; i < N + N; i++)
        res[i] = temp[i];
  }

  double get_time() {
    return double(clock()) / CLOCKS_PER_SEC;
  }

  VecD minimumWork(VecD xx, VecD yy, VecD rr, VecD mm) {
    srand(time(NULL));
    double start_time = get_time();
    N = xx.size();
    #ifdef AZN
    pln("size:", N);
    #endif
    for (int i = 0; i < N; i++) {
      x[i] = xx[i];
      y[i] = yy[i];
      r[i] = rr[i];
      m[i] = mm[i];
    }
    res.resize(N + N);
    maxr = *max_element(r, r + N) + 1e-9;
    maxd = 2 * maxr;
    midx = accumulate(x, x + N, 0.0) / N;
    midy = accumulate(y, y + N, 0.0) / N;
    best = 1e100;
    for (int i = 0; i < N; i++)
      order[i] = i;
    go();
    for (int its = 0; its < 1000; its++) {
      random_shuffle(order, order + N);
      go();
    }
    //pln(res);
    #ifdef AZN
    pln("took:", get_time() - start_time);
    #endif
    return res;
  }
} ;

