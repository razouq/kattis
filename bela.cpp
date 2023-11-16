// Author: razouq
// Date: 2023-11-16 14:55
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

int main()
{
  ios::sync_with_stdio(0);
  cin.tie();

  map<char, pii> scoreMap;
  scoreMap['A'] = { 11, 11 };
  scoreMap['K'] = { 4, 4 };
  scoreMap['Q'] = { 3, 3 };
  scoreMap['J'] = { 20, 2 };
  scoreMap['T'] = { 10, 10 };
  scoreMap['9'] = { 14, 0 };
  scoreMap['8'] = { 0, 0 };
  scoreMap['7'] = { 0, 0 };

  int n;
  cin >> n;
  char b;
  cin >> b;
  int ans = 0;
  while (n--) {
    int cards = 4;
    while (cards--) {
      string s;
      cin >> s;
      ans += s[1] == b ? scoreMap[s[0]].F : scoreMap[s[0]].S;
    }
  }
  cout << ans << endl;
  return 0;
}