/* Solved
 * 94. Numeral System of the Maya
 * File:   MAYA.cpp
 * Author: Andy Y.F. Huang
 * Created on August 30, 2012, 10:57 PM
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
namespace MAYA {
const long long vals[7] = {1LL, 20LL, 360LL, 7200LL, 144000LL, 2880000LL, 57600000LL};
char str[500];

void solve(int test_num, int digits) {
  long long ans = 0;
  for (int i = digits - 1; i >= 0; i--) {
    gets(str);
    int sum = 0, len = strlen(str);
    for (int j = 0; j < len; ){
      char c = str[j];
      if (c == '-')
        sum += 5, j++;
      else if (c == 'S' || c <= ' ')
        j++;
      else {
        int cnt = 0;
        while (j < len && str[j] == c)
          j++, cnt++;
        sum += cnt;
      }
    }
    ans += vals[i] * sum;
  }
  cout << ans << endl;
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    int digits;
    scanf("%d\r\n", &digits);
    if (digits == 0)
      break;
    solve(1, digits);
  }
}
}

int main() {
  MAYA::solve();
  return 0;
}

