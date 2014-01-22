/* Solved
 * Polo the Penguin and the Lucky String
 * File:   PPLUCKY.cpp
 * Author: Andy Y.F. Huang
 * Created on Oct 20, 2013, 12:46:44 PM
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

using namespace std;

namespace PPLUCKY {
string str;
int bit[111000];
int N;

void update(int pos, int val) {
  for (int i = pos + 1; i <= N + 1; i += i & -i)
    bit[i] += val;
}

int get(int pos) {
  int res = 0;
  for (int i = pos + 1; i > 0; i -= i & -i)
    res += bit[i];
  return res;
}

int lb(int rank) {
  int res = 0;
  for (int i = 1 << 16; i > 0; i >>= 1)
    if (res + i <= N + 1 && bit[res + i] < rank)
      rank -= bit[res += i];
  return res;
}

void solve(int test_num) {
  cin >> N >> str;
  for (int i = 0; i <= N + 1; i++)
    bit[i] = 0;
  queue<int> q;
  for (int i = 0; i < N; i++) {
    if (i + 1 < N && str[i] == '4' && str[i + 1] == '7')
      q.push(i);
    update(i, 1);
  }
  update(N, 1); //sentinel
  str += '0';
  long long res = 0;
  while (!q.empty()) {
    vector<int> del;
    set<int> nq;
    for (; !q.empty(); q.pop()) {
      int pos = q.front(), rank = get(pos);
      //pln(pos, rank);
      res += rank;
      del.push_back(pos);
      del.push_back(lb(rank + 1));
    }
    for (int& p : del)
      update(p, -1);
    for (int i = 0; i < (int) del.size(); i += 2) {
      int pred = lb(get(del[i])), next = lb(get(del[i + 1]) + 1);
      //dbgln(pred);
      //dbgln(next);
      if (get(del[i]) > 0 && str[pred] == '4' && str[next] == '7')
        nq.insert(pred);
    }
    for (int x : nq)
      q.push(x);
  }
  cout << res << endl;
}

void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  int tests;
  cin >> tests;
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  PPLUCKY::solve();
  return 0;
}
