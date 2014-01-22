/* Solved
 * August Challenge 2013
 * Music & Lyrics
 * File:   LYRC.cpp
 * Author: Andy Y.F. Huang
 * Created on August 2, 2013, 2:47 PM
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

namespace LYRC {
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

inline char* next_str(char* str) {
  char c = 0;
  while (c <= ' ') c = next_char();
  do {
    *str++ = c;
    c = next_char();
  } while (c > ' ');
  *str = '\0';
  return str;
}

inline int next_int() {
  char c = 0;
  int ans = 0;
  while (c < '-') c = next_char();
  for (; c >= '0'; c = next_char()) ans = (ans << 1) + (ans << 3) + c - '0';
  return ans;
}

struct Node {
  Node * child[63], *fail;
  int cnt;
} ;

typedef Node* pNode;
pNode root;
vector<pNode> q;
char str[55555];
pNode leaf[555];
char word[5555];

char ord(char c) {
  if (c == '-') return 62;
  if (islower(c)) return c - 'a';
  if (isupper(c)) return c - 'A' + 26;
  return c - '0' + 52;
}

void solve(int test_num) {
  int W = next_int();
  char *p, *end;
  pNode at, fa;
  root = new Node();
  for (int i = 0, c; i < W; i++) {
    end = next_str(word);
    at = root;
    for (p = word; p != end; p++) {
      c = ord(*p);
      if (!at->child[c])
        at->child[c] = new Node();
      at = at->child[c];
    }
    leaf[i] = at;
  }
  q.push_back(root);
  for (int c, i = 0; i < (int) q.size(); i++) {
    at = q[i];
    for (c = 0; c < 63; c++) {
      if (!at->child[c]) continue;
      fa = at->fail;
      while (fa && !fa->child[c])
        fa = fa->fail;
      if (!fa)
        at->child[c]->fail = root;
      else
        at->child[c]->fail = fa->child[c];
      q.push_back(at->child[c]);
    }
  }
  int N = next_int();
  for (int i = 0, c; i < N; i++) {
    end = next_str(str);
    //pln(str);
    at = root;
    for (p = str; p != end; p++) {
      c = ord(*p);
      while (at && !at->child[c])
        at = at->fail;
      if (!at)
        at = root;
      else {
        at = at->child[c];
        at->cnt++;
      }
    }
  }
  for (; q.size() > 1; q.pop_back())
    q.back()->fail->cnt += q.back()->cnt;
  for (int i = 0; i < W; i++)
    printf("%d\n", leaf[i]->cnt);
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
  LYRC::solve();
  return 0;
}

