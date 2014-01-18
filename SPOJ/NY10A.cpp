/* Solved
 * 8612. Penney Game
 * File:   NY10A.cpp
 * Author: Andy Y.F. Huang
 * Created on August 10, 2012, 11:20 PM
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
namespace NY10A {
const char seq[8][4] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};
char str[55];

void solve(int test_num) {
  scanf("%d%s", &test_num, str);
  int cnt[8] = {0};
  for (int i = 0; i < 38; i++) {
    char temp[4] = {str[i], str[i + 1], str[i + 2], '\0'};
    for (int j = 0; j < 8; j++) {
      if (strcmp(temp, seq[j]) == 0) {
        cnt[j]++;
        break;
      }
    }
  }
  printf("%d", test_num);
  for (int i = 0; i < 8; i++)
    printf(" %d", cnt[i]);
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  NY10A::solve();
  return 0;
}

