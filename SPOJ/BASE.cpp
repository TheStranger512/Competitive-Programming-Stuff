/* Solved
 * 870. Basically Speaking - converting between bases
 * File:   BASE.cpp
 * Author: Andy Huang
 * Created on June 7, 2012, 12:09 AM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
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

struct Integer {

  static int parseInt(const std::string & str, const int radix) {
    int result = 0;
    int i = 0;
    int len = str.length();
    int digit;
    bool negative = false;
    if (str[0] == '-') {
      negative = true;
      i++;
    }
    while (i < len) {
      char ch = str[i++];
      if (ch >= 'A')
        digit = ch - 'A' + 10;
      else
        digit = ch - '0';
      result *= radix;
      result += digit;
    }
    return negative ? -result : result;
  }

  static std::string toString(int num, int radix) {
    const char digits[] = {
      '0' , '1' , '2' , '3' , '4' , '5' ,
      '6' , '7' , '8' , '9' , 'A' , 'B' ,
      'C' , 'D' , 'E' , 'F' , 'G' , 'H' ,
      'I' , 'J' , 'K' , 'L' , 'M' , 'N' ,
      'O' , 'P' , 'Q' , 'R' , 's' , 't' ,
      'U' , 'V' , 'W' , 'X' , 'Y' , 'Z'
    };
    char buf[33];
    int charpos = 31;
    buf[32] = '\0';
    bool negative = num < 0;
    if (negative)
      num = -num;
    while (num >= radix) {
      buf[charpos--] = digits[num % radix];
      num /= radix;
    }
    buf[charpos] = digits[num];
    if (negative)
      buf[--charpos] = '-';
    return std::string(buf + charpos);
  }

} ;

using namespace std;

void solve() {
  string str;
  int base1, base2;
  while (cin >> str >> base1 >> base2) {
    string ans = Integer::toString(Integer::parseInt(str, base1), base2);
    if (ans.length() > 7)
      puts("  ERROR");
    else
      printf("%7s\n", ans.c_str());
  }

}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}

