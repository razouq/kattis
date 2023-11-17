// Author: razouq
// Date: 2023-11-17 10:13
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

void color(vector<vector<int>>& mat, int x, int y) {
  mat[x][y]++;
  int a, b;
  // up right
  a = x + 1; b = y + 1;
  while (a < 8 && b < 8) {
    mat[a][b]++;
    a++; b++;
  }

  // up left
  a = x - 1; b = y + 1;
  while (a >= 0 && b < 8) {
    mat[a][b]++;
    a--; b++;
  }

  // bottom right
  a = x + 1; b = y - 1;
  while (a < 8 && b >= 0) {
    mat[a][b]++;
    a++; b--;
  }

  // bottom left
  a = x - 1; b = y - 1;
  while (a >= 0 && b >= 0) {
    mat[a][b]++;
    a--; b--;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie();

  int t;
  cin >> t;
  while (t--) {
    char c1, c2;
    int x1, x2, y1, y2;
    cin >> c1 >> y1;
    cin >> c2 >> y2;
    x1 = c1 - 'A' + 1;
    x2 = c2 - 'A' + 1;

    if ((x1 + y1) % 2 != (x2 + y2) % 2) {
      cout << "Impossible" << endl;
      continue;
    }

    if (x1 == x2 && y1 == y2) {
      cout << "0 " << c1 << " " << y1 << endl;
      continue;
    }

    if (abs(x1 - x2) == abs(y1 - y2)) {
      cout << "1 " << c1 << " " << y1 << " " << c2 << " " << y2 << endl;
      continue;
    }

    x1--; x2--; y1--; y2--;

    vector<vector<int>> mat(8, vector<int>(8, 0));
    color(mat, x1, y1);
    color(mat, x2, y2);

    int x, y;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (mat[i][j] >= 2) {
          x = i + 1;
          y = j + 1;
        }
      }
    }

    x1++; x2++; y1++; y2++;


    cout << "2 " << c1 << " " << y1 << " " << (char)('A' + x - 1) << " " << y << " " << c2 << " " << y2 << endl;
  }
  return 0;
}