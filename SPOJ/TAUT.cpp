/* Solved
 * 147. Tautology
 * File:   TAUT.cpp
 * Author: Andy Y.F. Huang
 * Created on August 28, 2012, 11:11 PM
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
namespace TAUT {
bool value[35], have[27];
char expr[200];
int vars[27], len;

inline bool evalbin(bool a, char op, bool b) {
  if (op == 'C')
    return a && b;
  else if (op == 'D')
    return a || b;
  else if (op == 'E')
    return a == b;
  else
    return !a || b;
}

inline bool isoperator(char c) {
  return c < 'a';
}

bool eval() {
  bool valstack[200];
  int top = 0;
  for (int i = len - 1; i >= 0; i--) {
    char c = expr[i];
    if (!isoperator(c))
      valstack[top++] = value[c - 'a'];
    else {
      if (c == 'N')
        valstack[top - 1] = !valstack[top - 1];
      else {
        valstack[top - 2] = evalbin(valstack[top - 1], c, valstack[top - 2]);
        top--;
      }
    }
  }
  assert(top == 1);
  return valstack[top - 1];
}

void solve(int test_num) {
  memset(value, false, sizeof (value));
  memset(have, false, sizeof (expr));
  scanf("%s", expr);
  len = strlen(expr);
  int varscnt = 0;
  for (int i = 0; i < len; i++)
    if (expr[i] >= 'a' && !have[expr[i] - 'a'])
      have[expr[i] - 'a'] = true, vars[varscnt++] = expr[i] - 'a';
  for (int mask = (1 << varscnt) - 1; mask >= 0; mask--) {
    for (int i = 0; i < varscnt; i++)
      value[vars[i]] = 1 << i & mask;
    if (!eval()) {
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
  TAUT::solve();
  return 0;
}

