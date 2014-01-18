/* Solved
 * 15215. David and his Obsession
 * File:   PUCMM009.cpp
 * Author: Andy Y.F. Huang
 * Created on July 22, 2013, 12:09 AM
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

namespace PUCMM009 {
char str[11];

void solve(int test_num) {
  int num = 0;
  for (int i = 3 * 495; i < 100000; i += 495) {
    sprintf(str, "%d", i);
    if (strlen(str) == 4)
      str[4] = '0';
    sort(str, str + 5);
    bool ok = true;
    for (int j = 1; j < 5; j++)
      if (str[j] == str[j - 1])
        ok = false;
    if (ok) {
      //pln(i);
      num++;
    }
  }
  int g = __gcd(num, 30240);
  printf("%d/%d\n", num / g, 30240 / g);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  PUCMM009::solve();
  return 0;
}

