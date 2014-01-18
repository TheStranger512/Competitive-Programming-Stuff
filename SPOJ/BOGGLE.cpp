/*
 * Solved
 * 12462. Boggle Scoring
 * File:   BOGGLE.cpp
 * Author: Andy Y.F. Huang
 * Created on January 24, 2013, 9:59 PM
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
namespace BOGGLE {
string words[111][55];
int len[111] = {0};
char buf[5555];
map<string, int> cnt;

int getscore(int len) {
  if (len <= 4) return 1;
  if (len == 5) return 2;
  if (len == 6) return 3;
  if (len == 7) return 5;
  return 11;
}

void solve(int test_num) {
  int players;
  scanf("%d ", &players);
  for (int p = 0; p < players; p++) {
    cin.getline(buf, 5000);
    char* ptr = strtok(buf, " \r\t\n");
    for (; ptr != NULL; ptr = strtok(NULL, " \r\t\n")) {
      words[p][len[p]++] = ptr;
      cnt[string(ptr)]++;
    }
  }
  int ans = 0;
  for (int p = 0; p < players; p++) {
    int score = 0;
    for (int i = 0; i < len[p]; i++)
      if (cnt[words[p][i]] == 1)
        score += getscore(words[p][i].size());
    ans = max(ans, score);
  }
  printf("%d\n", ans);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
}
}

int main() {
  BOGGLE::solve();
  return 0;
}

