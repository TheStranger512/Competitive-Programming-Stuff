/* Solved
 * SRM 589 Div1 Easy
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

using namespace std;

struct GooseTattarrattatDiv1 {
  int getmin(string S);
};

int GooseTattarrattatDiv1::getmin(string s) {
  bool vis[55], g[55][55];
  int cnt[255];
  int N = s.size();
  memset(g, false, sizeof(g));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (s[i] == s[j] || j == N - i - 1)
        g[i][j] = true;
  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        g[i][j] |= g[i][k] && g[k][j];
  memset(vis, false, sizeof(vis));
  int res = 0;
  for (int i = 0; i < N; i++) {
    if (vis[i])
      continue;
    memset(cnt, 0, sizeof(cnt));
    int sum = 0;
    for (int j = 0; j < N; j++)
      if (g[i][j]) {
        vis[j] = true;
        cnt[(int) s[j]]++;
        sum++;
      }
    res += sum - *max_element(cnt, cnt + 255);
  }
  return res;
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	GooseTattarrattatDiv1 *obj;
	int answer;
	obj = new GooseTattarrattatDiv1();
	clock_t startTime = clock();
	answer = obj->getmin(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
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
	int p1;
	
	{
	// ----- test 0 -----
	p0 = "geese";
	p1 = 2;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "tattarrattat";
	p1 = 0;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "xyyzzzxxx";
	p1 = 2;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag";
	p1 = 11;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "abaabb";
	p1 = 3;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "fhhsunkwilkrfozlfjkjjkgjzmjtwmhfunvprtrwzvirqzhepk";
	all_right = KawigiEdit_RunTest(5, p0, false, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// Goose Tattarrattat has a string S of lowercase letters.
// Tattarrattat wants to change her string into a palindrome: a string that reads the same forwards and backwards.
// (For example, "racecar" is a palindrome.)
// 
// She will do this in a series of steps.
// In each step, Tattarrattat will choose two letters of the alphabet: X and Y.
// She will then change each X in her string into a Y.
// Changing each single character takes 1 second.
// 
// For example, if S="goose" and Tattarrattat chooses X='o' and Y='e' in the next step, the step will take 2 seconds (because there are two 'o's in S) and after the step she would have S="geese".
// 
// You are given the string S.
// Return the smallest number of seconds in which Tattarrattat can change S into a palindrome.
// 
// DEFINITION
// Class:GooseTattarrattatDiv1
// Method:getmin
// Parameters:string
// Returns:int
// Method signature:int getmin(string S)
// 
// 
// NOTES
// -Tattarrattat must always change all occurrences of the chosen letter into the other one; she is not allowed to change only some of the occurrences.
// 
// 
// CONSTRAINTS
// -S will contain between 1 and 50 characters, inclusive.
// -Each character in S will be a lowercase letter ('a'-'z').
// 
// 
// EXAMPLES
// 
// 0)
// "geese"
// 
// Returns: 2
// 
// There are many ways how Tattarrattat can change this S into a palindrome.
// For example, she could do it in two steps as follows:
// 
// Change all 'g's to 'e's: this takes 1 second and produces the string "eeese".
// Change all 'e's to 's's: this takes 4 seconds and produces the string "sssss".
// 
// This way took her 1+4 = 5 seconds.
// However, there are faster ways.
// The best one only takes 2 seconds.
// For example, she can first change all 'g's to 'e's (1 second), and then change all 's's to 'e's (1 second), obtaining the palindrome "eeeee".
// 
// 1)
// "tattarrattat"
// 
// Returns: 0
// 
// This string is already a palindrome so no changes are needed.
// 
// 2)
// "xyyzzzxxx"
// 
// Returns: 2
// 
// 
// 
// 3)
// "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag"
// 
// Returns: 11
// 
// 
// 
// 4)
// "abaabb"
// 
// Returns: 3
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!