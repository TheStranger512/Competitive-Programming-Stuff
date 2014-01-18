/*
 * Solved
 * 2528. Monkey Vines
 * File:   GNY07F.cpp
 * Author: Andy Y.F. Huang
 * Created on January 26, 2013, 1:17 PM
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

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace GNY07F {
char line[555];
int match[555], len;
stack<int> st;

inline int lcm(int a, int b) {
  return a * b / __gcd(a, b);
}

int rec(int pos, int width) {
  if (width == 0) return 1;
  if (width == 2) return 2;
  int a = match[pos + 1];
  int lef = rec(pos + 1, a - pos), rig = 0;
  if (a + 1 < pos + width - 1) {
    rig = rec(a + 1, match[a + 1] - a);
    return 2 * lcm(lef, rig);
  }
  else return 2 * lef;
}

void solve(int test_num) {
  cin.getline(line, 550);
  len = strlen(line);
  for (int i = 0; i < len; i++) {
    if (line[i] == '[')
      st.push(i);
    else  {
      match[st.top()] = i;
      match[i] = st.top();
      st.pop();
    }
  }
  printf("%d %d\n", test_num, rec(0, len));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  cin.ignore();
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  GNY07F::solve();
  return 0;
}

