/* Solved
 * IOI 2009 - Garage
 * File:   ioi0921.cpp
 * Author: Andy Huang
 * Created on March 31, 2012, 11:58 AM
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

int rate[105];
int gar[105];
int w[10005];
queue<int> q;

void solve() {
  ms(gar,-1);
  int n, m;
  si(n);
  si(m);
  forl(i,0,n){
    si(rate[i]);
  }
  forl(i,0,m){
    si(w[i]);
  }
  int spots = n;
  int ans = 0;
  forl(z,0,2*m){
    int x;
    si(x);
    if (x >= 0){
      x--;
      if (spots){
        forl(i,0,n){
          if (gar[i] == -1){
            gar[i] = x;
            ans += rate[i]*w[x];
            spots--;
            break;
          }
        }
      }
      else
        q.push(x);
    }
    else{
      x = -x-1;
      forl(i,0,n){
        if (gar[i] == x){
          gar[i] = -1;
          if (!q.empty()){
            gar[i] = q.front();
            q.pop();
            ans += rate[i]*w[gar[i]];
          }
          else
            spots++;
          break;
        }
      }
    }
    //pln(ans);
  }
  pln(ans);
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}

