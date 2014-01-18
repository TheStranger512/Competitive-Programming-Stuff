/* Solved
 * 7264. Digital LED Number
 * File:   DIGNUM.cpp
 * Author: Andy Y.F. Huang
 * Created on December 26, 2012, 1:42 PM
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
namespace DIGNUM {
char a[11111], b[11111], c[11111];
char nums[3][31] = {" _     _  _     _  _  _  _  _ ",
                    "| |  | _| _||_||_ |_   ||_||_|",
                    "|_|  ||_  _|  | _||_|  ||_|  |"};

bool match(const char* str, const char* pat) {
  return str[0] == pat[0] && str[1] == pat[1] && str[2] == pat[2];
}

void solve(int test_num) {
  int len = strlen(a);
  if (len % 3 != 0) a[len++] = ' ';
  len = strlen(b);
  if (len % 3 != 0) b[len++] = ' ';
  len = strlen(c);
  if (len % 3 != 0) c[len++] = ' ';
  for (int i = 0; i < len; i += 3) {
    for (int j = 0; j < 10; j++)
      if (match(nums[0] + j * 3, a + i)
              && match(nums[1] + j * 3, b + i) && match(nums[2] + j * 3, c + i))
        putchar(j + '0');
  }
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (gets(a) != NULL && gets(b) != NULL && gets(c) != NULL)
    solve(1);
}
}

int main() {
  DIGNUM::solve();
  return 0;
}

