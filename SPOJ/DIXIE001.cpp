/* Solved
 * 14334. Evil Overlord Cypher
 * File:   DIXIE001.cpp
 * Author: Andy Y.F. Huang
 * Created on March 31, 2013, 11:47 AM
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

namespace DIXIE001 {

struct State {
  int val, cnt;

  bool operator<(const State & s) const {
    return cnt < s.cnt || (cnt == s.cnt && val < s.val);
  }
} ;
State cnt[255];

void solve(int test_num) {
  string str = "";
  while (true) {
    int c = getchar();
    if (c == EOF) break;
    if (c == '\r') continue;
    cnt[c].cnt++;
    str += (char) c;
  }
  vector<State> freq;
  string back;
  for (int i = 0; i < 128; i++) {
    cnt[i].val = i;
    if (cnt[i].cnt > 0)
      freq.push_back(cnt[i]);
  }
  sort(freq.begin(), freq.end());
  for (int i = 0; i < (int) freq.size(); i++)
    back += (char) freq[i].val;
  reverse(freq.begin(), freq.end());
  //pln(back);
  for (int i = 0; i < (int) str.size(); i++) {
    int pos = back.find(str[i]);
    putchar((char) freq[pos].val);
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  char str[11];
  gets(str);
  solve(1);
}
}

int main() {
  DIXIE001::solve();
  return 0;
}

