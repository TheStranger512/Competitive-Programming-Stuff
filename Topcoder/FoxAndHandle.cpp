/*
 * Solved
 * SRM 563 Div1 Easy
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

struct FoxAndHandle {
  string lexSmallestName(string S);
} ;

string FoxAndHandle::lexSmallestName(string S) {
  int len = S.size();
  int needcnt[27] = {0}, have[27] = {0}, temp[27];
  for (int i = 0; i < len; i++)
    needcnt[S[i] - 'a']++;
  for (int i = 0; i < 26; i++)
    needcnt[i] >>= 1;
  memcpy(temp, needcnt, sizeof (temp));
  S += 'z' + 1;
  string ans = "";
  int prev = -1;
  for (int i = 0; i < len / 2; i++) {
    int cnt[27] = {0};
    int best = len;
    for (int j = prev + 1; j < len; j++) {
      if (S[j] < S[best] && have[S[j] - 'a'] < needcnt[S[j] - 'a'])
        best = j;
      if (++cnt[S[j] - 'a'] > temp[S[j] - 'a'])
        break;
    }
    for (int j = prev + 1; j < best; j++)
      temp[S[j] - 'a']--;
    have[S[best] - 'a']++;
    ans += S[best];
    prev = best;
  }
  return ans;
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof

bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
  cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
  cout << "]" << endl;
  FoxAndHandle *obj;
  string answer;
  obj = new FoxAndHandle();
  clock_t startTime = clock();
  answer = obj->lexSmallestName(p0);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << "\"" << p1 << "\"" << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << "\"" << answer << "\"" << endl;
  if (hasAnswer) {
    res = answer == p1;
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
  freopen("azn.txt", "w", stderr);
  #endif

  bool all_right;
  all_right = true;

  string p0;
  string p1;

  {
    // ----- test 0 -----
    p0 = "foxfox";
    p1 = "fox";
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    p0 = "ccieliel";
    p1 = "ceil";
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    p0 = "abaabbab";
    p1 = "aabb";
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    p0 = "bbbbaaaa";
    p1 = "bbaa";
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 4 -----
    p0 = "fedcbafedcba";
    p1 = "afedcb";
    all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 5 -----
    p0 = "nodevillivedon";
    p1 = "deilvon";
    all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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
// We say that a string Z can be obtained by shuffling two strings X and Y together, if it is possible to interleave the letters of X and Y so that Z is obtained. It is not allowed to change the order of letters in X and Y.
// For example, you can shuffle the strings X="abcd" and Y="efg" to produce any of the strings "abcdefg", "aebfcgd", "abcefgd", or "eabcfdg", but you cannot produce the string "bacdefg".
//
//
//
// Formally, let Shuffle(X,Y) be the set of all strings that can be produced by shuffling X and Y together.
// We can define Shuffle inductively as follows:
//
// for any string X: Shuffle("",X) = Shuffle(X,"") = { X }
// for any letters a, b and any strings X, Y:
// Shuffle(aX,bY) = { aZ : Z belongs to Shuffle(X,bY) } united with { bZ : Z belongs to Shuffle(aX,Y) }.
//
//
//
//
// Fox Ciel wants to register on TopCoder.
// In order to do that, she has to pick a handle.
// Ciel has a pet cat called S.
// As her handle, Ciel wants to use a string H with the following property:
// S can be obtained by shuffling H and some permutation of H together.
// For example, if S="ceiiclel", one possible handle would be H="ciel":
// she can permute H to obtain H'="eicl", and then shuffle these H and H' together to produce S.
//
//
//
// You are given the string S.
// The constraints guarantee that there is at least one possible handle H with the above property.
// Find and return the lexicographically smallest valid H.
//
// DEFINITION
// Class:FoxAndHandle
// Method:lexSmallestName
// Parameters:string
// Returns:string
// Method signature:string lexSmallestName(string S)
//
//
// CONSTRAINTS
// -S will contain between 2 and 50 characters, inclusive.
// -Each character of S will be a lowercase letter ('a'-'z').
// -Each letter ('a'-'z') will occur in S an even number of times.
//
//
// EXAMPLES
//
// 0)
// "foxfox"
//
// Returns: "fox"
//
// There are five possible handles for Fox Ciel in this test case: "fox", "fxo", "ofx", "oxf", and "xfo".
// The lexicographically smallest one is "fox".
//
// 1)
// "ccieliel"
//
// Returns: "ceil"
//
// Note that "ciel" is also a valid handle, but "ceil" is lexicographically smaller.
//
// 2)
// "abaabbab"
//
// Returns: "aabb"
//
//
//
// 3)
// "bbbbaaaa"
//
// Returns: "bbaa"
//
//
//
// 4)
// "fedcbafedcba"
//
// Returns: "afedcb"
//
//
//
// 5)
// "nodevillivedon"
//
// Returns: "deilvon"
//
//
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
