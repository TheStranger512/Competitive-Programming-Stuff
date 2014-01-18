/* Solved
 * 740. Treats for the Cows - dp
 * File:   TRT.cpp
 * Author: Andy Y.F. Huang
 * Created on August 24, 2012, 5:52 PM
 */

#include <cstdio>
#include <cstring>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace TRT {
int value[2010], dp[2010][2010] = {{0}};

inline int max(int a, int b) {
  return a > b ? a : b;
}

int rec(int left, int right, int age) {
  if (dp[left][right])
    return dp[left][right];
  if (left == right)
    return dp[left][right] = age * value[left];
  dp[left][right] = max(value[left] * age + rec(left + 1, right, age + 1),
                        value[right] * age + rec(left, right - 1, age + 1));
  return dp[left][right];
}

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 1; i <= len; i++)
    scanf("%d", &value[i]);
  printf("%d\n", rec(1, len, 1));
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve(1);
}
}

int main() {
  TRT::solve();
  return 0;
}

