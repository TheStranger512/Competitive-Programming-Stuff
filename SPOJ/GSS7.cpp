/*
 * Solved
 * 6779. Can you answer these queries VII
 * File:   GSS7.cpp
 * Author: Andy Y.F. Huang
 * Created on March 25, 2013, 8:50 PM
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

namespace GSS7 {
const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
unsigned int bytes_read = 0;
unsigned int input_index = 0;

inline char next_char() {
  if (input_index == bytes_read) {
    bytes_read = fread(input_buffer, sizeof (char) , buffer_size, stdin);
    input_buffer[bytes_read] = '\0'; //sentinel
    input_index = 0;
  }
  return input_buffer[input_index++];
}

inline int next_int() {
  char c = 0;
  int ans = 0;
  while (c < '-') c = next_char();
  bool neg;
  if (c == '-')
    neg = true, c = next_char();
  else
    neg = false;
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += c - '0';
    c = next_char();
  }
  return neg ? -ans : ans;
}

char output_buffer[buffer_size];
unsigned int output_index = 0;

inline void write_flush() {
  fwrite(output_buffer, sizeof (char) , output_index, stdout);
  output_index = 0;
}

inline void write_char(char c) {
  output_buffer[output_index++] = c;
  if (output_index == buffer_size)
    write_flush();
}

inline void write_int(int num) {
  if (num >= 10)
    write_int(num / 10);
  write_char(num % 10 + '0');
}

struct Node {
  int pre, total, sub, suff;

  void operator()(const Node& l, const Node & r) {
    static Node temp;
    temp.total = l.total + r.total;
    temp.pre = max(l.pre, l.total + r.pre);
    temp.suff = max(r.suff, r.total + l.suff);
    temp.sub = max(max(l.sub, r.sub), l.suff + r.pre);
    *this = temp;
  }

  void reverse() {
    swap(pre, suff);
  }

  void update(int val, int len) {
    total = val * len;
    pre = sub = suff = max(val, total);
  }

  void fill(int val) {
    pre = total = sub = suff = val;
  }

  friend ostream& operator<<(ostream& out, const Node & x) {
    return out << '(' << x.pre << ',' << x.total << ',' << x.sub << ',' << x.suff << ')';
  }

} ;
#define MAX 111000
#define INF 1050111000
#define lch(x) (x<<1)
#define rch(x) (x<<1|1)
#define mid ((x + y)>>1)
int last[MAX], to[2 * MAX], next[2 * MAX];
int val[MAX];
int top[MAX], timein[MAX], timeout[MAX], size[MAX], par[17][MAX];
int pos[MAX], invpos[MAX];
const Node NEUTRAL = {-INF, 0, -INF, -INF};
Node tree[3 * MAX];
int lazy[3 * MAX];
int len, X, Y, toset, MAXLOG;

int nextpos() {
  static int pos = 1;
  return pos++;
}

int nexttime() {
  static int T = 1;
  return T++;
}

void dfs1(int at) {
  size[at] = 1;
  timein[at] = nexttime();
  for (int id = last[at]; id > -1; id = next[id]) {
    if (to[id] != par[0][at]) {
      par[0][to[id]] = at;
      dfs1(to[id]);
      size[at] += size[to[id]];
    }
  }
  timeout[at] = nexttime();
}

void dfs2(int at, int curtop) {
  top[at] = curtop;
  pos[at] = nextpos();
  invpos[pos[at]] = at;
  int heavy = -1;
  for (int id = last[at]; id > -1; id = next[id])
    if (to[id] != par[0][at] && (heavy == -1 || size[to[id]] > size[heavy]))
      heavy = to[id];
  if (heavy == -1) return;
  dfs2(heavy, curtop);
  for (int id = last[at]; id > -1; id = next[id])
    if (to[id] != par[0][at] && to[id] != heavy)
      dfs2(to[id], to[id]);
}

bool isanc(int a, int b) {
  return timein[a] <= timein[b] && timeout[b] <= timeout[a];
}

int getlca(int A, int B) {
  if (isanc(A, B)) return A;
  for (int i = MAXLOG; i >= 0; i--)
    if (!isanc(par[i][A], B))
      A = par[i][A];
  return par[0][A];
}

void prog(int node, int x, int y) {
  if (lazy[node] == INF) return;
  lazy[lch(node)] = lazy[rch(node)] = lazy[node];
  tree[lch(node)].update(lazy[node], mid - x + 1);
  tree[rch(node)].update(lazy[node], y - mid);
  lazy[node] = INF;
}

Node asktree(int node, int x, int y) {
  if (X > y || Y < x) return NEUTRAL;
  if (X <= x && y <= Y) return tree[node];
  prog(node, x, y);
  Node res;
  res(asktree(lch(node), x, mid), asktree(rch(node), mid + 1, y));
  return res;
}

void updatetree(int node, int x, int y) {
  if (X > y || Y < x) return;
  if (X <= x && y <= Y) {
    tree[node].update(toset, y - x + 1);
    lazy[node] = toset;
    return;
  }
  prog(node, x, y);
  updatetree(lch(node), x, mid);
  updatetree(rch(node), mid + 1, y);
  tree[node](tree[lch(node)], tree[rch(node)]);
}

void buildtree(int node, int x, int y) {
  lazy[node] = INF;
  if (x == y)
    tree[node].fill(val[invpos[x]]);
  else {
    buildtree(lch(node), x, mid);
    buildtree(rch(node), mid + 1, y);
    tree[node](tree[lch(node)], tree[rch(node)]);
  }
}

Node query(int A, int B) {
  //depth[A] > depth[B]
  //does not include B
  Node res = NEUTRAL;
  while (top[A] != top[B]) {
    X = pos[top[A]];
    Y = pos[A];
    res(asktree(1, 1, len), res);
    A = par[0][top[A]];
  }
  X = pos[B] + 1;
  Y = pos[A];
  if (X <= Y)
    res(asktree(1, 1, len), res);
  return res;
}

void update(int A, int B) {
  //depth[A] > depth[B]
  //does not include B
  while (top[A] != top[B]) {
    X = pos[top[A]];
    Y = pos[A];
    updatetree(1, 1, len);
    A = par[0][top[A]];
  }
  X = pos[B] + 1;
  Y = pos[A];
  if (X <= Y)
    updatetree(1, 1, len);
}

void solve(int test_num) {
  memset(last, -1, sizeof (last));
  len = next_int();
  for (int i = 1; i <= len; i++)
    val[i] = next_int();
  for (int i = 1, e = 0, a, b; i < len; i++) {
    a = next_int();
    b = next_int();
    to[e] = b;
    next[e] = last[a];
    last[a] = e++;
    to[e] = a;
    next[e] = last[b];
    last[b] = e++;
  }
  MAXLOG = 0;
  while ((1 << (MAXLOG + 1)) < len)
    MAXLOG++;
  par[0][1] = 1;
  dfs1(1);
  dfs2(1, 1);
  for (int j = 1; j <= MAXLOG; j++)
    for (int i = 1; i <= len; i++)
      par[j][i] = par[j - 1][par[j - 1][i]];

  //plnarr(pos + 1, pos + len + 1);
  //plnarr(invpos + 1, invpos + len + 1);
  //plnarr(top + 1, top + len + 1);
  buildtree(1, 1, len);
  int quests = next_int();
  Node temp, first, second;
  for (int q = 0, type, lca, res, A, B; q < quests; q++) {
    type = next_int();
    A = next_int();
    B = next_int();
    lca = getlca(A, B);
    //pln("node:",A, B, lca);
    X = Y = pos[lca];
    if (type == 1) {
      temp = asktree(1, 1, len);
      first = query(A, lca);
      second = query(B, lca);
      //pln(temp, first, second);
      first.reverse();
      temp(first, temp);
      temp(temp, second);
      res = max(0, temp.sub);
      write_int(res);
      write_char('\n');
    }
    else {
      toset = next_int();
      updatetree(1, 1, len);
      update(A, lca);
      update(B, lca);
    }
  }
}

/*
 * GSS3
 */
//void solve(int test_num) {
//  int len = next_int();
//  for (int i = 1; i <= len; i++) {
//    val[i] = next_int();
//    invpos[i] = i;
//  }
//  buildtree(1, 1, len);
//  int quests = next_int();
//  for (int q = 0; q < quests; q++) {
//    int type = next_int();
//    X = next_int();
//    if (type == 0) {
//      Y = X;
//      toset = next_int();
//      updatetree(1, 1, len);
//    }
//    else {
//      Y = next_int();
//      int res = asktree(1, 1, len).sub;
//      if (res < 0) {
//        write_char('-');
//        res = -res;
//      }
//      write_int(res);
//      write_char('\n');
//    }
//  }
//}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  solve(1);
  write_flush();
}
}

int main() {
  GSS7::solve();
  return 0;
}

