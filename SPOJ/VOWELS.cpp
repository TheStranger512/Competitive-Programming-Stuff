/* Solved
 * 11333. Vowels - simple counting number of vowels
 * File:   VOWELS.cpp
 * Author: Andy Huang
 * Created on May 4, 2012, 11:33 PM
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

using namespace std;

char input[10005];

void solve() {
  gets(input);
  int len = strlen(input);
  int ans = 0;
  for (int i = 0; i < len; i++) {
    switch (input[i]) {
      case 'a': case 'e': case 'i': case 'o': case 'u':
      case 'A': case 'E': case 'I': case 'O': case 'U':
        ans++;
    }
  }
  printf("%d\n", ans);

}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
  return 0;
}

