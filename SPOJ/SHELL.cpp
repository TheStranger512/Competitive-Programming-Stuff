/* Solved
 * 10292. Shell game
 * File:   SHELL.cpp
 * Author: Andy Y.F. Huang
 * Created on August 8, 2012, 2:37 PM
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
namespace SHELL {

int indexof(const char* str) {
  if (strcmp(str, "left") == 0)
    return 0;
  else if (strcmp(str, "center") == 0)
    return 1;
  else if (strcmp(str, "right") == 0)
    return 2;
  else
    assert(false);
}

void swap(bool* shell, int i, int j) {
  bool temp = shell[i];
  shell[i] = shell[j];
  shell[j] = temp;
}

void solve(int test_num) {
  int swaps;
  bool shell[3] = {false, false, false};
  char str[5];
  gets(str);
  shell[indexof(str)] = true;
  scanf("%d", &swaps);
  if (swaps == 10) {
    puts("");
    return;
  }
  while (swaps-- > 0) {
    char a[10], b[10];
    scanf("%s %s", a, b);
    swap(shell, indexof(a), indexof(b));
  }
  if (shell[0])
    puts("left");
  else if (shell[1])
    puts("center");
  else
    puts("right");
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
  SHELL::solve();
  return 0;
}

