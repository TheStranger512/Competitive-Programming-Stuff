/* Solved
 * SRM 573 Div1 Medium
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
typedef long long llong;

struct SkiResorts {
  llong minCost(vector <string> road, vector <int> altitude);
} ;

#define SIZE(x) ((int)x.size())
typedef pair<int, int> Node;
vector<int> adj[55];
int alt[55], val[55];
bool vis[55];
int len, cnt;
llong dp[55][55]; //at, height

int get(int value) {
  return lower_bound(val, val + cnt, value) - val;
}

llong go(int st) {
  for (int i = 0; i < len; i++)
    val[i] = alt[i];
  val[len] = st;
  sort(val, val + len + 1);
  cnt = unique(val, val + len + 1) - val;
  memset(dp, 0x3F, sizeof (dp));
  dp[0][get(st)] = abs(alt[0] - st);
  queue<Node> q;
  q.push(Node(0, get(st)));
  for (int at, h; !q.empty(); q.pop()) {
    at = q.front().first;
    h = q.front().second;
    for (int i = 0; i < SIZE(adj[at]); i++) {
      int to = adj[at][i];
      for (int nh = h; nh >= 0; nh--) {
        if (dp[at][h] + abs(alt[to] - val[nh]) < dp[to][nh]) {
          dp[to][nh] = dp[at][h] + abs(alt[to] - val[nh]);
          q.push(Node(to, nh));
        }
      }
    }
  }
  return *min_element(dp[len - 1], dp[len - 1] + cnt);
}

llong SkiResorts::minCost(vector <string> road, vector <int> altitude) {
  for (int i = 0; i < 55; i++)
    adj[i].clear();
  len = altitude.size();
  for (int i = 0; i < len; i++) {
    alt[i] = altitude[i];
    for (int j = 0; j < len; j++)
      if (road[i][j] == 'Y')
        adj[i].push_back(j);
  }
  memset(vis, false, sizeof (vis));
  queue<int> q;
  q.push(0);
  vis[0] = true;
  for (; !q.empty(); q.pop()) {
    int at = q.front();
    for (int i = 0; i < SIZE(adj[at]); i++)
      if (!vis[adj[at][i]]) {
        vis[adj[at][i]] = true;
        q.push(adj[at][i]);
      }
  }
  if (!vis[len - 1]) return -1LL;
  llong best = 1LL << 60;
  for (int i = 0; i < len; i++)
    best = min(best, go(alt[i]));
  return best;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <int> p1, bool hasAnswer, llong p2) {
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
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	SkiResorts *obj;
	llong answer;
	obj = new SkiResorts();
	clock_t startTime = clock();
	answer = obj->minCost(p0, p1);
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
	vector <int> p1;
	llong p2;

	{
	// ----- test 0 -----
	string t0[] = {"NYN","YNY","NYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {30,20,10};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	string t0[] = {"NY","YN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {10,20};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 10ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	string t0[] = {"NYN","YNN","NNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {573,573,573};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -1ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	string t0[] = {"NNYNNYYYNN","NNNNYNYNNN","YNNNNYYNNN","NNNNNNYNYY","NYNNNNNNYY","YNYNNNNYNN","YYYYNNNYNN","YNNNNYYNNN","NNNYYNNNNN","NNNYYNNNNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {7,4,13,2,8,1,8,15,5,15};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 12ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	string t0[] = {"NNYNNYYYNN","NNNNYNYNNN","YNNNNYYNNN","NNNNNNYNYY","NYNNNNNNYY","YNYNNNNYNN","YYYYNNNYNN","YNNNNYYNNN","NNNYYNNNNN","NNNYYNNNNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {121,432,64536,143151,5251,54354,124,4133,1344,1555};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(4, p0, p1, false, p2) && all_right;
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
// Fox Ciel is the owner of a ski resort. The ski resort has N places numbered 0 through N-1. There are some bidirectional roads between pairs of places. You are given a vector <string> roads. If the j-th character of the i-th element of roads is 'Y', there is a bidirectional road that connects place i and place j. If it is 'N', there's no road between them. You are also given a vector <int> altitude. The i-th element of altitude is the altitude of the place i.
//
//
// You can go directly from the place i to the place j by skiing if there is a bidirectional road between them and the altitude of the place i is higher than or equal to the altitude of the place j. Ciel wants to reconstruct the ski resort so that place N-1 is reachable (not necessarily directly) from place 0 by skiing. In the reconstruction, Ciel can change the altitude of some places. The cost of changing the altitude of a place from x to y is |x - y| units of money, where || denotes the absolute value.
//
//
// Return the minimal cost required for the reconstruction. If it is impossible to reach place N-1 from place 0 even after the reconstruction, return -1.
//
// DEFINITION
// Class:SkiResorts
// Method:minCost
// Parameters:vector <string>, vector <int>
// Returns:long long
// Method signature:long long minCost(vector <string> road, vector <int> altitude)
//
//
// CONSTRAINTS
// -road will contain between 2 and 50 elements, inclusive.
// -Each element of road will contain exactly N characters, where N is the number of elements of road.
// -Each character in road will be either 'Y' or 'N'.
// -For each valid i, the i-th character of the i-th element of road will be 'N'.
// -For each valid pair (i, j), the i-th character of the j-th element of road and the j-th character of the i-th element of road will be equal.
// -altitude will contain exactly N elements.
// -Each element of altitude will be between 0 and 1,000,000,000, inclusive.
//
//
// EXAMPLES
//
// 0)
// {"NYN",
//  "YNY",
//  "NYN"}
// {30, 20, 10}
//
// Returns: 0
//
// It is possible to reach place 2 from place 0 even without the reconstruction by following the path (place 0) -> (place 1) -> (place 2).
//
// 1)
// {"NY",
//  "YN"}
// {10, 20}
//
// Returns: 10
//
// For example, Ciel can change the altitude of both places to 15. The cost is |10 - 15| + |20 - 15| = 10.
//
// 2)
// {"NYN",
//  "YNN",
//  "NNN"}
// {573, 573, 573}
//
// Returns: -1
//
// Place 2 is not reachable from place 0.
//
// 3)
// {"NNYNNYYYNN",
//  "NNNNYNYNNN",
//  "YNNNNYYNNN",
//  "NNNNNNYNYY",
//  "NYNNNNNNYY",
//  "YNYNNNNYNN",
//  "YYYYNNNYNN",
//  "YNNNNYYNNN",
//  "NNNYYNNNNN",
//  "NNNYYNNNNN"}
// {7, 4, 13, 2, 8, 1, 8, 15, 5, 15}
//
// Returns: 12
//
//
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
