/* 
 * 3442. The last digit - number theory
 * File:   LASTDIG.cpp
 * Author: Andy Huang
 * Created on March 13, 2012, 1:35 PM
 */
#include <stdio.h>
#include <string.h>

using namespace std;

int end[11];

void solve() {
  memset(end, 0xFF, sizeof (end));
  long long base, exp;
  scanf("%lld %lld", &base, &exp);
  if (exp == 0) {
    puts("1");
    return;
  }
  if (base == 0) {
    puts("0");
    return;
  }
  int len = 0;
  long long cur = base;
  while (end[cur % 10] == -1) {
    end[cur % 10] = len;
    cur *= base;
    len++;
  }
  exp--;
  exp %= len;
  for (int i = 0; i < 10; i++) {
    if (end[i] == exp) {
      printf("%d\n", i);
      return;
    }
  }
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  while (tests--)
    solve();
  return 0;
}