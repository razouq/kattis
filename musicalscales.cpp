// Author: razouq
// Date: 2023-12-01 16:52
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

  vi major = { 2, 2, 1, 2, 2, 2, 1};
  vector<string> notes = { "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };
  map<string, int> mp;
  for (int i = 0; i < 12; i++) {
    mp[notes[i]] = i;
  }
  int n;
  cin >> n;
  set<string> st;
  string x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    st.insert(x);
  }
  vector<string> ans;
  for (int i = 0; i < 12; i++) {
    map<string, bool> exists;
    for (int j = i, k = 0; j < i + 12; j += major[k++]) {
      exists[notes[j]] = true;
    }
    bool valid = true;
    for (auto it = st.begin(); it != st.end(); it++) {
      if (!exists[*it]) valid = false;
    }
    if (valid) ans.PB(notes[i]);
  }

  if (ans.size()) {
    for (auto item : ans) cout << item << " ";
    cout << endl;
  } else cout << "none" << endl;
  return 0;
}