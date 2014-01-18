/*
 * SRM 588 Div2 Easy
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
#include <array>

using namespace std;

struct KeyDungeonDiv2 {
	int countDoors(vector <int> doorR, vector <int> doorG, vector <int> keys);
};

int KeyDungeonDiv2::countDoors(vector <int> doorR, vector <int> doorG, vector <int> keys) {
	int res = 0;
	for (int i = 0; i < doorR.size(); i++) {
		int r = keys[0] - doorR[i];
		int g = keys[1] - doorG[i];
		if (keys[2] >= max(0, -r) + max(0, -g))
			res++;
	}
	return res;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	KeyDungeonDiv2 *obj;
	int answer;
	obj = new KeyDungeonDiv2();
	clock_t startTime = clock();
	answer = obj->countDoors(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	
	vector <int> p0;
	vector <int> p1;
	vector <int> p2;
	int p3;
	
	{
	// ----- test 0 -----
	int t0[] = {2,0,5,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,4,0,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,3,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {0,1,2,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,2,3,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,0,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {3,5,4,2,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {4,2,3,8,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,0,10};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 5;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {4,5,4,6,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,1,2,3,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,2,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 0;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {41,44,41,57,58,74,84,100,58,2,43,32,82,97,44,13,35,98,96,81,43,77,18,51,27,27,39,39,45,82,59,20,28,93,6,39,64,78,28,85,17,56,3,68,4,0,36,80,41,77};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {67,15,53,36,88,29,26,57,68,99,97,27,51,70,3,49,65,75,35,92,66,0,23,96,38,86,98,31,26,75,30,2,92,78,100,99,38,26,85,74,77,15,16,48,100,88,55,93,99,54};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {39,31,34};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 17;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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
// You are exploring a dungeon.
// In the dungeon you found some locked doors.
// Each locked door has some red and some green keyholes (zero or more of each kind).
// In order to open a door, you must insert fitting keys into all its keyholes simultaneously.
// Once you open a door, you may take all the keys back and possibly reuse some of them later to open other doors. 
// 
// There are three kinds of keys: red, green, and white ones.
// Each red key fits into any red keyhole.
// Each green key fits into any green keyhole.
// Each white key fits into any keyhole (both red and green ones). 
// 
// You are given vector <int>s doorR and doorG.
// These two vector <int>s have the same length.
// For each valid i, the values doorR[i] and doorG[i] describe one of the doors you found:
// a door with doorR[i] red and doorG[i] green keyholes. 
// 
// You are also given the vector <int> keys with three elements:
// keys[0] is the number of red keys, keys[1] the number of green keys, and keys[2] the number of white keys you have at the beginning. 
// 
// Return the number of doors you can open with keys you have.
// 
// DEFINITION
// Class:KeyDungeonDiv2
// Method:countDoors
// Parameters:vector <int>, vector <int>, vector <int>
// Returns:int
// Method signature:int countDoors(vector <int> doorR, vector <int> doorG, vector <int> keys)
// 
// 
// CONSTRAINTS
// -doorR and doorG will each contain between 1 and 50 elements, inclusive.
// -doorR and doorG will contain the same number of elements.
// -Each element of doorR and doorG will be between 0 and 100, inclusive.
// -keys will contain exactly 3 elements.
// -Each element of keys will be between 0 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {2, 0, 5, 3}
// {1, 4, 0, 2}
// {2, 3, 1}
// 
// Returns: 3
// 
// There are 4 doors. You have 2 red keys, 3 green keys, 1 white key.
// You can open 3 of the doors:
// 
// You can open door 0, using 2 red keys and 1 green key.
// You can open door 1, using 3 green keys and 1 white key. Here you insert the white key into one of the green keyholes.
// You can't open door 2, for you have only 3 keys that can be inserted into red key holes.
// You can open door 3, using 2 red keys, 2 green keys, and 1 white key. Here you insert the white key into one of the red keyholes.
// 
// 
// 1)
// {0, 1, 2, 0}
// {0, 2, 3, 1}
// {0, 0, 0}
// 
// Returns: 1
// 
// You have no key at all, but door 0 also has no keyhole. Therefore, you can open door 0.
// 
// 
// 2)
// {3, 5, 4, 2, 8}
// {4, 2, 3, 8, 1}
// {0, 0, 10}
// 
// Returns: 5
// 
// 
// 
// 3)
// {4, 5, 4, 6, 8}
// {2, 1, 2, 3, 5}
// {1, 2, 1}
// 
// Returns: 0
// 
// 
// 
// 4)
// {41,44,41,57,58,74,84,100,58,2,43,32,82,97,44,13,35,98,96,81,43,77,18,51,27,
//  27,39,39,45,82,59,20,28,93,6,39,64,78,28,85,17,56,3,68,4,0,36,80,41,77}
// {67,15,53,36,88,29,26,57,68,99,97,27,51,70,3,49,65,75,35,92,66,0,23,96,38,86,
//  98,31,26,75,30,2,92,78,100,99,38,26,85,74,77,15,16,48,100,88,55,93,99,54}
// {39,31,34}
// 
// Returns: 17
// 
// 
// 
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
