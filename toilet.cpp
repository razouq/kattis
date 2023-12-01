// Author: razouq
// Date: 2023-12-01 16:33
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
  int n = s.size();
  int ans;
  char currentPostition;

  // When you leave, always leave the seat up
  ans = 0;
  currentPostition = s[0];
  for (int i = 1; i < n; i++) {
    if (s[i] != currentPostition) {
      ans++;
      currentPostition = s[i];
    }
    if (currentPostition != 'U') {
      ans++;
      currentPostition = 'U';
    }
  }
  cout << ans << endl;

  // When you leave, always leave the seat down
  ans = 0;
  currentPostition = s[0];
  for (int i = 1; i < n; i++) {
    if (s[i] != currentPostition) {
      ans++;
      currentPostition = s[i];
    }
    if (currentPostition != 'D') {
      ans++;
      currentPostition = 'D';
    }
  }
  cout << ans << endl;

  // When you leave, always leave the seat as you would like to find it
  ans = 0;
  currentPostition = s[0];
  for (int i = 1; i < n; i++) {
    if (s[i] != currentPostition) {
      ans++;
      currentPostition = s[i];
    }
  }
  cout << ans << endl;

  return 0;
}