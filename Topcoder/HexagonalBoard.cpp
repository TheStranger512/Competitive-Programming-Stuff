/* Solved
 * SRM 593 Div1 Easy
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

struct HexagonalBoard {
  int minColors(vector<string> board);
};

const int dx[] = { 0, 1, -1, 0, -1, 1 };
const int dy[] = { 1, 0, 0, -1, 1, -1 };
int id[55][55];
vector<int> adj[2555];
int col[2555];
bool bad;

void rec(int at) {
  for (int i = 0; i < (int) adj[at].size(); i++) {
    int to = adj[at][i];
    if (col[to] == col[at]) {
      bad = true;
      return;
    }
    if (col[to] == -1) {
      col[to] = col[at] ^ 1;
      rec(to);
    }
  }
}

int HexagonalBoard::minColors(vector<string> board) {
  for (int i = 0; i < 2555; i++)
    adj[i].clear();
  memset(id, -1, sizeof(id));
  int V = 0;
  const int R = board.size(), C = board[0].size();
  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++)
      if (board[r][c] == 'X')
        id[r][c] = V++;
  bool edges = 0;
  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++) {
      if (id[r][c] == -1)
        continue;
      for (int d = 0; d < 6; d++) {
        int nr = r + dx[d], nc = c + dy[d];
        if (nr >= 0 && nr < R && nc >= 0 && nc < C && id[nr][nc] != -1) {
          edges = true;
          adj[id[r][c]].push_back(id[nr][nc]);
        }
      }
    }
  if (V == 0)
    return 0;
  if (!edges)
    return 1;
  //plnarr(adj, adj + V);
  memset(col, -1, sizeof(col));
  bad = false;
  for (int v = 0; v < V; v++)
    if (col[v] == -1) {
      col[v] = 0;
      rec(v);
    }
  //plnarr(col, col + V);
  if (!bad)
    return 2;
  return 3;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector<string> p0, bool hasAnswer, int p1) {
  cout << "Test " << testNum << ": [" << "{";
  for (int i = 0; int(p0.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << "\"" << p0[i] << "\"";
  }
  cout << "}";
  cout << "]" << endl;
  HexagonalBoard *obj;
  int answer;
  obj = new HexagonalBoard();
  clock_t startTime = clock();
  answer = obj->minColors(p0);
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

  vector<string> p0;
  int p1;

  {
    // ----- test 0 -----
    string t0[] = { "---", "---", "---" };
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 0;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    string t0[] = { "-X--", "---X", "----", "-X--" };
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 1;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    string t0[] = { "XXXX", "---X", "---X", "---X" };
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 2;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    string t0[] = { "XX-XX--", "-XX-XXX", "X-XX--X", "X--X-X-", "XX-X-XX", "-X-XX-X", "-XX-XX-" };
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 3;
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
// The pony Applejack has an N by N hexagonal board. The following picture shows the hexagonal board when N = 1, 2, 3, and 4.
// 
// 
// 
// 
// 
// She wants to color some cells of the board. You are given a vector <string> board. If the j-th character of the i-th element of board is 'X', she wants to color the cell (i, j). If she colors two cells that share an edge, she must use different colors for those cells. Return the minimal number of colors she needs.
// 
// DEFINITION
// Class:HexagonalBoard
// Method:minColors
// Parameters:vector <string>
// Returns:int
// Method signature:int minColors(vector <string> board)
// 
// 
// CONSTRAINTS
// -board will contain between 1 and 50 elements, inclusive.
// -Each element of board will contain exactly N characters, where N is the number of elements in board.
// -Each character in board will be either 'X' or '-'.
// 
// 
// EXAMPLES
// 
// 0)
// {"---",
//  "---",
//  "---"}
//  
// 
// Returns: 0
// 
// She won't color any cells, so she won't need any colors.
// 
// 1)
// {"-X--",
//  "---X",
//  "----",
//  "-X--"}
// 
// Returns: 1
// 
// She can color all cells with the same color.
// 
// 2)
// {"XXXX",
//  "---X",
//  "---X",
//  "---X"}
// 
// Returns: 2
// 
// For example, she can color cells in the following way:
// 
// Color cells (0, 0), (0, 2), (1, 3), and (3, 3) red.
// Color cells (0, 1), (0, 3), and (2, 3) blue.
// 
// 
// 
// 3)
// {"XX-XX--"
// ,"-XX-XXX"
// ,"X-XX--X"
// ,"X--X-X-"
// ,"XX-X-XX"
// ,"-X-XX-X"
// ,"-XX-XX-"}
// 
// Returns: 3
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!