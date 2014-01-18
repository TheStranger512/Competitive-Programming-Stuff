/* Solved
 * 33. Trip
 * File:   TRIP.cpp
 * Author: Andy Y.F. Huang
 * Created on April 22, 2013, 6:35 PM
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

namespace TRIP {
#define NIL -1
int ch[5555][26];
int root, next, anslen;
char A[88], B[88], str[88];
int dp[99][99], lcs;
char ans[1111][88];
int order[1111];
bool moi[4444][81][81];

bool cmp(int a, int b) {
  return strcmp(ans[a], ans[b]) < 0;
}

int getnext() {
  memset(ch[next], -1, sizeof (ch[next]));
  return next++;
}

int go(int at, int c) {
  if (ch[at][c] == NIL)
    ch[at][c] = getnext();
  return ch[at][c];
}

void rec(int i, int j, int cur) {
  if (i == 0 || j == 0) return;
  if (moi[cur][i][j]) return;
  moi[cur][i][j] = true;
  if (A[i] == B[j])
    rec(i - 1, j - 1, go(cur, A[i] - 'a'));
  else {
    if (dp[i - 1][j] == dp[i][j])
      rec(i - 1, j, cur);
    if (dp[i][j - 1] == dp[i][j])
      rec(i, j - 1, cur);
  }
}

void dfs(int at, int depth) {
  if (depth == lcs) {
    memcpy(ans[anslen], str, lcs + 1);
    anslen++;
  }
  else
    for (int c = 0; c < 26; c++)
      if (ch[at][c] != NIL) {
        str[depth] = c + 'a';
        dfs(ch[at][c], depth + 1);
      }
}

void solve(int test_num) {
  scanf("%s %s", A + 1, B + 1);
  int lenA = strlen(A + 1);
  int lenB = strlen(B + 1);
  memset(dp, 0, sizeof (dp));
  memset(moi, false, sizeof (moi));
  next = anslen = 0;
  root = getnext();
  for (int i = 1; i <= lenA; i++)
    for (int j = 1; j <= lenB; j++)
      if (A[i] == B[j])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
  //plnarr(dp, lenA + 1, lenB + 1);
  lcs = dp[lenA][lenB];
  str[lcs] = 0;
  rec(lenA, lenB, root);
  if (test_num > 1) putchar('\n');
  dfs(root, 0);
  //pln(ans);
  for (int i = 0; i < anslen; i++) {
    reverse(ans[i], ans[i] + lcs);
    order[i] = i;
  }
  sort(order, order + anslen, cmp);
  for (int i = 0; i < anslen; i++)
    printf("%s\n", ans[order[i]]);
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
  TRIP::solve();
  return 0;
}

