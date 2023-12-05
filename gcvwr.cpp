// Author: razouq
// Date: 2023-12-05 06:44
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
  
  int g, t, n;
  cin >> g >> t >> n;

  int ans = (g - t) * 90 / 100;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ans -= x;
  }

  cout << ans << endl;
  return 0;
}