/*
 * Solved
 * 9510. Ads Proposal
 * File:   ADSPROP.cpp
 * Author: Andy Y.F. Huang
 * Created on September 25, 2012, 11:26 PM
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
namespace ADSPROP {
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

inline void next_int(int& ans) {
  char c = 0;
  ans = 0;
  while (c < '-') c = next_char();
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += char_to_int[c];
    c = next_char();
  }
}

const char digit_to_char[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
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

inline void write_int(long long num) {
  if (num >= 10)
    write_int(num / 10);
  write_char(digit_to_char[num % 10]);
}

int id[500100], clicks[500100], len[500100];
int order[500100];
long long ans[500500];

inline bool comp(const int a, const int b) {
  return id[a] < id[b] || (id[a] == id[b] && clicks[a] > clicks[b]);
}

void solve(int test_num) {
  //memset(ans, 0, sizeof (ans));
  int users, adcnt, queries;
  //scanf("%d %d %d", &users, &adcnt, &queries);
  next_int(users), next_int(adcnt), next_int(queries);
  for (int i = 0; i <= adcnt; i++)
    ans[i] = 0;
  for (int i = 0; i < adcnt; i++) {
    next_int(id[i]);
    next_int(clicks[i]);
    next_int(len[i]);
    order[i] = i;
  }
  stable_sort(order, order + adcnt, comp);
  for (int i = 0; i < adcnt; ) {
    int cid = id[order[i]], cnt = 1, j = i;
    while (j < adcnt && id[order[j]] == cid) {
      ans[cnt++] += len[order[j]];
      j++;
    }
    i = j;
  }
  for (int i = 1; i <= adcnt; i++)
    ans[i] += ans[i - 1];
  write_char('C');
  write_char('a');
  write_char('s');
  write_char('e');
  write_char(' ');
  write_char('#');
  write_int(test_num);
  write_char(':');
  write_char('\n');
  //printf("Case #%d:\n", test_num);
  for (int q = 0, k; q < queries; q++) {
    //scanf("%d", &k);
    next_int(k);
    //printf("%lld\n", ans[min(adcnt, k)]);
    write_int(ans[min(adcnt, k)]);
    write_char('\n');
  }
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  next_int(tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
  write_flush();
}
}

int main() {
  ADSPROP::solve();
  return 0;
}

