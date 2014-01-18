/* Solved
 * 11986. ROMAN NUMERALS
 * File:   ROMAN008.cpp
 * Author: Andy Y.F. Huang
 * Created on August 17, 2012, 2:33 PM
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace ROMAN008 {
const int len = 13;
const char* nums[len] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
const int lengths[len] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1};
const int values[len] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

int fromRoman(const std::string & roman) {
  int ans = 0;
  unsigned int start = 0;
  for (int j = 0; j < len; j++) {
    if (start >= roman.length())
      break;
    while (roman.find(nums[j], start) == start) {
      start += lengths[j];
      ans += values[j];
    }
  }
  return ans;
}

string toRoman(int num) {
  std::stringstream ans;
  for (int i = 0; i < len; i++)
    while (num >= values[i]) {
      ans << nums[i];
      num -= values[i];
    }
  return ans.str();
}

string a, b, op;

void solve(int test_num) {
  char c = op[0];
  int x = fromRoman(a), y = fromRoman(b);
  if (c == '+')
    x += y;
  else if (c == '-')
    x -= y;
  else if (c == '*')
    x *= y;
  else if (c == '/')
    x /= y;
  else
    x %= y;
  cout << toRoman(x) << endl;
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (cin >> a >> b >> op)
    solve(1);
}
}

int main() {
  ROMAN008::solve();
  return 0;
}

