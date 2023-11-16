// Author: razouq
// Date: 2023-11-16 15:41
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

bool isGood(vi v, int n) {
  for (int i = 0; i < n; i++) {
    if (v[i] != i + 1) {
      return false;
    }
  }
  return true;
}

vi shuffle(vi v, int n, string s) {
  int a = 0;
  int b;
  if (n % 2 == 0) b = n / 2;
  else {
    if (s == "out") b = n / 2 + 1;
    else b = n / 2;
  }
  char startWith = s == "out" ? 'a' : 'b';
  vi res;
  while (res.size() < n) {
    if (startWith == 'a') {
      res.PB(v[a++]);
    } else {
      res.PB(v[b++]);
    }
    startWith = startWith == 'a' ? 'b' : 'a';
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  
  int n;
  string s;
  cin >> n >> s;

  vi v(n);
  for (int i = 0; i < n; i++) v[i] = i + 1;
  // for (int item : v) cout << item << " "; cout << endl;

  int ans = 0;
  do {
    v = shuffle(v, n, s);
    // for (int item : v) cout << item << " "; cout << endl;

    ans++;
  } while (!isGood(v, n));
  cout << ans << endl;

  return 0;
}