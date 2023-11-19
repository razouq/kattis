// Author: razouq
// Date: 2023-11-19 07:09
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

  int mn = 0;
  int mx = 11;

  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    cin.ignore();

    string s;
    getline(cin, s);
    if (s == "too high") mx = min(mx, n);
    if (s == "too low") mn = max(mn, n);
    if (s == "right on") {
      if (mn < n && n < mx) cout << "Stan may be honest" << endl;
      else cout << "Stan is dishonest" << endl;
      mn = 0;
      mx = 11;
    }
  }
  return 0;
}