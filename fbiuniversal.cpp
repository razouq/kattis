// Author: razouq
// Date: 2023-12-07 16:18
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

  string nums = "0123456789ACDEFHJKLMNPRTVWX";
  map<char, int> numMap;
  for (int i = 0; i < nums.size(); i++) {
    numMap[nums[i]] = i;
  }

  map<char, char> mp;
  mp['B'] = '8';
  mp['G'] = 'C';
  mp['I'] = '1';
  mp['O'] = '0';
  mp['Q'] = '0';
  mp['S'] = '5';
  mp['U'] = 'V';
  mp['Y'] = 'V';
  mp['Z'] = '2';

  int t;
  cin >> t;
  while(t--) {
    int p;
    cin >> p;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
      if (mp[s[i]]) {
        s[i] = mp[s[i]];
      }
    }

    int ans = 0;
    vi v = { 2, 4, 5, 7, 8, 10, 11, 13 };
    for (int i = 0; i < 8; i++) {
      ans += numMap[s[i]] * v[i];
    }
    long long number = 0;
    long long k = powl(27, 7);
    for (int i = 0; i < 8; i++) {
      number += k * numMap[s[i]];
      k /= 27;
    }
    if (ans % 27 == numMap[s[8]]) {
      cout << p << " " << number << endl;
    }
    else cout <<p <<" Invalid"<< endl;
  }
  return 0;
}