/* Solved
 * IOI '07 - Zagreb, Croatia
 * Sails
 * File:   ioi0713.cpp
 * Author: Andy Y.F. Huang
 * Created on December 20, 2012, 5:00 PM
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
namespace ioi0713 {

struct Mast {
  int sails, height;

  bool operator<(const Mast & m) const {
    return height < m.height;
  }
} ;

#define maxh (100010)
int len;
int tree[maxh + 5];
Mast masts[maxh + 5];

void update(int pos, int val) {
  for (int i = pos; i <= maxh; i += i&-i)
    tree[i] += val;
}

int query(int pos) {
  int ans = 0;
  for (int i = pos; i; i -= i&-i)
    ans += tree[i];
  return ans;
}

int lowbound(int val) {
  int ans = maxh;
  for (int low = 1, high = maxh; low <= high; ) {
    int mid = (low + high) >> 1;
    if (query(mid) <= val) {
      ans = min(ans, mid);
      high = mid - 1;
    }
    else low = mid + 1;
  }
  return ans;
}

int upbound(int val) {
  int ans = maxh;
  for (int low = 1, high = maxh; low <= high; ) {
    int mid = (low + high) >> 1;
    if (query(mid) < val) {
      ans = min(ans, mid);
      high = mid - 1;
    }
    else low = mid + 1;
  }
  return ans - 1;
}

void solve(int test_num) {
  memset(tree, 0, sizeof (tree));
  scanf("%d", &len);
  for (int i = 0; i < len; i++)
    scanf("%d %d", &masts[i].height, &masts[i].sails);
  sort(masts, masts + len);
  for (int i = 0; i < len; i++) {
    int height = masts[i].height, cnt = masts[i].sails;
    int sum = query(height - cnt + 1);
    int low = lowbound(sum), high = min(height, upbound(sum));
    //pln(low, high);
    if (low < height - cnt + 1) {
      update(low, 1);
      update(low + high - (height - cnt), -1);
      if (high != height) {
        update(high + 1, 1);
        update(height + 1, -1);
      }
    }
    else {
      update((height - cnt + 1), 1);
      update(height + 1, -1);
    }
    //plnarr(tree + 1, tree + 1 + len);
    //    for (int j = 1; j <= len; j++)
    //      printf("%d ", query(j));
    //    putchar('\n');
  }
  //pln(lowbound(0));
  long long ans = 0;
  for (int i = 1; i <= maxh; i++) {
    int sum = query(i);
    ans += 1LL * sum * (sum - 1) / 2;
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
  ioi0713::solve();
  return 0;
}

