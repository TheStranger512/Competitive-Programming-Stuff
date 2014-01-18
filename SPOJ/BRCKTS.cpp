/*
 * Solved
 * 61. Brackets
 * File:   BRCKTS.cpp
 * Author: Andy Y.F. Huang
 * Created on March 3, 2013, 11:35 AM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace BRCKTS {

struct Node {
  int sum, minpre;

  void fill(int val) {
    sum = minpre = val;
  }

  void invert() {
    sum = -sum;
    minpre = -minpre;
  }

  bool good() {
    return sum == 0 && minpre == 0;
  }

  void f(const Node & left, const Node & right) {
    sum = left.sum + right.sum;
    minpre = min(left.minpre, left.sum + right.minpre);
  }
} ;

Node tree[66666];
int len;
char str[33333];

void solve(int test_num) {
  scanf("%s", str);
  int size = 1;
  while (size < len)
    size <<= 1;
  for (int i = len; i < size; i++)
    if ((i - len) & 1) str[i] = ')';
    else str[i] = '(';
  //pln(str);
  for (int i = 0; i < size; i++)
    tree[i + size].fill(str[i] == '(' ? 1 : -1);
  for (int i = size - 1; i > 0; i--)
    tree[i].f(tree[i + i], tree[i + i + 1]);
  int quests;
  scanf("%d", &quests);
  printf("Test %d:\n", test_num);
  for (int q = 0; q < quests; q++) {
    int pos;
    scanf("%d", &pos);
    if (pos == 0) {
      if (tree[1].good())
        puts("YES");
      else puts("NO");
    }
    else {
      pos--;
      tree[pos + size].invert();
      for (int i = (pos + size) >> 1; i > 0; i >>= 1)
        tree[i].f(tree[i + i], tree[i + i + 1]);
    }
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  for (int t = 1; scanf("%d", &len) != EOF; t++)
    solve(t);
}
}

int main() {
  BRCKTS::solve();
  return 0;
}

