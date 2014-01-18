/*
 * TCO 13 Round 1
 * File:   SnowCleaning.cpp
 * Author: Andy Y.F. Huang
 * Created on March 31, 2013, 3:07 PM
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

struct SnowCleaning {
  int WORKPROB;
  typedef pair<int, int> Point;
  int workers, size, sal, fine;
  vector<Point> snow, ppl;
  vector<string> commands;
  bool dirty[55][55];
  bool used[111];
  Point CORNERS[4];

  bool oob(int r, int c) {
    return r < 0 || r >= size || c < 0 || c >= size;
  }

  int nextrand(int from, int to) {
    //get random int in [from, to)
    return from + rand() % (to - from);
  }

  int dist(const Point& a, const Point & b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
  }

  int init(int boardSize, int salary, int snowFine) {
    srand(time(NULL));
    workers = 0;
    size = boardSize;
    sal = salary;
    fine = snowFine;
    if (sal > fine) WORKPROB = 17;
    else WORKPROB = 25;
    snow.clear();
    ppl.clear();
    CORNERS[0] = Point(0, 0);
    CORNERS[1] = Point(size - 1, size - 1);
    CORNERS[2] = Point(0, size - 1);
    CORNERS[3] = Point(size - 1, 0);
    //pln("size:", size);
    memset(dirty, false, sizeof (dirty));
    return 0;
  }

  void hire(int r, int c) {
    workers++;
    static char buf[111];
    sprintf(buf, "H %d %d", r, c);
    commands.push_back(string(buf));
    ppl.push_back(Point(r, c));
  }

  void move(int worker, const Point & to) {
    static const char* DIRECTION = "URDL";
    static const int DR[] = {-1, 0, 1, 0};
    static const int DC[] = {0, 1, 0, -1};
    static char buf[111];
    static int dir[] = {0, 1, 2, 3};
    used[worker] = true;
    Point at = ppl[worker];
    if (at == to) {
      //right on top of snow
      dirty[at.first][at.second] = false;
      return;
    }
    random_shuffle(dir, dir + 4);
    for (int d = 0; d < 4; d++) {
      int nr = at.first + DR[dir[d]];
      int nc = at.second + DC[dir[d]];
      if (!oob(nr, nc) && dist(Point(nr, nc), to) < dist(at, to)) {
        sprintf(buf, "M %d %c", worker, DIRECTION[dir[d]]);
        //pln(worker, nr, nc);
        dirty[nr][nc] = false;
        commands.push_back(string(buf));
        ppl[worker] = Point(nr, nc);
        return;
      }
    }
  }

  void go() {
    commands.clear();
    snow.clear();
    for (int r = 0; r < size; r++)
      for (int c = 0; c < size; c++)
        if (dirty[r][c])
          snow.push_back(Point(r, c));
    random_shuffle(snow.begin(), snow.end());
    memset(used, false, sizeof (used));
    int snowcnt = snow.size();
    for (int i = 0; i < snowcnt; i++) {
      if (!dirty[snow[i].first][snow[i].second]) continue;
      int closest = -1;
      for (int j = 0; j < workers; j++)
        if (!used[j] && (closest == -1 || dist(snow[i], ppl[j]) < dist(snow[i], ppl[closest])))
          closest = j;
      if (closest == -1) break;
      move(closest, snow[i]);
    }
    for (int i = 0; i < workers; i++)
      if (!used[i])
        move(i, CORNERS[rand() & 3]);
    if (workers < size && (workers < 5 || nextrand(0, WORKPROB) == 0))
      hire(nextrand(0, size), nextrand(0, size));
    for (int i = 0; i < workers; i++)
      dirty[ppl[i].first][ppl[i].second] = false;
  }

  vector <string> nextDay(vector <int> snowFalls) {
    int len = snowFalls.size();
    for (int i = 0; i < len; i += 2)
      dirty[snowFalls[i]][snowFalls[i + 1]] = true;
    go();
    return commands;
  }
} ;


