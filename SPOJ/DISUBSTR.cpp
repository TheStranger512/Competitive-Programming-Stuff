/* Solved
 * 694. Distinct Substrings - suffix array
 * File:   DISUBSTR.cpp
 * Author: Andy Huang
 * Created on May 21, 2012, 7:16 PM
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

struct SuffixArray {
private:
  unsigned int size;
  std::string* suffix;
  unsigned int* location;
  unsigned int* lcp; //longest common prefix array

public:

  SuffixArray() {
  }

  SuffixArray(const std::string & str) {
    size = str.length();
    suffix = new std::string[size];
    location = new unsigned int[size];
    lcp = new unsigned int[size];
    for (unsigned int i = 0; i < size; i++)
      suffix[i] = str.substr(i);
    std::sort(suffix, suffix + size);
    if (size) {
      lcp[0] = 0;
      location[0] = size - suffix[0].length();
    }
    for (unsigned int i = 1; i < size; i++) {
      lcp[i] = findlcp(i - 1, i);
      location[i] = size - suffix[i].length();
    }
  }

  ~SuffixArray() {
    delete [] suffix;
    delete [] location;
    delete [] lcp;
  }

  unsigned int length()const {
    return size;
  }

  unsigned int getlcp(unsigned int index)const {
    return lcp[index];
  }

  const std::string & getsuffix(unsigned int index)const {
    return suffix[index];
  }

  int search(const std::string & query) {
    unsigned int low = 0;
    unsigned int high = size - 1;
    while (low < high) {
      unsigned int mid = (low + high) >> 1;
      int compare = query.compare(suffix[mid]);
      if (compare > 0)
        low = mid + 1;
      else
        high = mid;
    }
    if (high == low && query.compare(suffix[low]) == 0)
      return low;
    else
      return -1;
  }

private:

  unsigned int findlcp(unsigned int j, unsigned int k)const {
    unsigned int len = std::min(suffix[j].length(), suffix[k].length());
    for (unsigned int i = 0; i < len; i++)
      if (suffix[j][i] != suffix[k][i])
        return i;
    return len;
  }

};

using namespace std;

char str[1050];

void solve() {
  scanf("%s", str);
  string real(str);
  SuffixArray sa(real);
  int ans = real.length();
  ans = ans * (ans + 1) >> 1;
  for (unsigned int i = 0; i < sa.length(); i++)
    ans -= sa.getlcp(i);
  printf("%d\n", ans);
}

int main() {
  #ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tests;
  scanf("%d", &tests);
  while (tests--)
    solve();
  return 0;
}

