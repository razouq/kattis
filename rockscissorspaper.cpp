// Author: razouq
// Date: 2023-11-23 10:20
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

  map<char, char> killer;
  killer['R'] = 'P';
  killer['P'] = 'S';
  killer['S'] = 'R';

  int t;
  cin >> t;
  while (t--) {
    int n, m, d;
    cin >> n >> m >> d;

    vector<string> mat(n);
    for (int i = 0; i < n; i++) cin >> mat[i];
    while (d--) {
      vpii coors;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          bool change = false;
          if (0 <= i - 1 && mat[i - 1][j] == killer[mat[i][j]]) {
            change = true;
          }
          if (i + 1 < n && mat[i + 1][j] == killer[mat[i][j]]) {
            change = true;
          }
          if (0 <= j - 1 && mat[i][j - 1] == killer[mat[i][j]]) {
            change = true;
          }

          if (j + 1 < m && mat[i][j + 1] == killer[mat[i][j]]) {
            change = true;
          }

          if (change) {
            coors.PB({ i, j });
          }
        }
      }
        for (auto coor : coors) {
          mat[coor.F][coor.S] = killer[mat[coor.F][coor.S]];
        }
    }
    for (string line : mat) {
      cout << line << endl;
    }
    cout << endl;
  }
  return 0;
}