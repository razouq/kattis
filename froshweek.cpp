// Author: razouq
// Date: 2023-12-09 16:02
// #include<flamers.h>
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

template<class TIn>
using indexed_set = tree<
  TIn, null_type, less<TIn>,
  rb_tree_tag, tree_order_statistics_node_update>;

ll inversions(vector<int>& v) {
  indexed_set<int> s;
  for (int i = 0; i < v.size(); i++) {
    s.insert(v[i]);
  }

  ll ans = 0;
  for (auto i : v) {
    ans += s.order_of_key(i);
    s.erase(i);
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie();

  int n;
  cin >> n;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  cout << inversions(v) << endl;

  return 0;
}