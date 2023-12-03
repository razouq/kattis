// Author: razouq
// Date: 2023-12-03 08:01
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

  map<char, pair<int, int>> pos;
  vector<string> keyboard = { "QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM" };

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < keyboard[i].size(); j++) {
      pos[tolower(keyboard[i][j])] = { i, j };
    }
  }

  int t;
  cin >> t;
  while (t--) {
    string s;
    int n;
    cin >> s >> n;
    vector<pair<int, string>> v;
    for (int i = 0; i < n; i++) {
      string str;
      cin >> str;
      int sum = 0;
      for (int j = 0; j < s.size(); j++) {
        sum += abs(pos[s[j]].F - pos[str[j]].F) + abs(pos[s[j]].S - pos[str[j]].S);
      }
      v.PB({ sum, str });
    }
    sort(v.begin(), v.end());
    for (auto item : v) {
      cout << item.S << " " << item.F << endl;
    }
  }
  return 0;
}