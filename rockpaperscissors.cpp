// Author: razouq
// Date: 2023-11-23 10:04
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

int solve(string m1, string m2) {
  if (m1 == m2) return 0;
  if (m1 == "rock" && m2 == "scissors") return 1;
  if (m1 == "scissors" && m2 == "paper") return 1;
  if (m1 == "paper" && m2 == "rock") return 1;
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie();

  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;

    int k;
    cin >> k;

    int m = k * n * (n - 1) / 2;
    vector<int> games(n + 1, 0);
    vector<int> wins(n + 1, 0);
    while (m--) {
      int p1, p2;
      string m1, m2;
      cin >> p1 >> m1 >> p2 >> m2;
      int result = solve(m1, m2);
      if (result == 0) continue;
      games[p1]++;
      games[p2]++;
      
      if (result == 1) wins[p1]++;
      if (result == -1) wins[p2]++;
    }

    for (int i = 1; i <= n; i++) {
      if (games[i] == 0) cout << '-' << endl;
      else cout << fixed << setprecision(3) << (double)wins[i] / games[i] << endl;
    }
    cout << endl;
  }
  return 0;
}