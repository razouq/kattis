// Author: razouq
// Date: 2023-11-16 17:21
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
typedef set<int> si;

int main() {
  ios::sync_with_stdio(0);
  cin.tie();

  map<string, si> count;
  map<string, bool> ban;
  map<int, bool> touched;

  int n;
  cin >> n;
  int k;
  cin >> k;
  int notTouched = n;
  for (int i = 0; i < k; i++) {
    int c1, c2;
    cin >> c1 >> c2;

    string p1, p2;
    cin >> p1 >> p2;

    count[p1].insert(c1);
    count[p2].insert(c2);

    if (!touched[c1]) {
      touched[c1] = true;
      notTouched--;
    }

    if (!touched[c2]) {
      touched[c2] = true;
      notTouched--;
    }

    if (p1 == p2) ban[p1] = true;
  }
  int touchedOnce = 0;
  int ans = 0;
  for (auto it = count.begin(); it != count.end(); it++) {
    if (!ban[it->F] && it->S.size() == 2) ans++;
    if (!ban[it->F] && it->S.size() == 1) touchedOnce++;
  }

  if (touchedOnce == notTouched) ans += touchedOnce;
  else if (touchedOnce == 0 && notTouched == 2) ans++;

  cout << ans << endl;
  return 0;
}