/* Solved
 * 13043. The Mirror of Galadriel
 * File:   AMR12D.cpp
 * Author: Andy Y.F. Huang
 * Created on December 22, 2012, 2:26 PM
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
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace AMR12D {

void solve(int test_num) {
  string str, rev;
  cin >> str;
  for (int i = 0; i < (int) str.size(); i++)
    rev += str[str.size() - i - 1];
  for (int i = 0; i < (int) str.size(); i++) {
    for (int j = 1; j <= (int) str.size() - i; j++) {
      if (rev.find(str.substr(i, j)) == string::npos) {
        puts("NO");
        return;
      }
    }
  }
  puts("YES");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  AMR12D::solve();
  return 0;
}

