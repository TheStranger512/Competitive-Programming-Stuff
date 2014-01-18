/* Solved
 * 3372. Round Table
 * File:   ROUNDT.cpp
 * Author: Andy Y.F. Huang
 * Created on June 22, 2013, 2:30 PM
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

namespace ROUNDT {
#define LESS 0
#define GREAT 1
int A[2222], B[2222];
int costA[2], costB[2][2222];
int dp[2][2222];
int N;

int getdir(int A, int B) {
  //0 - CCW, 1 - CW
  //Door2 to A to B
  if (B > N)
    return (N < A && A < B) ? LESS : GREAT;
  else
    return (B < A && A <= N) ? GREAT : LESS;
}

void solve(int test_num) {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", B + i);
  for (int i = 1; i <= N; i++)
    scanf("%d", A + i);
  int* cur = dp[0], *prev = dp[1];
  prev[0] = 0;
  memset(costA, 0, sizeof (costA));
  memset(costB, 0, sizeof (costB));
  for (int j = 1; j <= N; j++) {
    for (int jj = 1; jj < j; jj++)
      if (B[jj] < B[j])
        costB[LESS][j]++;
      else
        costB[GREAT][j]++;
    prev[j] = prev[j - 1] + min(costB[LESS][j], costB[GREAT][j]);
  }
  for (int i = 1; i <= N; i++) {
    costA[LESS] = costA[GREAT] = 0;
    for (int ii = 1; ii < i; ii++)
      costA[getdir(A[ii], A[i])]++;
    cur[0] = prev[0] +  min(costA[LESS], costA[GREAT]);
    for (int j = 1; j <= N; j++) {
      if (A[i] > B[j])
        costB[GREAT][j]++;
      else
        costB[LESS][j]++;
      costA[getdir(B[j], A[i])]++;
      cur[j] = min(cur[j - 1] + min(costB[LESS][j], costB[GREAT][j]),
                   prev[j] + min(costA[LESS], costA[GREAT]));
    }
    //plnarr(cur, cur + N);
    swap(cur, prev);
  }
  //pln(costA[0], costA[1]);
  printf("%d\n", prev[N]);
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
  ROUNDT::solve();
  return 0;
}

