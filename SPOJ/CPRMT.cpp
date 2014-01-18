/* Solved
 * 1728. Common Permutation
 * File:   CPRMT.cpp
 * Author: Andy Y.F. Huang
 * Created on August 6, 2012, 8:41 PM
 */

#include <cstdio>
#include <algorithm>
#include <cstring>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace CPRMT {
const int k_max_len = 1010;

void solve(int test_num, char* a, char* b) {
  int acnt[26] = {0}, bcnt[26] = {0};
  int alen = strlen(a), blen = strlen(b);
  for (int i = 0; i < alen; i++)
    acnt[a[i] - 'a']++;
  for (int j = 0; j < blen; j++)
    bcnt[b[j] - 'a']++;
  for (int c = 0; c < 26; c++)
    for (int i = 0; i < min(acnt[c], bcnt[c]); i++)
      putchar(c + 'a');
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  char a[k_max_len], b[k_max_len];
  while (scanf("%s\r\n%s", a, b) != EOF)
    solve(1, a, b);
}
}

int main() {
  CPRMT::solve();
  return 0;
}

