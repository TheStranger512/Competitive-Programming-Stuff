/* Solved
 * 4480. Chaos Strings - sorting and bit
 * File:   MCHAOS.cpp
 * Author: Andy Y.F. Huang
 * Created on September 11, 2012, 10:19 PM
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

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace MCHAOS {
const unsigned int buffer_size = 1 << 16;
char input_buffer[buffer_size];
const unsigned int char_to_int[58] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                      11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                                      21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                                      31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                                      41, 42, 43, 44, 45, 46, 47,
                                      0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
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
  char c;
  do {
    c = next_char();
  } while (c <= ' ');
  do {
    *str++ = c;
    c = next_char();
  } while (c > ' ');
  *str = '\0';
  return str;
}

char str[100010][15];
int len[100010], order1[100010], order2[100010], hash[100010];
long long tree[100010] = {0};

void update(int pos, int val) {
  for (int i = ++pos; i < 100010; i += i&-i)
    tree[i] += val;
}

long long query(int pos) {
  long long ans = 0;
  for (int i = ++pos; i > 0; i -= i&-i)
    ans += tree[i];
  return ans;
}

bool cmp(int a, int b) {
  return strcmp(str[a], str[b]) < 0;
}

bool cmp2(int a, int b) {
  for (int i = len[a] - 1, j = len[b] - 1; i >= 0 && j >= 0; i--, j--) {
    if (str[a][i] < str[b][j])
      return true;
    else if (str[a][i] > str[b][j])
      return false;
  }
  return len[a] < len[b];
}

void solve(int test_num) {
  int words;
  long long ans = 0;
  scanf("%d", &words);
  for (int i = 0; i < words; i++) {
    len[i] = next_str(str[i]) - str[i];
    order1[i] = order2[i] = i;
  }
  sort(order1, order1 + words, cmp);
  sort(order2, order2 + words, cmp2);
  //plnarr(order1, order1 + words);
  //plnarr(order2, order2 + words);
  for (int i = 0; i < words; i++)
    hash[order2[i]] = i;
  for (int i = 0; i < words; i++) {
    ans += i - query(hash[order1[i]]);
    update(hash[order1[i]], 1);
  }
  printf("%lld\n", ans);
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
  MCHAOS::solve();
  return 0;
}

