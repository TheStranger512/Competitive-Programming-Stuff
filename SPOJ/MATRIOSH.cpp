/*
 * Solved
 * 999. Generalized Matrioshkas
 * File:   MATRIOSH.cpp
 * Author: Andy Y.F. Huang
 * Created on January 26, 2013, 12:23 PM
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
namespace MATRIOSH {
stack<int> st;
vector<int> vals;
char buf[111222];

void solve(int test_num) {
  while (!st.empty()) st.pop();
  vals.clear();
  //pln(buf);
  for (char* ptr = strtok(buf, " \r\t\n"); ptr != NULL; ptr = strtok(NULL, " \r\t\n"))
    vals.push_back(atoi(ptr));
  for (int i = 0; i < (int) vals.size(); i++) {
    if (vals[i] < 0)
      st.push(-vals[i]);
    else {
      if (st.empty() || vals[i] != st.top()) {
        puts(":-( Try again.");
        return;
      }
      st.pop();
    }
  }
  if (!st.empty()) {
    puts(":-( Try again.");
    return;
  }
  bool bad = false;
  st.push(-vals.front());
  for (int i = 1; i < (int) vals.size(); i++) {
    if (vals[i] > 0) {
      if (st.top() <= 0) bad = true;
      st.pop();
    }
    else {
      st.top() -= -vals[i];
      st.push(-vals[i]);
    }
  }
  if (bad) puts(":-( Try again.");
  else puts(":-) Matrioshka!");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  while (scanf("%[^\r\n] ", buf) != EOF)
    solve(1);
}
}

int main() {
  MATRIOSH::solve();
  return 0;
}

