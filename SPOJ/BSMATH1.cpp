/* Solved
 * 5530. Math with Bases (Easy)
 * File:   BSMATH1.cpp
 * Author: Andy Y.F. Huang
 * Created on September 3, 2012, 12:56 PM
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
namespace BSMATH1 {
const char digits[] = {
                       '0' , '1' , '2' , '3' , '4' , '5' ,
                       '6' , '7' , '8' , '9' , 'A' , 'B' ,
                       'C' , 'D' , 'E' , 'F' , 'G' , 'H' ,
                       'I' , 'J' , 'K' , 'L' , 'M' , 'N' ,
                       'O' , 'P' , 'Q' , 'R' , 'S' , 'T' ,
                       'U' , 'V' , 'W' , 'X' , 'Y' , 'Z'
};

long long parseInt(const char* str, const int radix) {
  long long result = 0;
  int i = 0;
  int len = strlen(str);
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

std::string toString(long long num, int radix) {
  char buf[70];
  int charpos = 68;
  buf[69] = '\0';
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

char a[1010][60], b[1010][60], op[1010][10];
char reala[60], realb[60], realop[10], realans[60];
int minbase;

void checkbase(char str[]) {
  for (int i = strlen(str) - 1; i >= 0; i--) {
    if (str[i] >= 'A')
      minbase = max(minbase, str[i] - 'A' + 10 + 1);
    else
      minbase = max(minbase, str[i] - '0' + 1);
  }
}

void solve(int test_num) {
  int quests;
  minbase = 2;
  scanf("%s %s %s = %s %d", reala, realop, realb, realans, &quests);
  for (int i = 0; i < quests; i++)
    scanf("%s %s %s =\r\n", a[i], op[i], b[i]);
  checkbase(reala);
  checkbase(realb);
  checkbase(realans);
  for (int i = 0; i < quests; i++) {
    checkbase(a[i]);
    checkbase(b[i]);
  }
  for (int base = minbase; base <= 36; base++) {
    long long aa = parseInt(reala, base);
    long long bb = parseInt(realb, base);
    string res;
    if (realop[0] == '+')
      res = toString(aa + bb, base);
    else
      res = toString(aa - bb, base);
    if (strcmp(res.c_str(), realans) == 0) {
      printf("SECTION %d (BASE %d)\n", test_num, base);
      for (int i = 0; i < quests; i++) {
        aa = parseInt(a[i], base);
        bb = parseInt(b[i], base);
        if (op[i][0] == '+')
          res = toString(aa + bb, base);
        else
          res = toString(aa - bb, base);
        printf("  %s %s %s = %s\n", a[i], op[i], b[i], res.c_str());
      }
      break;
    }
  }
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
  BSMATH1::solve();
  return 0;
}

