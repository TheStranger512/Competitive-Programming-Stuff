/* Solved
 * 10576. Exclusive Security - dp, prefix xorsums
 * Read question carefully
 * File:   EXCLSEC.cpp
 * Author: Andy Y.F. Huang
 * Created on September 9, 2012, 3:15 PM
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
#include <ctime>
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace EXCLSEC {
int len, groups, queries;
int xorsum[100010], val[100010];
int id[100010], start[100010], end[100010];

bool slow(int num) {
  for (int i = 0; i < groups; i++) {
    int sum = num;
    for (int j = start[i]; j <= end[i]; j++)
      sum ^= id[j];
    if (sum == 0)
      return false;
  }
  return true;
}

void solve(int test_num) {
  xorsum[0] = 0;
  for (int i = 1; i <= len; i++) {
    scanf("%d", &id[i]);
    xorsum[i] = xorsum[i - 1] ^ id[i];
  }
  for (int i = 0; i < groups; i++) {
    scanf("%d %d", &start[i], &end[i]);
    val[i] = xorsum[start[i] - 1] ^ xorsum[end[i]];
  }
  sort(val, val + groups);
  sort(id + 1, id + len + 1);
  //plnarr(val, val + groups);
  for (int i = 0; i < queries; i++) {
    int num;
    scanf("%d", &num);
    //    #ifdef AZN
    //    bool realgood = slow(num);
    //    #endif
    if (binary_search(val, val + groups, num)
            || binary_search(id + 1, id + len + 1, num))
      puts("N");
    else
      puts("Y");
  }
  puts("-");
}

void makecase() {
  freopen("input.txt", "w", stdout);
  int len = 100, groups = 100, queries = 100;
  printf("%d %d %d\n", len, groups, queries);
  for (int i = 0; i < len; i++)
    printf("%d ", rand() % 100);
  putchar('\n');
  for (int i = 0; i < groups; i++) {
    int a = rand() % len + 1;
    int b = a - 1;
    while (b < a)
      b = rand() % len + 1;
    printf("%d %d\n", a, b);
  }
  for (int i = 0; i < queries; i++)
    printf("%d\n", rand() % 100);
  puts("0 0 0");
}

void solve() {
  #ifdef AZN
  //makecase();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (true) {
    scanf("%d %d %d", &len, &groups, &queries);
    if (len == 0 && groups == 0 && queries == 0)
      break;
    solve(1);
  }
}
}

int main() {
  EXCLSEC::solve();
  return 0;
}

