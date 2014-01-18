/* Solved
 * 4350. Giá trị lớn nhất 3
 * Three trees lol
 * File:   QMAX3VN.cpp
 * Author: Andy Y.F. Huang
 * Created on December 8, 2012, 9:23 PM
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
namespace QMAX3VN {
#define lim (1 << 17)
int rmq[lim << 1], sum[lim];
int togo[lim], order[lim];
char str[5];
char op[lim];
int x[lim], y[lim];

bool cmp(int a, int b) {
  return y[a] < y[b] || (y[a] == y[b] && b < a);
}

void update(int pos, int val) {
  for (int i = pos + 1; i < lim; i += i&-i)
    sum[i] += val;
}

int getsum(int pos) {
  int ans = 0;
  for (int i = pos + 1; i; i -= i&-i)
    ans += sum[i];
  return ans;
}

int indexof(int val) {
  int pos = 0;
  for (int add = lim >> 1, total = 0; add; add >>= 1)
    if (total + sum[pos + add] < val) {
      pos += add;
      total += sum[pos];
    }
  return pos;
}

void solve(int test_num) {
  static int tree[lim];
  for (int i = 0; i < (lim << 1); i++)
    rmq[i] = -(1 << 30);
  int len, addcnt = 0;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%s %d %d", str, &x[i], &y[i]);
    op[i] = str[0];
    if (op[i] == 'A')
      order[addcnt++] = i;
  }

  //find final order of added ppl
  for (int i = 1; i <= addcnt; i++)
    for (int j = i; j <= addcnt; j += j&-j)
      tree[j]++;
  //plnarr(order, order + addcnt);
  for (int i = addcnt - 1; i >= 0; i--) {
    int& pos = togo[order[i]];
    for (int add = lim, total = 0; add; add >>= 1)
      if (pos + add <= addcnt && total + tree[pos + add] < y[order[i]])
        total += tree[pos += add];
    //pln(pos);
    for (int j = pos + 1; j <= addcnt; j += j&-j)
      tree[j]--;
  }

  //do RMQ
  //plnarr(togo, togo + len);
  for (int i = 0; i < len; i++) {
    if (op[i] == 'A') {
      int pos = togo[i];
      rmq[pos + lim] = x[i];
      for (int id = (pos + lim) >> 1; id; id >>= 1)
        rmq[id] = max(rmq[id + id], rmq[id + id + 1]);
      //pln(rmq[1]);
      update(pos, 1);
    }
    else {
      int ans = -(1 << 30);
      //pln(indexof(x[i]), indexof(y[i]));
      for (int l = indexof(x[i]) + lim, r = indexof(y[i]) + lim + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = max(ans, rmq[l++]);
        if (r & 1) ans = max(ans, rmq[--r]);
      }
      printf("%d\n", ans);
    }
  }
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
  QMAX3VN::solve();
  return 0;
}

