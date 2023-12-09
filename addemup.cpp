// Author: razouq
// Date: 2023-12-08 20:14
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

vi rev(10);

bool isReversable(ll n) {
  // palindrom
  bool palin = true;
  string s = to_string(n);
  int a = 0;
  int b = s.size() - 1;
  while (a < b) {
    if (s[a] != s[b]) palin = false;
    a++;
    b--;
  }
  while (n) {
    int c = n % 10;
    if (rev[c] == -1) return false;
    n /= 10;
  }
  return !palin;
}

ll getReverse(ll n) {
  ll ans = 0;
  int sizeN = to_string(n).size();
  ll k = powl(10, sizeN-1);
  while (n) {
    int c = n % 10;
    ans += k * rev[c];
    k /= 10;
    n /= 10;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie();

  rev = { 0, 1, 2, -1, -1, 5, 9, -1, 8, 6 };

  ll n, s;
  cin >> n >> s;
  vl a;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    a.PB(x);
    if (isReversable(x)) {
      a.PB(getReverse(x));
    }
  }
  sort(a.begin(), a.end());
  // for (int i = 0; i < a.size(); i++) cout << a[i] << " "; cout << endl;
  bool found = false;
  for (int i = 0; i < a.size(); i++) {
    ll value = s - a[i];
    auto it = lower_bound(a.begin(), a.end(), value);
    if (it != a.end() && *it == value) {
      auto nextIt = ++it;
      if (value != a[i] && (!isReversable(a[i]) || !isReversable(value) || getReverse(value) != a[i] || (nextIt != a.end() && *nextIt == value))) {
        found = true;
      }
      if (value == a[i] && (nextIt != a.end() && *nextIt == value)) {
        found = true;
      }
    }
  }
  if (found) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}