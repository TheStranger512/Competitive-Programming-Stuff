/* Solved
 * 11980. Sequence
 * File:   GSSQUNCE.cpp
 * Author: Andy Y.F. Huang
 * Created on August 17, 2012, 12:56 AM
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
namespace GSSQUNCE {
int arr[50050], len;

void solve(int test_num) {
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d", &arr[i]);
  if (len < 2) {
    puts("NO");
    return;
  }
  sort(arr, arr + len);
  for (int i = 0; i < len; ) {
    int cnt = 0, cur = arr[i];
    while (i < len && arr[i] == cur)
      i++, cnt++;
    if (cnt > 2) {
      puts("NO");
      return;
    }
  }
  puts("YES");
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
  GSSQUNCE::solve();
  return 0;
}

