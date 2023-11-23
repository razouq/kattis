// Author: razouq
// Date: 2023-11-23 16:07
// #include<flamers.h>
#include "bits/stdc++.h"
#pragma GCC optimize("O3")

#define ll long long
#define ull unsigned long long
#define F first
#define S second
#define PB push_back
#define POB pop_back

const int INF = 1e9;
const ll LLINF = 4e18;
const int MOD = 1e9 + 7;

using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie();


  vector<string> board(8);
  for (string& line : board) cin >> line;

  string cmds;
  cin >> cmds;

  string directions = "RDLU";
  int direction = 0;
  int y = 7;
  int x = 0;
  bool bug = false;
  for (char cmd : cmds) {
    if (cmd == 'F') {
      int b = y;
      int a = x;
      if (directions[direction] == 'R') {
        a++;
      } else if (directions[direction] == 'D') {
        b++;
      } else if (directions[direction] == 'L') {
        a--;
      } else if (directions[direction] == 'U') {
        b--;
      }
      if (a < 0 || a > 7 || b < 0 || b > 7) {
        bug = true;
        break;
      }
      if (board[b][a] == 'C' || board[b][a] == 'I') {
        bug = true;
        break;
      }
      x = a;
      y = b;
    } else if (cmd == 'R') {
      direction++;
      direction %= 4;
    } else if (cmd == 'L') {
      direction--;
      direction += 4;
      direction %= 4;
    } else if (cmd == 'X') {
      int b = y;
      int a = x;
      if (directions[direction] == 'R') {
        a++;
      } else if (directions[direction] == 'D') {
        b++;
      } else if (directions[direction] == 'L') {
        a--;
      } else if (directions[direction] == 'U') {
        b--;
      }
      if (a < 0 || a > 7 || b < 0 || b > 7) {
        bug = true;
        break;
      }
      if (board[b][a] == 'I' || board[b][a] == '.') {
        board[b][a] = '.';
      } else {
        bug = true;
        break;
      }
    }
    if (bug) break;
  }

  if (bug || board[y][x] != 'D') cout << "Bug!" << endl;
  else cout << "Diamond!" << endl;
  return 0;
}