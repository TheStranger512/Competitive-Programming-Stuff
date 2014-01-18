/* Solved
 * 423. Assignments
 * File:   ASSIGN.cpp
 * Author: Andy Y.F. Huang
 * Created on July 29, 2012, 1:12 PM
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ASSIGN {
long long dp[1 << 20];
int likes[25][25], len[25], two[21];
int valid[1 << 20], ppl, test_num;

long long rec(int student, int state) {
  long long ans = 0LL;
  if (valid[state] == test_num)
    return dp[state];
  if (student == ppl)
    ans = 1LL;
  else
    for (int j = 0; j < len[student]; j++)
      if (!(likes[student][j] & state))
        ans += rec(student + 1, likes[student][j] | state);
  valid[state] = test_num;
  return dp[state] = ans;
}

void solve(int test_number) {
  scanf("%d", &ppl);
  memset(len, 0, sizeof (len));
  for (int i = 0; i < ppl; i++) {
    for (int j = 0; j < ppl; j++) {
      char temp = 0;
      while (temp < 48)
        temp = getchar_unlocked();
      if (temp == '1')
        likes[i][len[i]++] = two[j];
    }
  }
  printf("%lld\n", rec(0, 0));
}

void makecase() {
  srand(time(NULL));
  freopen("input.txt", "w", stdout);
  puts("1");
  printf("%d\n", 20);
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++)
      printf("1 ");
    putchar('\n');
  }
}

void solve() {
  #ifdef AZN
  //makecase();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  for (int i = 0; i < 20; i++)
    two[i] = 1 << i;
  int tests;
  scanf("%d", &tests);
  for (test_num = 1; test_num <= tests; test_num++)
    solve(test_num);
}
}

int main() {
  ASSIGN::solve();
  return 0;
}

