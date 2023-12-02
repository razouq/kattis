// Author: razouq
// Date: 2023-12-02 06:15
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

  int testCase = 1;
  while (true) {
    int w, n;
    cin >> w >> n;
    if (w == 0 && n == 0) break;
    vector<string> s(n);
    vector<int> c(n);
    int cMax = 0;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      cin >> c[i];
      cMax = max(cMax, c[i]);
    }

    int currentWidth = 0;
    int currentHeight = 0;
    int totalHeight = 0;
    int maxFont = 0; // height
    for (int i = 0; i < n; i++) {
      int font = 8 + ceil((double)40 * (c[i] - 4) / (cMax - 4)); // height
      int width = ceil((double)9 * s[i].size() * font / 16);

      // first word in this line
      if (currentWidth == 0) {
        currentWidth = width;
        maxFont = font;
      } else {
        if (currentWidth + 10 + width <= w) {
          currentWidth += 10 + width;
          maxFont = max(maxFont, font);
        } else {
          currentWidth = width;
          totalHeight += maxFont;
          maxFont = font;
        }
      }
    }
    totalHeight += maxFont;
    cout << "CLOUD " << testCase++ << ": " << totalHeight << endl;
  }
  return 0;
}