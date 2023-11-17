// Author: razouq
// Date: 2023-11-17 06:03
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

  map<char, int> countSuits;
  map<string, bool> countCards;
  bool greska = false;

  for (int i = 0; i < s.size(); i += 3) {
    string str = "";
    str += s[i];
    str += s[i + 1];
    str += s[i + 2];
    if (countCards[str]) {
      greska = true;
    }
    countSuits[s[i]]++;
    countCards[str] = true;
  }
  if (greska) cout << "GRESKA" << endl;
  else cout << 13 - countSuits['P'] << " " << 13 - countSuits['K'] << " " << 13 - countSuits['H'] << " " << 13 - countSuits['T'] << endl;
  return 0;
}