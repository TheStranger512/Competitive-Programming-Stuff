/* Solved
 * 9788. Friends of Friends - simple graph theory
 * File:   FACEFRND.cpp
 * Author: Andy Huang
 * Created on May 7, 2012, 12:35 AM
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

using namespace std;

char friends[1000000];

void solve() {
  int n, ans = 0;
  memset(friends, 0, sizeof(friends));
  scanf("%d", &n);
  while (n--){
    int m, ff;
    scanf("%d %d", &m, &ff);
    if (friends[m] == 2)
      ans--;
    friends[m] = 1;
    while (ff--){
      int id;
      scanf("%d", &id);
      if (friends[id] == 0)
        ans++;
      if (friends[id] != 1)
        friends[id] = 2;
    }
  }
  printf("%d\n", ans);
}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}

