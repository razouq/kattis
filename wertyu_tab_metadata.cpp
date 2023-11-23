// Author: razouq
// Date: 2023-11-23 16:33
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

  string str = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

  map<char, int> mp;
  for (int i = 0; i < str.size(); i++) {
    mp[str[i]] = i;
  }

  string s;
  while (getline(cin, s)) {
    for (char& c : s) {
      if (c == ' ') continue;
      c = str[mp[c] - 1];
    }
    cout << s << endl;
  }
  return 0;
}