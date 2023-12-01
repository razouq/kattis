// Author: razouq
// Date: 2023-11-23 17:09
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
  
  int n1;
  int n2;
  cin >> n1;
  cin >> n2;
 
  int clockWise = -1 * (n1 - n2 + 360) % 360;
  int counterClockWise =  (n2 - n1 + 360) % 360;
  if (abs(counterClockWise) < abs(clockWise)) {
    cout << counterClockWise << endl;
  } else if (abs(counterClockWise) > abs(clockWise)) {
    cout << clockWise << endl;
  } else cout << abs(clockWise) << endl;
  return 0;
}