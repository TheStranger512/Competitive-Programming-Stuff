/* Solved
 * 10186. Divisor Digits
 * File:   PUCMM025.cpp
 * Author: Andy Y.F. Huang
 * Created on September 23, 2012, 12:02 AM
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
namespace PUCMM025 {
const int k_seven[6] = {1, 3, 2, 6, 4, 5};
char str[300] = {0};

void solve(int test_num) {
  int len = strlen(str + 1);
  int cnt[10] = {0}, ans = 0, sum = 0;
  for (int i = 1; i <= len; i++) {
    str[i] -= '0';
    cnt[(int) str[i]]++;
    sum += str[i];
  }
  if (len < 3) {
    int num = atoi(str + 1);
    for (int d = 1; d <= 9; d++)
      if (num % d == 0)
        ans += cnt[d];
    printf("%d\n", ans);
    return;
  }
  ans += cnt[1];
  if (str[len] % 2 == 0) //by 2
    ans += cnt[2];
  if (sum % 3 == 0)
    ans += cnt[3];
  if ((str[len - 1] * 10 + str[len]) % 4 == 0)
    ans += cnt[4];
  if (str[len] == 0 || str[len] == 5)
    ans += cnt[5];
  if (str[len] % 2 == 0 && sum % 3 == 0)
    ans += cnt[6];
  int sum7 = 0;
  for (int i = len, j = 0; i >= 1; i--, j = (j + 1) % 6)
    sum7 += str[i] * k_seven[j];
  if (sum7 % 7 == 0)
    ans += cnt[7];
  if ((str[len - 2] * 100 + str[len - 1] * 10 + str[len]) % 8 == 0)
    ans += cnt[8];
  if (sum % 9 == 0)
    ans += cnt[9];
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (scanf("%s", str + 1) != EOF)
    solve(1);
}
}

int main() {
  PUCMM025::solve();
  return 0;
}

