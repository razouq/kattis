// Author: razouq
// Date: 2023-11-23 15:08
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
  
  int t;
  cin >> t;
  while(t--) {
    int w, h, shots;
    cin >> w >> h >> shots;

    vector<vector<string>> players(2, vector<string>(h));
    vector<int> ships(2, 0);
    for (int p = 0; p < 2; p++) {
      for (int i = 0; i < h; i++) {
        cin >> players[p][i];
        for (int j = 0; j < w; j++) {
          if (players[p][i][j] == '#') {
            ships[p]++;
          }
        }
      }
    }

    // player 1 start
    int turn = 0;
    bool end = false;
    for (int i = 0; i < shots; i++) {
      // w, h
      int x, y;
      cin >> x >> y;
      if (end) continue;
      if (players[1 - turn][h - 1 - y][x] == '#') {
        players[1 - turn][h - 1 - y][x] = '_';
        ships[1 - turn]--;
        // if the playr hits the last ship of the openent
        if (ships[1 - turn] == 0) {
          if (turn == 1) end = true;
          turn = 1 - turn;
        }
      } else {
        if (turn == 1 && (ships[0] == 0 || ships[1] == 0)) {
          end = true;
        }
        turn = 1 - turn;
      }
    }
    if (ships[0] && !ships[1]) cout << "player one wins" << endl;
    else if (!ships[0] && ships[1]) cout << "player two wins" << endl;
    else cout << "draw" << endl;
  }
  return 0;
}