/* Solved
 * 11581. The Famous Clock - convert from roman
 * File:   CLOCK2.cpp
 * Author: Andy Huang
 * Created on June 3, 2012, 10:46 AM
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
#include <cassert>

#ifdef AZN
#include "Azn.cpp"
#define pln(x) println(x)
#define pf(x) print(x)
#define plnarr(i, j) println(i, j)
#endif

namespace {
const int len = 13;
const char* nums[len] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
const int lengths[len] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1};
const int values[len] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

struct Roman {

  static int fromRoman(const std::string & roman) {
    int ans = 0;
    unsigned int start = 0;
    for (int j = 0; j < len; j++) {
      while (roman.find(nums[j], start) == start) {
        start += lengths[j];
        ans += values[j];
      }
    }
    return ans;
  }

  static std::string toRoman(int num) {
    std::stringstream ans;
    for (int i = 0; i < len; i++)
      while (num >= values[i]) {
        ans << nums[i];
        num -= values[i];
      }
    return ans.str();
  }
} ;

}

using namespace std;

char str[50];

void solve() {
  printf("%d\n", Roman::fromRoman(string(str)));
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int cases = 1;
  while (~scanf("%s", str)) {
    printf("Case %d: ", cases++);
    solve();
  }
  return 0;
}

