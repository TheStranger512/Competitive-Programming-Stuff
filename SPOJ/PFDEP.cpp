/* Solved
 * 1846. Project File Dependencies - topological sort
 * File:   PFDEP.cpp
 * Author: Andy Huang
 * Created on June 14, 2012, 9:30 PM
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

using namespace std;

#define max_tasks 110

bool done[max_tasks];
vector<int> graph[max_tasks];

void solve() {
  memset(done, false, sizeof (done));
  int tasks, rules;
  scanf("%d %d", &tasks, &rules);
  for (int i = 0; i < rules; i++) {
    int task, depends;
    scanf("%d %d", &task, &depends);
    while (depends--) {
      int to;
      scanf("%d", &to);
      graph[task].push_back(to);
    }
  }
  int cnt = 0;
  while (cnt < tasks) {
    for (int i = 1; i <= tasks; i++) {
      if (done[i])
        continue;
      bool cando = true;
      for (unsigned int j = 0; j < graph[i].size() && cando; j++)
        if (!done[graph[i][j]])
          cando = false;
      if (cando) {
        cnt++;
        done[i] = true;
        printf("%d ", i);
        i = 0;
      }
    } 
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

