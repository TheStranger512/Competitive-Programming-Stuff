/* Solved
 * 10810. Its a Murder!
 * File:   DCEPC206.cpp
 * Author: Andy Y.F. Huang
 * Created on August 3, 2012, 10:37 PM
 */

#include <cstdio>
#include <algorithm>
#include <ctime>
#include <cstring>

#ifdef AZN
#include "Azn.cpp"
#endif

namespace Int_Input {
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

inline int next_int() {
  char c;
  do {
    c = next_char();
  } while (c <= ' ');
  int ans = 0;
  while (c >= '0') {
    ans = (ans << 1) + (ans << 3);
    ans += char_to_int[c];
    c = next_char();
  }
  return ans;
}
}

using namespace Int_Input;
using namespace std;

/**
 * Solved
 * @author Andy Y.F. Huang
 */
namespace DCEPC206 {
struct Num {
  int val, pos;

  bool operator<(const Num& n) const {
    if (val != n.val)
      return val < n.val;
    return pos > n.pos;
  }
};

const int k_max_n = 100010;
long long tree[k_max_n];
Num nums[k_max_n];

void update(int pos, int val) {
  for (int i = pos; i < k_max_n; i += i&-i)
    tree[i] += val;
}

long long query(int pos) {
  long long val = 0;
  for (int i = pos; i > 0; i -= i&-i)
    val += tree[i];
  return val;
}

void solve(int test_num) {
  memset(tree, 0, sizeof (tree));
  int len = next_int();
  long long ans = 0, slow = 0;
  for (int i = 0; i < len; i++) {
    nums[i].val = next_int();
    nums[i].pos = i + 1;
//    for (int j = 0; j < i; j++)
//      if (nums[j].val < nums[i].val)
//        slow += nums[j].val;
  }
  sort(nums, nums + len);
  for (int i = 0; i < len; i++) {
    ans += query(nums[i].pos);
    update(nums[i].pos, nums[i].val);
  }
  printf("%lld\n", ans);
  //pln(slow);
}

void makecase() {
  srand(time(NULL));
  freopen("input.txt", "w", stdout);
  puts("1");
  int len = 10;
  printf("%d\n", len);
  for (int i = 0; i < len; i++)
    printf("%d ", rand() % 1000000);
}

void solve() {
  #ifdef AZN
  //makecase();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests = next_int();
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  DCEPC206::solve();
  return 0;
}

