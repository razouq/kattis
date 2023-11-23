// Author: razouq
// Date: 2023-11-23 09:30
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

vector<char> cases;

void solve(vector<string>& mat) {
  // find '0'
  int x = -1;
  int y = -1;
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[i].size(); j++) {
      if (mat[i][j] == '0') {
        x = i;
        y = j;
      }
    }
  }

  // '0' not found!
  if (x == -1 && y == -1) return;

  for (char c : cases) {
    int a = -1;
    int b = -1;
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[i].size(); j++) {
        if (mat[i][j] == c) {
          a = i;
          b = j;
        }
      }
    }

    // next char not found!
    if (a == -1 && b == -1) return;


    if (x == a) {
      // work on '-'
      for (int j = min(y, b); j <= max(y, b); j++) {
        if (mat[x][j] == '.') {
          mat[x][j] = '-';
        }
        if (mat[x][j] == '|') {
          mat[x][j] = '+';
        }
      }
    } else if (y == b) {
      // work on '|'
      for (int i = min(x, a); i <= max(x, a); i++) {
        if (mat[i][y] == '.') {
          mat[i][y] = '|';
        }
        if (mat[i][y] == '-') {
          mat[i][y] = '+';
        }
      }
    }

    x = a;
    y = b;
  }
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie();

  for (char c = '1'; c <= '9'; c++) cases.PB(c);
  for (char c = 'a'; c <= 'z'; c++) cases.PB(c);
  for (char c = 'A'; c <= 'Z'; c++) cases.PB(c);

  string s;
  vector<string> mat;
  while (getline(cin, s)) {
    if (s != "") mat.PB(s);
    else {
      solve(mat);
      for (string line : mat) {
        for (char c : line) cout << c;
        cout << endl;
      }
      cout << endl;
      mat.clear();
    }
  }
  solve(mat);
  for (string line : mat) {
    for (char c : line) cout << c;
    cout << endl;
  }
  return 0;
}