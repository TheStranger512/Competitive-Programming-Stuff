/* Solved
 * Farmer
 * File:   ioi0422.cpp
 * Author: Andy Huang
 * Created on March 25, 2012, 6:38 PM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
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

#define forl(a,b,c) for (int a=b;a<c;a++)
#define ford(a,b,c) for (int a=b;a>=c;a--)
#define gl(s) getline(cin,s)
#define pln(x) cout << x << endl
#define ve(x) vector<x>
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define ms(x,n) memset(x,n,sizeof(x))
#define si(x) scanf("%d",&x)

using namespace std;

unsigned char fi[2000];
unsigned char str[2000];
bool dp[150001];

bool comp(const int& a, const int& b){
  return b < a;
}

void solve() {
  ms(dp,0);
  int q,n,m,bigf = 0, high = 0;
  scanf("%d %d %d",&q,&n,&m);
  forl(i,0,n){
    si(fi[i]);
    bigf = max(bigf,(int)fi[i]);
  }
  forl(i,0,m){
    si(str[i]);
  }
  dp[0] = 1;
//  sort(fi,fi+n);
  sort(str,str+m,comp);
  forl(i,0,n){
    ford(j,q,0){
      if (dp[j] && j+fi[i] <= q){
        dp[j+fi[i]] = true;
      }
    }
  }
  int ans;
  ford(i,q,0){
    if (dp[i]){
      ans = i;
      high = i;
      break;
    }
  }
  int i = 0;
  while (high < q){
    if (high + str[i] <= q){
      ans += str[i]-1;
      high += str[i];
    }
    else{
      int sum = q-high;
      high += sum;
      ans += sum - 1;
    }
    i++;
  }
  if (bigf >= q && q-1 > ans)
    pln(q-1);
  else
    pln(ans);
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}
