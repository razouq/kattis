// Author: razouq
// Date: 2023-12-05 09:43
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

vi stringToVI(string s) {
  vi v;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '-') {
      v.PB(s[i] - '0');
    }
  }
  return v;
}

int prod(vi a, vi b) {
  int ans = 0;
  for (int i = 0; i < a.size(); i++) {
    ans += a[i] * b[i];
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie();

  string s;
  cin >> s;
  vi v = stringToVI(s);
  vi a = { 4, 3, 2, 7, 6, 5, 4, 3, 2, 1 };
  int ans = prod(a, v) % 11 == 0 ? 1 : 0;
  cout << ans << endl;
  return 0;
}