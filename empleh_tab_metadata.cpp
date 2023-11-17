// Author: razouq
// Date: 2023-11-17 10:58
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

vector<string> split(string str) {
  vector<string> ans;
  string s = "";
  for (int i = 7; i < str.size(); i++) {
    if (str[i] == ',') {
      ans.PB(s);
      s = "";
      continue;
    }
    s += str[i];
  }
  if(s != "") ans.PB(s);
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie();

  string w, b;
  getline(cin, w);
  getline(cin, b);
  
  vector<string> white = split(w);
  vector<string> black = split(b);

  vector<vector<char>> mat(8, vector<char>(8, '?'));

  // white
  for (auto item : white) {
    if (item.size() == 3) {
      char v = item[0];
      int x = item[1] - 'a';
      int y = item[2] - '0' - 1;

      mat[y][x] = v;
    } else {
      char v = 'P';
      int x = item[0] - 'a';
      int y = item[1] - '0' - 1;

      mat[y][x] = v;
    }
  }

  // black
  for (auto item : black) {
    if (item.size() == 3) {
      char v = item[0];
      int x = item[1] - 'a';
      int y = item[2] - '0' - 1;
      v = tolower(v);
      mat[y][x] = v;
    } else {
      char v = 'P';
      int x = item[0] - 'a';
      int y = item[1] - '0' - 1;
      v = tolower(v);
      mat[y][x] = v;
    }
  }
  cout << "+---+---+---+---+---+---+---+---+" << endl;
  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j < 8; j++) {
      char v = mat[i][j];
      if (v == '?') {
        if ((i + j) % 2 == 0) v = ':';
        else v = '.';
      }
      cout << "|" << ((i + j) % 2 == 0 ? ':' : '.') << v << ((i + j) % 2 == 0 ? ':' : '.');
    }
    cout << "|";
    cout << endl;
    cout << "+---+---+---+---+---+---+---+---+" << endl;
  }



  return 0;
}