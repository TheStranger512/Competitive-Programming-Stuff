/* Solved
 * 11063. AP - Complete The Series (Easy)
 * File:   AP2.cpp
 * Author: Andy Huang
 * Created on March 13, 2012, 12:20 PM
 */

#include <stdio.h>

#define forl(a,b,c) for (int a=b;a<c;a++)
#define si(x) scanf("%d",&x)
#define pf(x) printf("%lld ",x)
#define ll unsigned long long

using namespace std;

void solve() {
  ll a, b, sn;
  ll n, d;
  scanf("%lld %lld %lld",&a, &b, &sn);
  n = (sn << 1)/ (b+a);
  d = (b-a)/(n-5);
  a = a - (d << 1);
  printf("%lld\n", n);
  int i = 0;
  while (i < n){
    pf(a);
    a += d;
    i++;
  }
  printf("\n");
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  si(t);
  while (t--){
    solve();
  }
  return 0;
}

