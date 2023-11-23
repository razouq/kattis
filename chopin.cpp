// Author: razouq
// Date: 2023-11-23 16:43
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

vector<string> split(string line) {
  vector<string> res;
  string s = "";
  for (char c : line) {
    if (c == ' ') {
      res.PB(s);
      s = "";
    } else {
      s += c;
    }
  }
  res.PB(s);
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie();

  map<string, string> mp;
  mp["A#"] = "Bb";
  mp["Bb"] = "A#";
  mp["C#"] = "Db";
  mp["Db"] = "C#";
  mp["D#"] = "Eb";
  mp["Eb"] = "D#";
  mp["F#"] = "Gb";
  mp["Gb"] = "F#";
  mp["G#"] = "Ab";
  mp["Ab"] = "G#";
  


  int t = 1;
  string line;
  while (getline(cin, line)) {
    vector<string> v = split(line);
    string note = v[0];
    string scale = v[1];
    if(mp[note].size()) cout << "Case " << t << ": " << mp[note] << " " << scale << endl;
    else cout << "Case " << t << ": UNIQUE" << endl;
    t++;
  }
  return 0;
}