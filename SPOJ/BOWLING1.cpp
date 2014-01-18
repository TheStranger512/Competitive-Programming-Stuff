/* Solved
 * 6477. Bowling
 * File:   BOWLING1.cpp
 * Author: Andy Y.F. Huang
 * Created on August 30, 2012, 6:04 PM
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
namespace BOWLING1 {

void solve(int test_num) {
  stringstream ss;
  int score[15] = {0}, vals[50] = {0}, len = 0;
  string str;
  getline(cin, str);
  ss << str;
  while (ss >> vals[len])
    len++;
  for (int i = 1, j = 0; i <= 10; i++, j++) {
    int first = vals[j];
    bool striked = false, spared = false;
    if (first == 10) {
      score[i] = 10 + vals[j + 1] + vals[j + 2];
      striked = true;
    }
    else {
      int second = vals[++j];
      score[i] = first + second;
      if (first + second == 10) {
        score[i] += vals[j + 1];
        spared = true;
      }
    }
  }
  int sum = 0;
  //plnarr(score + 1, score + 11);
  for (int i = 1; i <= 10; i++)
    sum += score[i];
  printf("%d\n", sum);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  int tests;
  cin >> tests;
  cin.ignore(500, '\n');
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  BOWLING1::solve();
  return 0;
}

