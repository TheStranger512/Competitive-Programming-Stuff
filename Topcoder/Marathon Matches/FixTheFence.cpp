/*
 *
 * File:   FixTheFence.cpp
 * Author: Andy Y.F. Huang
 * Created on March 10, 2013, 4:20 PM
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

struct FixTheFence {
  int rows, cols;
  char grid[111][111];

  string findLoop(vector <string> diagram) {
    stringstream ss;
    ss << "0 0 ";
    rows = diagram.size();
    cols = diagram[0].size();
    for (int r = 0; r < rows; r++)
      for (int c = 0; c < cols; c++)
        grid[r][c] = diagram[r][c];
    if (rows % 2 == 0)
      rows--;
    if (cols % 2 == 0)
      cols--;
    for (int c = 0; c < cols; c++)
      ss << 'R';
    ss << 'D';
    for (int c = cols; c > 0; c--) {
      char dir;
      if (c & 1) dir = 'D';
      else dir = 'U';
      for (int r = 1; r < rows; r++)
        ss << dir;
      ss << 'L';
    }
    for (int r = 0; r < rows; r++)
      ss << 'U';
    return ss.str();
  }
} ;
