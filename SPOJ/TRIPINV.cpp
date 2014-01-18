/* Solved
 * 9650. Mega Inversions
 * File:   TRIPINV.cpp
 * Author: Andy Y.F. Huang
 * Created on May 23, 2013, 12:18 AM
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

namespace TRIPINV {

template <class T, size_t size> struct FenwickTree {
  T tree[size + 1];

  void init() {
    memset(tree, 0, sizeof (tree));
  }

  void update(int pos, T val) {
    for (int i = pos; i <= size; i += i&-i)
      tree[i] += val;
  }

  T query(int pos) const {
    T ans = 0;
    for (int i = pos; i > 0; i -= i&-i)
      ans += tree[i];
    return ans;
  }

} ;

#define OFFSET 100001
typedef long long llong;
FenwickTree<int, 111000 > cnt;
FenwickTree<llong, 111000 > invs;
int arr[111000];

void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%d", arr + i);
    arr[i] = -arr[i] + OFFSET;
  }
  llong res = 0;
  for (int i = 0; i < len; i++) {
    res += invs.query(arr[i] - 1);
    invs.update(arr[i], cnt.query(arr[i] - 1));
    cnt.update(arr[i], 1);
  }
  printf("%lld\n", res);

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
  TRIPINV::solve();
  return 0;
}

