/* Solved
 * August Challenge 2013
 * Prime Distance On Tree
 * File:   PRIMEDST.cpp
 * Author: Andy Y.F. Huang
 * Created on August 2, 2013, 4:12 PM
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

namespace PRIMEDST {

template <class T, size_t MAXSIZE> struct Vector {
  T arr[MAXSIZE + 1], *last;

  Vector() : last(arr) { }

  void clear() {
    last = arr;
  }

  int size() {
    return last - arr;
  }

  void push_back(const T & val) {
    *last++ = val;
  }

  void pop_back() {
    last--;
  }

  T * begin() {
    return arr;
  }

  T * end() {
    return last;
  }

  T& operator[](size_t pos) {
    return arr[pos];
  }

  T & front() {
    return *arr;
  }

  T & back() {
    return *(last - 1);
  }

} ;

#define MAX 50055
typedef long long ll;
bool del[MAX], isprime[MAX];
int last[MAX], to[2 * MAX], pred[2 * MAX];
queue<int> next;
int cnt[MAX], size[MAX], opt[MAX];
int maxdist;
Vector<int, MAX> primes, all, dist;

void dfs1(int at, int par) {
  all.push_back(at);
  size[at] = 1;
  opt[at] = 0;
  for (int e = last[at]; ~e; e = pred[e]) {
    if (to[e] != par && !del[to[e]]) {
      dfs1(to[e], at);
      opt[at] = max(opt[at], size[to[e]]);
      size[at] += size[to[e]];
    }
  }
}

void dfs2(int at, int par, int cdist) {
  dist.push_back(cdist);
  maxdist = max(maxdist, cdist);
  for (int e = last[at]; ~e; e = pred[e])
    if (to[e] != par && !del[to[e]])
      dfs2(to[e], at, cdist + 1);
}

ll go(int start) {
  all.clear();
  int cent = -1, minsize = MAX;
  dfs1(start, -1);
  for (int i = 0, temp; i < all.size(); i++) {
    temp = max(all.size() - size[all[i]], opt[all[i]]);
    if (temp < minsize) {
      minsize = temp;
      cent = all[i];
    }
  }
  for (int i = 0; i < all.size(); i++)
    cnt[i] = 0;
  del[cent] = true;
  //pln("Centroid:", cent);
  //plnarr(cnt, cnt + N);
  cnt[0] = 1;
  ll res = 0;
  for (int e = last[cent], pmax = 0, i, j, k, l, lim; ~e; e = pred[e]) {
    if (del[to[e]]) continue;
    next.push(to[e]);
    dist.clear();
    maxdist = 0;
    dfs2(to[e], cent, 1);
    sort(dist.begin(), dist.end());
    for (i = 0, j = 0; i < dist.size(); i = k) {
      for (k = i; k < dist.size() && dist[i] == dist[k]; )
        k++;
      while (primes[j] < dist[i])
        j++;
      lim = dist[i] + pmax;
      for (l = j; primes[l] <= lim; l++)
        res += ll(k - i) * cnt[primes[l] - dist[i]];
    }
    for (int i = 0; i < dist.size(); i++)
      cnt[dist[i]]++;
    pmax = max(pmax, maxdist);
  }
  return res;
}

void sieve() {
  memset(isprime, true, sizeof (isprime));
  isprime[0] = isprime[1] = true;
  primes.clear();
  for (int i = 2; i * i < MAX; i++)
    if (isprime[i])
      for (int j = i * i; j < MAX; j += i)
        isprime[j] = false;
  primes.push_back(2);
  for (int i = 3; i < MAX; i += 2)
    if (isprime[i])
      primes.push_back(i);
  primes.push_back(1000000007);
  //5133 prime numbers
  //pln("# of primes: ", primes.size());
  //pln(primes.back());
}

void add_edge(int a, int b) {
  static int e = 0;
  to[e] = b;
  pred[e] = last[a];
  last[a] = e++;
}

void solve(int test_num) {
  memset(last, -1, sizeof (last));
  int V;
  scanf("%d", &V);
  for (int i = 1, a, b; i < V; i++) {
    scanf("%d %d", &a, &b);
    add_edge(a, b);
    add_edge(b, a);
  }
  sieve();
  ll res = 0;
  memset(del, false, sizeof (del));
  next.push(1);
  for (; !next.empty(); next.pop())
    res += go(next.front());
  printf("%.7lf\n", 2.0 * res / V / (V - 1));
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
  PRIMEDST::solve();
  return 0;
}

