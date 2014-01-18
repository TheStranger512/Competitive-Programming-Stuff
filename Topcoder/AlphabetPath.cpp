/*
 * SRM 523 Div2 Easy
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
template <class A> inline void pln(A a){cout << a << endl;}
template <class it> inline void plnarr(it begin, it end)
{cout<<'[';if(begin<end){while (true){cout<<(*begin);if(++begin==end)break;else cout<<',';}}cout<<']'<<endl;}
typedef long long llong;

class AlphabetPath {
public:
	string doesItExist(vector <string> letterMaze);
};

vector<string> maze;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
int rows, cols;

bool rec(char cur, int r, int c) {
	if (cur == 'Z') return true;
	for (int d = 0; d < 4; d++) {
		int nr = r + dy[d], nc = c + dx[d];
		if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) 
			continue;
		if (maze[nr][nc] == cur + 1 && rec(cur + 1, nr, nc))
			return true;
	}
	return false;
}


string AlphabetPath::doesItExist(vector <string> letterMaze) {
	maze = letterMaze;
	rows = maze.size();
	cols = maze.front().size();
	for (int r = 0; r < rows; r++)
		for (int c = 0; c < cols; c++)
			if (maze[r][c] == 'A' && rec('A', r, c))
				return "YES";
	return "NO";
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	AlphabetPath *obj;
	string answer;
	obj = new AlphabetPath();
	clock_t startTime = clock();
	answer = obj->doesItExist(p0);
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
	bool all_right;
	all_right = true;
	
	vector <string> p0;
	string p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "YES";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"ADEHI..Z","BCFGJK.Y",".PONML.X",".QRSTUVW"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "YES";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"ACBDEFGHIJKLMNOPQRSTUVWXYZ"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "NO";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"ABC.......","...DEFGHIJ","TSRQPONMLK","UVWXYZ...."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "NO";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"..............","..............","..............","...DEFGHIJK...","...C......L...","...B......M...","...A......N...","..........O...","..ZY..TSRQP...","...XWVU.......",".............."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "YES";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
// You are given a 2-dimensional matrix of characters represented by the vector <string> letterMaze. The i-th character of the j-th element of letterMaze  represents the character at row i and column j. Each of the 26 letters from 'A' to 'Z' appears exactly once in letterMaze, the remaining characters are periods ('.').
// 
// An alphabet path is a sequence of 26 elements of the matrix such that:
// 
// The first element contains the letter 'A'.
// The first element and the second element are (horizontally or vertically) adjacent.
// The second element contains the letter 'B'.
// The second element and the third element are (horizontally or vertically) adjacent.
// ...
// The 25-th element and the 26-th element are (horizontally or vertically) adjacent.
// The last, 26-th element contains the letter 'Z'.
// 
// Given letterMaze return string "YES" if the alphabet path exists in the matrix and "NO" otherwise.
// 
// DEFINITION
// Class:AlphabetPath
// Method:doesItExist
// Parameters:vector <string>
// Returns:string
// Method signature:string doesItExist(vector <string> letterMaze)
// 
// 
// NOTES
// -Formally, elements (x1,y1) and (x2,y2) are horizontally or vertically adjacent if and only if abs(x1 - x2) + abs(y1 - y2) = 1. 
// 
// 
// CONSTRAINTS
// -letterMaze will contain between 1 and 50 elements, inclusive.
// -Each element of letterMaze will contain between 1 and 50 characters, inclusive.
// -All the elements of letterMaze will contain the same number of characters.
// -Each element of letterMaze will only contain uppercase letters ('A'-'Z') and periods ('.').
// -Each uppercase letter from 'A' to 'Z' will appear exactly once in letterMaze.
// 
// 
// EXAMPLES
// 
// 0)
// {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}
// 
// Returns: "YES"
// 
// Simply go from left to right.
// 
// 1)
// {"ADEHI..Z",
//  "BCFGJK.Y",
//  ".PONML.X",
//  ".QRSTUVW"}
// 
// 
// Returns: "YES"
// 
// 
// 
// 2)
// {"ACBDEFGHIJKLMNOPQRSTUVWXYZ"}
// 
// Returns: "NO"
// 
// 
// 
// 3)
// {"ABC.......",
//  "...DEFGHIJ",
//  "TSRQPONMLK",
//  "UVWXYZ...."}
// 
// Returns: "NO"
// 
// The cells marked with C and D are not adjacent, it is impossible to make an alphabet path in this case.
// 
// 4)
// {"..............",
//  "..............",
//  "..............",
//  "...DEFGHIJK...",
//  "...C......L...",
//  "...B......M...",
//  "...A......N...",
//  "..........O...",
//  "..ZY..TSRQP...",
//  "...XWVU.......",
//  ".............."}
// 
// Returns: "YES"
// 
// 
// 
// END KAWIGIEDIT TESTING



//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
