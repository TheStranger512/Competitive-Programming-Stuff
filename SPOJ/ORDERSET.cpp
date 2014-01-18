/* Solved
 * 3273. Order statistic set
 * File:   ORDERSET.cpp
 * Author: Andy Y.F. Huang
 * Created on August 27, 2012, 5:36 PM
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
namespace ORDERSET {
const int k_max_size = 200010;
int tree[k_max_size] = {0};
bool have[k_max_size] = {0};
int val[k_max_size], order[k_max_size], hash[k_max_size], revhash[k_max_size];
char type[k_max_size];

void update(int pos, int val, int size) {
  for (int i = pos; i <= size; i |= (i + 1))
    tree[i] += val;
}

int query(int pos) {
  int ans = 0;
  for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
    ans += tree[i];
  return ans;
}

bool cmp(int a, int b) {
  return val[a] < val[b];
}

void solve(int test_num) {
  int size, curhash = 0;
  scanf("%d\r\n", &size);
  for (int i = 0; i < size; i++) {
    scanf("%c %d\r\n", &type[i], &val[i]);
    order[i] = i;
  }
  sort(order, order + size, cmp);
  for (int i = 0, prev = 1234567890; i < size; i++) {
    if (val[order[i]] == prev)
      hash[order[i]] = curhash, revhash[curhash] = order[i];
    else {
      hash[order[i]] = ++curhash;
      prev = val[order[i]];
      revhash[curhash] = order[i];
    }
  }
  for (int i = 0, cnt = 0; i < size; i++) {
    if (type[i] == 'I' && !have[hash[i]]) {
      update(hash[i], 1, curhash);
      have[hash[i]] = true;
      cnt++;
    }
    else if (type[i] == 'D' && have[hash[i]]) {
      update(hash[i], -1, curhash);
      have[hash[i]] = false;
      cnt--;
    }
    else if (type[i] == 'K') {
      if (val[i] > cnt) {
        puts("invalid");
        continue;
      }
      int low = 0, high = curhash;
      while (low < high) {
        int mid = (low + high) >> 1;
        int rank = query(mid);
        if (rank < val[i])
          low = mid + 1;
        else
          high = mid;
      }
      printf("%d\n", val[revhash[low]]);
    }
    else if (type[i] == 'C')
      printf("%d\n", query(hash[i] - 1));
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
  ORDERSET::solve();
  return 0;
}

