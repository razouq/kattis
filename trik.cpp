// Author: razouq
// Date: 2023-11-18 21:21
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
  
  string s;
  cin >> s;

  vi v = { 1, 0, 0 };

  for (char c : s) {
    if (c == 'A') {
      swap(v[0], v[1]);
    } else if (c == 'B') {
      swap(v[1], v[2]);
    } else {
      swap(v[0], v[2]);
    }
  }

  for (int i = 0;i < 3; i++) {
    if (v[i] == 1) cout << i + 1 << endl;
  }

  return 0;
}