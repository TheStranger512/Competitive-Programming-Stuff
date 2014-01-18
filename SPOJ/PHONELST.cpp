/* Solved
 * 4033. Phone List - string searching
 * File:   PHONELST.cpp
 * Author: Andy Huang
 * Created on May 14, 2012, 5:04 PM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
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

template <typename Type> inline void pf(Type x) {
  #ifdef DEBUG
  std::cout << x;
  #endif
}

template <typename Type> inline void pln(Type x) {
  #ifdef DEBUG
  std::cout << x << std::endl;
  #endif
}

using namespace std;

string nums[10050];
char str[20];

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    nums[i] = string(str, strlen(str));
  }
  sort(nums, nums + n);
  bool poss = true;
  for (int i = 1; i < n; i++){
    int len = min(nums[i].length(), nums[i - 1].length());
    int k = 0;
    for (k = 0 ; k < len; k++)
      if (nums[i][k] != nums[i - 1][k])
        break;
    if (k == len)
      poss = false;
  }
  if (poss)
    puts("YES");
  else
    puts("NO");
}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  while (tests--)
    solve();
  return 0;
}

