/* Solved
 * TCO 2012 Round 2A Easy
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

struct SwitchesAndLamps {
  int theMin(vector <string> switches, vector <string> lamps);
} ;

int N;
string a[55], b[55];//swiches, lamps

int SwitchesAndLamps::theMin(vector <string> switches, vector <string> lamps) {
  N = switches[0].size();
  int E = switches.size();
  for (int j = 0; j < N; j++) {
    a[j] = b[j] = "";
    for (int i = 0; i < E; i++) {
      a[j] += switches[i][j];
      b[j] += lamps[i][j];
    }
  }
  sort(a, a + N);
  sort(b, b + N);
  if (!equal(a, a + N, b))
    return -1;
  int res = 0;
  for (int i = 0; i < N; i++) {
    int cnt = count(a, a + N, a[i]);
    int pw = 0;
    while (cnt > 1) {
      pw++;
      cnt = (cnt + 1) >> 1;
    }
    res = max(res, pw);
  }
  return res;
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	SwitchesAndLamps *obj;
	int answer;
	obj = new SwitchesAndLamps();
	clock_t startTime = clock();
	answer = obj->theMin(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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

	vector <string> p0;
	vector <string> p1;
	int p2;

	{
	// ----- test 0 -----
	string t0[] = {"NYNN","NNYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"NNNY","NNYN"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	string t0[] = {"YYN","YNY","YYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"YNY","NYY","YNY"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	string t0[] = {"NYYYNYNNYYYNYNNNNY","NYYYNYNNYYYNYNNNNY"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"YYYNNNYNNYNYNYNYNY","YYYNNNYNNYNYYNNYNY"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -1;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	string t0[] = {"YYNNN","NNYYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"NYNNY","NNNYY"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -1;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	string t0[] = {"YNNYNNYNYY","NYNNYNYNYN","YNYNYYYYYN","NNYYNYNYNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"NYYNYNNYNY","NYYYNNYNNN","YYYYNYNNYY","YNNNNYNYYN"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	string t0[] = {"NNNN","NNNN","NNNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"NNNN","NNNN","NNNN"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(5, p0, p1, false, p2) && all_right;
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
// There are N switches and N lamps in Cucumberman's house. Each switch is connected to a single lamp. Different switches are connected to different lamps. Switches are numbered 0 through N-1. Lamps are also numbered 0 through N-1, but not necessarily in the same order as their corresponding switches. Switches and lamps have two states: ON and OFF. When a switch is in the ON state, the lamp connected to the switch is ON. When a switch is in the OFF state, the lamp connected to the switch is OFF.
//
//
// Cucumberman decided to perform some experiments in order to figure out the connection between switches and lamps. In each experiment he first sets the states of all switches as he wants to, and then he writes down the states of all lamps.
//
//
// He has already performed some experiments. You are given the results in two vector <string>s switches and lamps. If the j-th character of the i-th element of switches is 'Y', the j-th switch was ON in the i-th experiment. If the j-th character of the i-th element of switches is 'N', the j-th switch was OFF in the i-th experiment. lamps gives the information of lamps in the same format.
//
//
// If the results of experiments are inconsistent, return -1. (I.e., return -1 if no way of assigning switches to lamps matches all the experiments.) Otherwise, return the minimal number of additional experiments required to figure out the connection between switches and lamps. In other words, return the smallest nonnegative integer X with the following property: It is possible to design X additional experiments in such a way that after Cucumberman executes them and tells you the results you will surely be able to match each switch to its corresponding lamp.
//
//
// DEFINITION
// Class:SwitchesAndLamps
// Method:theMin
// Parameters:vector <string>, vector <string>
// Returns:int
// Method signature:int theMin(vector <string> switches, vector <string> lamps)
//
//
// CONSTRAINTS
// -switches will contain between 1 and 50 elements, inclusive.
// -Each element of switches will contain between 1 and 50 characters, inclusive.
// -Each element of switches will contain the same number of characters.
// -lamps will contain the same number of elements as switches.
// -Each element of lamps will contain the same number of characters, and it will be equal to the number of characters of elements in switches.
// -Each character in switches and lamps will be 'Y' or 'N'.
// -For each i, the number of 'Y' in switches[i] and the number of 'Y' in lamps[i] will be equal.
//
//
// EXAMPLES
//
// 0)
// {"NYNN", "NNYN"}
// {"NNNY", "NNYN"}
//
// Returns: 1
//
// He can figure out that switch 1 is connected to lamp 3 and switch 2 is connected to lamp 2. He needs one more experiment to figure out which of the switches 0 and 3 is connected to lamp 0.
//
// 1)
// {"YYN", "YNY", "YYN"}
// {"YNY", "NYY", "YNY"}
//
// Returns: 0
//
// He can figure out that switch 0 is connected to lamp 2, switch 1 is connected to lamp 0, and switch 2 is connected to lamp 1. No additional experiments are necessary.
//
//
// 2)
// {"NYYYNYNNYYYNYNNNNY", "NYYYNYNNYYYNYNNNNY"}
// {"YYYNNNYNNYNYNYNYNY", "YYYNNNYNNYNYYNNYNY"}
//
// Returns: -1
//
// The same experiment cannot give different results when executed twice.
//
// 3)
// {"YYNNN", "NNYYN"}
// {"NYNNY", "NNNYY"}
//
// Returns: -1
//
//
//
// 4)
// {"YNNYNNYNYY", "NYNNYNYNYN", "YNYNYYYYYN", "NNYYNYNYNN"}
// {"NYYNYNNYNY", "NYYYNNYNNN", "YYYYNYNNYY", "YNNNNYNYYN"}
//
// Returns: 2
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!