/* Solved
 * 4580. ABCDEF
 * File:   ABCDEF.cpp
 * Author: Andy Y.F. Huang
 * Created on August 10, 2012, 1:35 AM
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
namespace ABCDEF {
const int k_max_n = 1000010;
int first[k_max_n], second[k_max_n];
int cnta[k_max_n] = {0}, cntb[k_max_n] = {0};

void solve(int test_num) {
  int lena = 0, lenb = 0, num[110], size;
  scanf("%d", &size);
  for (int i = 0; i < size; i++)
    scanf("%d", &num[i]);
  for (int a = 0; a < size; a++)
    for (int b = 0; b < size; b++)
      for (int c = 0; c < size; c++)
        first[lena++] = num[a] * num[b] + num[c];
  for (int d = 0; d < size; d++) {
    if (num[d] == 0)
      continue;
    for (int e = 0; e < size; e++)
      for (int f = 0; f < size; f++)
        second[lenb++] = num[d] * (num[f] + num[e]);
  }
  sort(first, first + lena);
  sort(second, second + lenb);
//  plnarr(first, first + lena);
//  plnarr(second, second + lenb);
  int unia = -1, unib = -1;
  int prev = 1234567890;
  for (int i = 0; i < lena; i++) {
    if (first[i] != prev) {
      prev = first[i];
      first[++unia] = prev;
    }
    cnta[unia]++;
  }
  unia++;
  prev = 1234567890;
  for (int i = 0; i < lenb; i++) {
    if (second[i] != prev) {
      prev = second[i];
      second[++unib] = prev;
    }
    cntb[unib]++;
  }
  unib++;
//  plnarr(first, first + unia);
//  plnarr(cnta, cnta + unia);
//  plnarr(second, second + unib);
//  plnarr(cntb, cntb + unib);
  int i = 0, j = 0;
  long long ans = 0;
  while (i < unia && j < unib) {
    if (first[i] == second[j])
      ans += cnta[i++] * cntb[j++];
    else if (first[i] < second[j])
      i++;
    else
      j++;
  }
  printf("%lld\n", ans);
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
  ABCDEF::solve();
  return 0;
}

