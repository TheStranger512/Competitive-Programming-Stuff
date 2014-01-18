/* Solved
 * 9040. Tug of War
 * File:   TUG.cpp
 * Author: Andy Y.F. Huang
 * Created on August 11, 2012, 3:19 PM
 */

#include <cstdio>
#include <cstring>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace TUG {

void solve(int test_num) {
  int dp[5100] = {0}, str[110], len;
  scanf("%d", &len);
  if (len >= 100) {
    for (int i = 0; i < len; i++)
      scanf("%d", &str[0]);
    puts("YES");
    return;
  }
  for (int i = 0; i < len; i++)
    scanf("%d", &str[i]);
  dp[0] = 1;
  for (int j = 0; j < len; j++) {
    for (int i = 5050; i >= 0; i--) {
      if (dp[i] && i + str[j] <= 5050 && ++dp[i + str[j]] >= 2) {
        puts("YES");
        return;
      }
    }
  }
  puts("NO");
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
  TUG::solve();
  return 0;
}

