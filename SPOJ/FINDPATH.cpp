/* Solved
 * 7909. CALCULATE PATH FOR JERRY - bfs
 * File:   FINDPATH.cpp
 * Author: Andy Y.F. Huang
 * Created on September 8, 2012, 3:02 PM
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
#include <bits/stl_queue.h>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace FINDPATH {
int nums[25], len;
long long path[40], goal;

void solve(int test_num) {
  for (int i = 0; i < len; i++)
    scanf("%d", &nums[i]);
  sort(nums, nums + len);
  queue<long long> q;
  map<long long, int> dist;
  map<long long, int>::iterator it;
  map<long long, long long> prev;
  map<long long, long long>::iterator it2;
  dist[1LL] = 0;
  q.push(1LL);
  while (!q.empty()) {
    long long cur = q.front();
    q.pop();
    if (cur == goal)
      break;
    int cdist = dist[cur];
    for (int i = 0; i < len; i++) {
      long long ncur = cur * nums[i];
      if (ncur > goal)
        continue;
      it = dist.find(ncur);
      if (it == dist.end() || cdist + 1 < it->second) {
        if (it == dist.end())
          dist[ncur] = cdist + 1;
        else
          it->second = cdist + 1;
        prev[ncur] = cur;
        q.push(ncur);
      }
    }
  }
  it = dist.find(goal);
  if (it == dist.end()) {
    puts("-1");
    return;
  }
  int pathlen = it->second;
  it2 = prev.find(goal);
  path[pathlen--] = goal;
  while (it2 != prev.end()) {
    path[pathlen--] = it2->second;
    it2 = prev.find(it2->second);
  }
  printf("%d\n", it->second);
  printf("1");
  for (int i = 1; i <= it->second; i++)
    printf(" %lld", path[i]);
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  while (scanf("%lld %d", &goal, &len) != EOF)
    solve(1);
}
}

int main() {
  FINDPATH::solve();
  return 0;
}

