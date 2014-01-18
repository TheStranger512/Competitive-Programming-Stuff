/* Solved
 * 6294. Yodaness Level
 * File:   YODANESS.cpp
 * Author: Andy Y.F. Huang
 * Created on July 30, 2012, 8:14 PM
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
namespace YODANESS {

struct Compare {

  bool operator()(const char* a, const char* b) const {
    return strcmp(a, b) < 0;
  }
} ;
map<char*, int, Compare> hash;
const int k_max_len = 30010;
const int k_max_word_len = 25;
int tree[k_max_len];
char str[k_max_len][k_max_word_len];

void update(int pos, int val, int size) {
  for (int i = pos; i < size; i |= (i + 1))
    tree[i] += val;
}

int query(int pos) {
  int ans = 0;
  for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
    ans += tree[i];
  return ans;
}

void solve(int test_num) {
  memset(tree, 0, sizeof (tree));
  hash.clear();
  int size, yodaness = 0;
  scanf("%d", &size);
  for (int i = 0; i < size; i++) {
    scanf("%s\r\n", str[i]);
    hash[str[i]] = i;
  }
  for (int i = 0; i < size; i++) {
    char word[k_max_word_len];
    scanf("%s\r\n", word);
    update(hash[word], 1, size);
    yodaness += query(size - 1) - query(hash[word]);

  }
  printf("%d\n", yodaness);
}

void solve() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  YODANESS::solve();
  return 0;
}

