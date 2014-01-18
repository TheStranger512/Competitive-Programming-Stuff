/*
 * Test MM 2
 * File:   StringConnectivity.cpp
 * Author: Andy Y.F. Huang
 * Created on May 19, 2013, 4:06 PM
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

struct StringConnectivity {
  #define DOWN 3
  #define LEFT 2
  #define RIGHT 0
  #define UP 1
  typedef vector<int> VecInt;

  VecInt placeString(string str) {
    int len = (int) sqrt(str.size());
    VecInt res;
    res.push_back(0);
    res.push_back(0);
    for (int r = 0; r < len; r++) {
      if (r > 0)
        res.push_back(DOWN);
      for (int c = 0; c < len - 1; c++)
        res.push_back((r & 1) ? LEFT : RIGHT);
    }
    //pln(str.size(), res.size());
    return res;
  }
} ;

