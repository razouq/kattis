// Author: razouq
// Date: 2023-12-01 16:28
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
  while(t--) {
    int sum, diff;
    cin >> sum >> diff;
    if (sum % 2 != diff % 2 || sum < diff) cout << "impossible" << endl;
    else cout << diff + (sum - diff) / 2 << " " << (sum - diff) / 2 << endl;
  }
  return 0;
}