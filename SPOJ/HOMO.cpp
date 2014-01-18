/* Solved
 * 7691. Homo or Hetero
 * File:   HOMO.cpp
 * Author: Andy Y.F. Huang
 * Created on August 17, 2012, 11:35 AM
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
namespace HOMO {
map<int, int> cnt;
map<int, int>::iterator iter;
char str[20];

void solve(int test_num) {
  cnt.clear();
  int ops, twos = 0;
  scanf("%d", &ops);
  for (int i = 0; i < ops; i++) {
    int val;
    scanf("%s %d", str, &val);
    iter = cnt.find(val);
    if (str[0] == 'i') {
      if (iter != cnt.end()) {
        iter->second++;
        if (iter->second == 2)
          twos++;
      }
      else
        cnt[val] = 1;
    }
    else {
      if (iter != cnt.end()) {
        iter->second--;
        if (iter->second == 1)
          twos--;
        if (iter->second == 0)
          cnt.erase(iter);
      }
    }
    if (cnt.size() >= 2 && twos > 0)
      puts("both");
    else if (twos > 0)
      puts("homo");
    else if (cnt.size() >= 2)
      puts("hetero");
    else
      puts("neither");
  }
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
  HOMO::solve();
  return 0;
}

