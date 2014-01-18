/* Solved
 * 12319. hai jolly jolly jolly
 * File:   NITT2.cpp
 * Author: Andy Y.F. Huang
 * Created on June 1, 2013, 11:12 PM
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

namespace NITT2 {
//252 = 4 * 7 * 9
//525 = 3 * 7 * 25
char str[55555];
int len;

bool div4() {
  if (len == 1)
    return (str[0] - '0') % 4 == 0;
  return (10 * (str[len - 2] - '0') + str[len - 1]) % 4 == 0;
}

bool div7() {
  //do this test last!!
  static int D[] = {1, 3, 2, 6, 4, 5};
  reverse(str, str + len);
  int sum = 0;
  for (int i = 0; i < len; i++)
    sum += (str[i] - '0') * D[i % 6];
  return sum % 7 == 0;
}

bool div25() {
  if (len == 1) return false;
  return (10 * (str[len - 2] - '0') + str[len - 1] - '0') % 25 == 0;
}

bool div9() {
  return (accumulate(str, str + len, 0) - '0' * len) % 9 == 0;
}

bool div3() {
  return (accumulate(str, str + len, 0) - '0' * len) % 3 == 0;
}

void solve(int test_num) {
  scanf("%s", str);
  len = strlen(str);
  bool four = div4(), twfive = div25(), nine = div9();
  bool three = div3();
  bool seven = div7();
  printf("%s %s\n", (four && seven && nine) ? "Yes" : "No", (three && seven && twfive) ? "Yes" : "No");
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  NITT2::solve();
  return 0;
}

