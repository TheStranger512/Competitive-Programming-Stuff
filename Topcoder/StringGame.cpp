/*
 * Solved
 * SRM 567 Div1 Medium
 * Author: Andy Y.F. Huang
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

using namespace std;

#ifdef AZN
#include "Azn.cpp"
#endif

class StringGame {
public:
  vector <int> getWinningStrings(vector <string> S);
} ;

int cnt[55][27];
bool used[33], active[55];

vector <int> StringGame::getWinningStrings(vector <string> strs) {
  memset(cnt, 0, sizeof (cnt));
  int len = strs.size(), slen = strs[0].size();
  vector<int> ans;
  for (int i = 0; i < len; i++)
    for (int a = 0; a < slen; a++)
      cnt[i][strs[i][a] - 'a']++;
  for (int i = 0; i < len; i++) {
    memset(used, false, sizeof (used));
    memset(active, true, sizeof (active));
    active[i] = false;
    int activecnt = len - 1;
    while (true) {
      int pick = -1;
      for (int c = 0; c < 26; c++) {
        if (used[c]) continue;
        bool ok = true;
        for (int j = 0; j < len; j++)
          if (active[j] && cnt[j][c] > cnt[i][c])
            ok = false;
        if (ok) {
          pick = c;
          break;
        }
      }
      if (pick == -1) break;
      used[pick] = true;
      for (int j = 0; j < len; j++)
        if (active[j] && cnt[j][pick] < cnt[i][pick])
          active[j] = false, activecnt--;
    }
    if (activecnt == 0) ans.push_back(i);
  }
  return ans;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof

bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, vector <int> p1) {
  cout << "Test " << testNum << ": [" << "{";
  for (int i = 0; int(p0.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << "\"" << p0[i] << "\"";
  }
  cout << "}";
  cout << "]" << endl;
  StringGame *obj;
  vector <int> answer;
  obj = new StringGame();
  clock_t startTime = clock();
  answer = obj->getWinningStrings(p0);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
      if (i > 0) {
        cout << ",";
      }
      cout << p1[i];
    }
    cout << "}" << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << "{";
  for (int i = 0; int(answer.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << answer[i];
  }
  cout << "}" << endl;
  if (hasAnswer) {
    if (answer.size() != p1.size()) {
      res = false;
    }
    else {
      for (int i = 0; int(answer.size()) > i; ++i) {
        if (answer[i] != p1[i]) {
          res = false;
        }
      }
    }
  }
  if (!res) {
    cout << "DOESN'T MATCH!!!!" << endl;
  }
  else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
    cout << "FAIL the timeout" << endl;
    res = false;
  }
  else if (hasAnswer) {
    cout << "Match :-)" << endl;
  }
  else {
    cout << "OK, but is it right?" << endl;
  }
  cout << "" << endl;
  return res;
}

int main() {
  #ifdef AZN
  freopen("output.txt", "w", stdout);
  #endif

  bool all_right;
  all_right = true;

  vector <string> p0;
  vector <int> p1;

  {
    // ----- test 0 -----
    string t0[] = {"a", "b", "c", "d"};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    int t1[] = {0, 1, 2, 3};
    p1.assign(t1, t1 + sizeof (t1) / sizeof (t1[0]));
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    string t0[] = {"aabbcc", "aaabbb", "aaaccc"};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    int t1[] = {1, 2};
    p1.assign(t1, t1 + sizeof (t1) / sizeof (t1[0]));
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    string t0[] = {"ab", "ba"};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    p1.clear() /*{}*/;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    string t0[] = {"xaocxsss", "oooxsoas", "xaooosss", "xaocssss", "coxaosxx"};
    p0.assign(t0, t0 + sizeof (t0) / sizeof (t0[0]));
    int t1[] = {1, 3, 4};
    p1.assign(t1, t1 + sizeof (t1) / sizeof (t1[0]));
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
    // ------------------
  }

  if (all_right) {
    cout << "You're a stud (at least on the example cases)!" << endl;
  }
  else {
    cout << "Some of the test cases had errors." << endl;
  }
  return 0;
}
// PROBLEM STATEMENT
// Manao has invented a new unusual two-player game which he calls the String Game. The game is played on a set of strings of the same length comprised of lowercase English letters.
//
// In the beginning, the first player chooses a string X from the set and permutes its characters in any way he wants. He also chooses a permutation of the English alphabet. After that, the second player may permute the characters in each of the strings in the set, except for X. Now X is lexicographically compared to each of the other strings in the set using the permuted English alphabet. If X is strictly smaller than each of the other strings, the first player wins. Otherwise, the second player does.
//
// In order to compare two different strings A and B, first it is necessary to find the first position at which these strings differ. Let the characters at this position in A and B be a and b. If a stands earlier than b in the permuted alphabet, then A is lexicographically smaller than B, otherwise B is lexicographically smaller than A. For example, with alphabet {b, a, c, d, ..., z}, the string "aba" is lexicographically smaller than the string "aab" because 'b' stands earlier than 'a' in the alphabet.
//
// You are given a vector <string> S, the set of strings on which the String Game is played. Determine all strings which, when chosen by the first player, allow him to win if both he and his opponent play optimally. That is, the first player always permutes the string X and the alphabet optimally, and then the second player permutes all the other strings optimally. Return a vector <int> containing the sorted list of all 0-based indices of all such strings.
//
// DEFINITION
// Class:StringGame
// Method:getWinningStrings
// Parameters:vector <string>
// Returns:vector <int>
// Method signature:vector <int> getWinningStrings(vector <string> S)
//
//
// NOTES
// -The return value may sometimes be an empty vector <int>.
//
//
// CONSTRAINTS
// -S will contain between 2 and 50 elements, inclusive.
// -Each element of S will be between 1 and 50 characters long, inclusive.
// -All elements of S will be of equal length.
// -Each element of S will consist of lowercase letters ('a'-'z') only.
// -The elements of S will be distinct.
//
//
// EXAMPLES
//
// 0)
// {"a", "b", "c", "d"}
//
// Returns: {0, 1, 2, 3 }
//
// For each of the given strings, Manao can choose the alphabet which begins with the string's only character and his string will be lexicographically smallest.
//
// 1)
// {"aabbcc", "aaabbb", "aaaccc"}
//
// Returns: {1, 2 }
//
// Manao can win if he chooses the string "aaabbb" or "aaaccc". For "aaabbb", he can choose permutation of the alphabet {b, a, c, ..., z} and make his string "bbbaaa". For "aaaccc", the permutation can be {c, a, b, d, ..., z} and the string itself can be "cccaaa". In both cases, regardless of which permutations the opponent chooses, the two other strings will always be lexicographically larger than Manao's string.
//
// 2)
// {"ab", "ba"}
//
// Returns: { }
//
// Note that the first player's string should be strictly smaller than the opponent's strings.
//
// 3)
// {"xaocxsss", "oooxsoas", "xaooosss", "xaocssss", "coxaosxx"}
//
// Returns: {1, 3, 4 }
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
