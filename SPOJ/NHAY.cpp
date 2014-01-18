/* Solved
 * 32. A Needle in the Haystack
 * File:   NHAY.cpp
 * Author: Andy Y.F. Huang
 * Created on January 4, 2013, 3:36 PM
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
namespace NHAY {
char needle[1 << 24];
char hay[1 << 24];
int table[1 << 24];
int needlelen;

void solve(int test_num) {
  table[0] = -1;
  for (int i = 0, j = -1; i < needlelen; ) {
    while (j >= 0 && needle[i] != needle[j])
      j = table[j];
    table[++i] = ++j;
  }
  for (int i = 0, j = 0; hay[i] > 0; i++) {
    while (j >= 0 && needle[j] != hay[i])
      j = table[j];
    j++;
    if (j == needlelen) {
      printf("%d\n", i - needlelen + 1);
      j = table[j];
    }
  }
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (scanf("%d%s%s", &needlelen, needle, hay) != EOF)
    solve(1);

}
}

int main() {
  NHAY::solve();
  return 0;
}

