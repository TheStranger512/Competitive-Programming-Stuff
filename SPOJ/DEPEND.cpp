/* Solved
 * 2143. Dependency Problems
 * File:   DEPEND.cpp
 * Author: Andy Y.F. Huang
 * Created on October 28, 2012, 2:11 AM
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
#include <set>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include <cassert>
#include <ctime>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace DEPEND {

struct Comp {

  bool operator()(const char* a, const char* b) const {
    return strcmp(a, b) < 0;
  }
} ;

char names[11111][111];
char temp[111];
int deg[11111] = {0}, to[55555], next[55555], last[11111];
queue<int> q;
bool have[11111] = {false}, added[11111] = {false};
map<const char*, int, Comp> hash;

void solve(int test_num) {
  memset(last, 0xFF, sizeof (last));
  for (int edgecnt = 0, len = 0, curhash = 0; scanf("%s", names[len]) != EOF; ) {
    if (!hash.count(names[len]))
      hash[names[len]] = curhash++;
    int cur = hash[names[len++]];
    have[cur] = true;
    memset(added, false, sizeof (added));
    while (true) {
      scanf("%s", temp);
      if (temp[0] == '0')
        break;
      if (!hash.count(temp)) {
        memcpy(names[len], temp, sizeof (temp));
        hash[names[len++]] = curhash++;
      }
      int adj = hash[temp];
      if (!added[adj]) {
        deg[cur]++;
        to[edgecnt] = cur;
        next[edgecnt] = last[adj];
        last[adj] = edgecnt++;
      }
      added[adj] = true;
    }
    if (deg[cur] == 0)
      q.push(cur);
  }
  //plnarr(hash.begin(), hash.end());
  //plnarr(deg, deg + 10);
  int ans = 0;
  while (!q.empty()) {
    ans++;
    int cur = q.front();
    q.pop();
    for (int id = last[cur]; id != -1; id = next[id])
      if (--deg[to[id]] == 0 && have[to[id]])
        q.push(to[id]);
  }
  printf("%d\n", ans);
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
  DEPEND::solve();
  return 0;
}

