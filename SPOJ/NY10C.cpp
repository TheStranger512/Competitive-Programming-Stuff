/* Solved
 * 8625. Just The Simple Fax
 * File:   NY10C.cpp
 * Author: Andy Y.F. Huang
 * Created on December 31, 2012, 4:07 PM
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
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <cstddef>
#include <utility>
#include <valarray>
#include <cstdlib>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace NY10C {
char str[11111];
char ans[11111];

bool byteeq(int a, int b) {
  return str[a] == str[b] && str[a + 1] == str[b + 1];
}

char tohex(int b) {
  return b < 10 ? b + '0' : b - 10 + 'A';
}

void solve(int test_num) {
  int len;
  scanf("%d %d", &test_num, &len);
  len <<= 1;
  for (int i = 0; i < len; i += 80)
    scanf("%s", str + i);
  str[len] = str[len + 1] = str[len + 2] = str[len + 3] = 'x';
  int anslen = 0;
  for (int i = 0; i < len; ) {
    int nonrun = 0, j = i, pos = anslen + 2;
    while (nonrun < 128 && j < len && !(byteeq(j, j + 2) && byteeq(j, j + 4))) {
      ans[pos++] = str[j];
      ans[pos++] = str[j + 1];
      j += 2;
      nonrun++;
    }
    if (nonrun > 0) {
      nonrun--;
      ans[anslen] = tohex(nonrun >> 4);
      ans[anslen + 1] = tohex(nonrun & 15);
      anslen = pos;
    }
    if (j < len && byteeq(j, j + 2) && byteeq(j, j + 4)) {
      int curbyte = j, run = 0;
      while (run < 130 && j < len && byteeq(curbyte, j)) {
        j += 2;
        run++;
      }
      assert(run >= 3);
      run -= 3;
      run |= 1 << 7;
      ans[anslen++] = tohex(run >> 4);
      ans[anslen++] = tohex(run & 15);
      ans[anslen++] = str[curbyte];
      ans[anslen++] = str[curbyte + 1];
    }
    i = j;
  }
  printf("%d %d\n", test_num, anslen >> 1);
  for (int i = 0; i < anslen; i += 80, putchar('\n'))
    for (int j = 0; j < 80 && i + j < anslen; j++)
      putchar(ans[i + j]);
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
  NY10C::solve();
  return 0;
}

