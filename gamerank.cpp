// Author: razouq
// Date: 2023-11-23 06:26
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

int ranks(int level) {
  if (21 <= level && level <= 25) return 2;
  if (16 <= level && level <= 20) return 3;
  if (11 <= level && level <= 15) return 4;
  if (1 <= level && level <= 10) return 5;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  
  string s;
  cin >> s;
  int n = s.size();

  int stars = 0;
  int level = 25;
  bool isLegend = false;
  int consecutiveWins = 0;
  for (int i = 0; i < n; i++) {
    if (isLegend) continue;
    if (s[i] == 'W') {
      stars++;
      consecutiveWins++;
      if (6 <= level && level <= 25 && consecutiveWins >= 3) stars++;
      if (stars > ranks(level)) {
        stars -= ranks(level);
        level--;
        if (level == 0) isLegend = true;
      }
    } else {
      consecutiveWins = 0;
      if (level > 20) continue;
      stars--;
      if (stars < 0) {
        if (level == 20) stars = 0;
        else {
          level++;
          stars = ranks(level) - 1;
        }
      }
    }
  }
  if (isLegend) cout << "Legend" << endl;
  else cout << level << endl;
  return 0;
}