/*
 * Solved
 * 9255. Publication
 * File:   PUBLICAT.cpp
 * Author: Andy Y.F. Huang
 * Created on March 28, 2013, 11:19 PM
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

namespace PUBLICAT {

template <class T, size_t MAXSIZE, class Comp = less<T> > struct Indexer {
  T arr[MAXSIZE];
  int len;

  void add(const T & val) {
    arr[len++] = val;
  }

  void process() {
    sort(arr, arr + len, Comp());
    len = unique(arr, arr + len) - arr;
  }

  int get(const T & val) {
    return lower_bound(arr, arr + len, val, Comp()) - arr;
  }
} ;

const string ORI = "ORIZONDO";
vector<string> pubs[51];
Indexer<string, 2555 > vals;
int dist[555];
int last[555], to[5555], next[5555];
deque<int> q;
char buf[3000];

void solve(int test_num) {
  vals.len = 0;
  int len;
  scanf("%d ", &len);
  for (int i = 0; i < len; i++) {
    pubs[i].clear();
    gets(buf);
    char* ptr = strtok(buf, " \r\n");
    while (ptr != NULL) {
      pubs[i].push_back(string(ptr));
      vals.add(pubs[i].back());
      ptr = strtok(NULL, " \r\n");
    }
  }
  vals.process();
  int cnt = vals.len;
  memset(last, -1, sizeof (last));
  for (int i = 0, by, e = 0; i < len; i++) {
    for (int j = 0; j < (int) pubs[i].size(); j++) {
      by = vals.get(pubs[i][j]);
      to[e] = i + cnt;
      next[e] = last[by];
      last[by] = e++;
      to[e] = by;
      next[e] = last[i + cnt];
      last[i + cnt] =  e++;
    }
  }
  memset(dist, 0x3F, sizeof (dist));
  dist[vals.get(ORI)] = 0;
  q.push_back(vals.get(ORI));
  for (int at; !q.empty(); ) {
    at = q.front();
    q.pop_front();
    for (int id = last[at], x; id != -1; id = next[id]) {
      x = to[id];
      if (x < cnt && dist[at] + 1 < dist[x]) {
        q.push_back(x);
        dist[x] = dist[at] + 1;
      }
      if (x >= cnt && dist[at] < dist[x]) {
        q.push_front(x);
        dist[x] = dist[at];
      }
    }
  }
  for (int i = 0; i < cnt; i++) {
    printf(vals.arr[i].c_str());
    putchar(' ');
    if (dist[i] < 1000)
      printf("%d ", dist[i]);
  }
  putchar('\n');
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  PUBLICAT::solve();
  return 0;
}

