/* Solved
 * 12001. Bit by Bit
 * File:   DCEPC807.cpp
 * Author: Andy Y.F. Huang
 * Created on August 29, 2012, 10:37 PM
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
namespace DCEPC807 {
bool win[1 << 21] = {false};
const int twos[] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024,
                    2048, 4096, 8192, 16384, 32768, 65536, 131072,
                    262144, 524288, 1048576};

void init() {
  for (unsigned int i = 0; i <= 1000000; i++) {
    if (binary_search(twos, twos + 21, i))
      win[i] = false;
    if (!win[i]) {
      //pln(i);
      for (unsigned j = 0; j < 20; j++) {
        unsigned x = 1 << j | i;
        bool a = (x ^ i) != 0;
        unsigned y = x | (1 << (j + 1));
        bool b = (y ^ i) != 0;
        if (a)
          win[x] = true;
        if (a && b)
          win[y] = true;
      }
    }
  }
}

void solve(int test_num) {
  int n;
  scanf("%d", &n);
  puts(win[n] ? "Alice" : "Bob");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  init();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  DCEPC807::solve();
  return 0;
}

