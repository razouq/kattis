// Author: razouq
// Date: 2023-12-08 19:15
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
  
  int n, t;
  cin >> n >> t;
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (t == 1) {
    bool found = false;
    for (int i = 0; i < n; i++) {
      int value = 7777 - a[i];
      auto it = lower_bound(a.begin(), a.end(), value);
      if (it != a.end() && *it == value) {
        found = true;
        break;
      }
    }
    if (found) cout << "Yes" << endl;
    else cout << "No" << endl;
  } else if (t == 2) {
    bool unique = true;
    map<int, bool> mp;
    for (int i = 0; i < n; i++) {
      if (mp[a[i]]) unique = false;
      mp[a[i]] = true;
    }
    if (unique) cout << "Unique" << endl;
    else cout << "Contains Duplicate" << endl;
  } else if (t == 3) {
    map<int, int> mp;
    int ans = -1;
    for (int i = 0; i < n; i++) {
      mp[a[i]]++;
      if (mp[a[i]] > n / 2) {
        ans = a[i];
      }
    }
    cout << ans << endl;
  } else if (t == 4) {
    if (n % 2 == 1) {
      cout << a[n / 2] << endl;
    } else {
      cout << a[n / 2 - 1] << " " << a[n / 2] << endl;
    }
  } else if (t == 5) {
    for (int i = 0; i < n; i++) {
      if (100 <= a[i] && a[i] <= 999) cout << a[i] << " ";
    }
  }
  return 0;
}