// Author: razouq
// Date: 2023-10-14 16:51
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

bool isLowerCase(char c) {
  return 'a' <= c && c <= 'z';
}

bool isUpperCase(char c) {
  return 'A' <= c && c <= 'Z';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie();

  int n = 17;
  vector<string> lines;
  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;
    if (i % 2 == 1) lines.PB(line);
  }

  reverse(lines.begin(), lines.end());

  string white = "White: ";
  string black = "Black: ";
  vector<char> pieces = { 'K', 'Q', 'R', 'B', 'N', 'P' };

  for (char piece : pieces) {
    for (int i = 7; i >= 0; i--) {
      for (int j = 0; j < lines[0].size(); j++) {
        if (j > 1 && (j - 2) % 4 == 0 && toupper(lines[i][j]) == piece) {
          if (isLowerCase(lines[i][j])) {
            if (toupper(lines[i][j]) != 'P')
              black += toupper(lines[i][j]);
            black += 'a' + (j - 2) / 4;
            black += '0' + (i + 1);
            black += ',';
          }
        }
      }
    }
  }

  for (char piece : pieces) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < lines[0].size(); j++) {
        if (j > 1 && (j - 2) % 4 == 0 && toupper(lines[i][j]) == piece) {
          if (isUpperCase(lines[i][j])) {
            if (toupper(lines[i][j]) != 'P')
              white += toupper(lines[i][j]);
            white += 'a' + (j - 2) / 4;
            white += '0' + (i + 1);
            white += ',';
          }
        }
      }
    }
  }
  if (white[white.size() - 1] == ',') white.pop_back();
  if (black[black.size() - 1] == ',') black.pop_back();
  cout << white << endl;
  cout << black << endl;
  return 0;
}