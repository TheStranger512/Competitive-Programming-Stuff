/* Solved
 * 13090. New Strategy
 * File:   PCPC12D.cpp
 * Author: Andy Y.F. Huang
 * Created on December 28, 2012, 4:11 PM
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
namespace PCPC12D {
int len;
int order[1111];
char str[1111][111];
int cnt[1111][27];

bool cmp(int a, int b) {
  for (int i = 0; i < 26; i++)
    if (cnt[a][i] != cnt[b][i])
      return cnt[a][i] > cnt[b][i];
  return false;
}

void solve(int test_num) {
  scanf("%d\r\n", &len);
  for (int i = 0; i < len; i++) {
    order[i] = i;
    scanf("%[^\r\n]\r\n", str[i]);
    memset(cnt[i], 0, sizeof (cnt[i]));
    int tlen = strlen(str[i]);
    for (int j = 0; j < tlen; j++)
      if (isalpha(str[i][j]))
        cnt[i][tolower(str[i][j]) - 'a']++;
  }
  sort(order, order + len, cmp);
  printf("case: %d\n", test_num);
  for (int i = 0; i < len; i++)
    puts(str[order[i]]);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d\r\n", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  PCPC12D::solve();
  return 0;
}

