// Author: razouq
// Date: 2023-11-23 10:59
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

  int t;
  cin >> t;
  while (t--) {
    vector<string> mat(3);
    for (int i = 0; i < 3; i++) cin >> mat[i];

    int x = 0;
    int o = 0;

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (mat[i][j] == 'X') x++;
        if (mat[i][j] == 'O') o++;
      }
    }

    int winsXh = 0;
    int winsOh = 0;
    int winsXv = 0;
    int winsOv = 0;
    int winsXd = 0;
    int winsOd = 0;

    for (int i = 0; i < 3; i++) {
      if (mat[i] == "XXX") winsXh++;
      if (mat[i] == "OOO") winsOh++;
    }

    for (int j = 0; j < 3; j++) {
      string s = "";
      for (int i = 0; i < 3; i++) {
        s += mat[i][j];
      }
      if (s == "XXX") winsXv++;
      if (s == "OOO") winsOv++;
    }

    string s1 = "";
    s1 += mat[0][0];
    s1 += mat[1][1];
    s1 += mat[2][2];
    if (s1 == "XXX") winsXd++;
    if (s1 == "OOO") winsOd++;

    string s2 = "";
    s2 += mat[0][2];
    s2 += mat[1][1];
    s2 += mat[2][0];
    if (s2 == "XXX") winsXd++;
    if (s2 == "OOO") winsOd++;

    int winsX = winsXh + winsXv + winsXd;
    int winsO = winsOh + winsOv + winsOd;

    bool valid = true;

    if (o > x) valid = false;
    if (o + 1 < x) valid = false;

    if (winsXh > 1) valid = false;
    if (winsXv > 1) valid = false;

    if (winsOh > 1) valid = false;
    if (winsOv > 1) valid = false;

    if (winsX > 0 && winsO > 0) valid = false;
    if (winsX > 0 && x == o) valid = false;
    if (winsO > 0 && x > o) valid = false;

    if (valid) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}