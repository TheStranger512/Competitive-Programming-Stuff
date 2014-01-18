/* Solved
 * 1787. Run Length Encoding
 * File:   ENCONDIN.cpp
 * Author: Andy Y.F. Huang
 * Created on August 27, 2012, 11:53 PM
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
 * Unsolved
 * @author Andy Y.F. Huang
 */
namespace ENCONDIN {
char str[10100];

void solve(int test_num) {
  bool prevsingle = false;
  int len = strlen(str);
  for (int i = 0; i < len; ) {
    if (str[i] == '\r')
      break;
    char c = str[i];
    int j = i, cnt = 0;
    while (cnt < 9 && j < len && str[j] == c)
      j++, cnt++;
    if (cnt == 1) {
      if (!prevsingle)
        putchar('1');
      putchar(c);
      if (c == '1')
        putchar('1');
      prevsingle = true;
    }
    else {
      if (prevsingle)
        putchar('1');
      putchar(cnt + '0');
      putchar(c);
      prevsingle = false;
    }
    i = j;
  }
  if (prevsingle)
    putchar('1');
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (gets(str) != NULL)
    solve(1);
}
}

int main() {
  ENCONDIN::solve();
  return 0;
}

