/* Solved
 * 9493. Advanced Fruits - dp - shortest common supersequence
 * File:   ADFRUITS.cpp
 * Author: Andy Y.F. Huang
 * Created on August 31, 2012, 9:09 PM
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
namespace ADFRUITS {
/**
 * dp[i][j] = scs of a[i] && b[j]
 * if i == 0: = j
 * if j == 0: = i
 * if a[i] == b[j]: dp[i - 1][j - 1] + 1
 * if a[i] != b[j]: min(dp[i - 1][j], dp[i][j - 1]) + 1
 */
int dp[110][100];
char a[110], b[110];

void trace(int i, int j) {
  if (i == 0)
    for (int k = 1; k <= j; k++)
      putchar(b[k]);
  else if (j == 0)
    for (int k = 1; k <= i; k++)
      putchar(a[k]);
  else if (a[i] == b[j]) {
    trace(i - 1, j - 1);
    putchar(a[i]);
  }
  else if (dp[i - 1][j] <= dp[i][j - 1]) {
    trace(i - 1, j);
    putchar(a[i]);
  }
  else {
    trace(i, j - 1);
    putchar(b[j]);
  }
}

void solve(int test_num) {
  memset(dp, 0, sizeof (dp));
  int lena = strlen(a + 1), lenb = strlen(b + 1);
  for (int i = 0; i <= lena; i++)
    dp[i][0] = i;
  for (int j = 0; j <= lenb; j++)
    dp[0][j] = j;
  for (int i = 1; i <= lena; i++) {
    for (int j = 1; j <= lenb; j++) {
      if (a[i] == b[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
    }
  }
//  for (int i = 0; i <= lena; i++)
//    plnarr(dp[i], dp[i] + lenb + 1);
//  pln(dp[lena][lenb]);
  trace(lena, lenb);
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (scanf("%s %s", a + 1, b + 1) != EOF)
    solve(1);
}
}

int main() {
  ADFRUITS::solve();
  return 0;
}

