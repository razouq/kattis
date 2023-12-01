// Author: razouq
// Date: 2023-12-01 09:59
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

vector<string> split(string s, char c) {
  vector<string> res;
  string cur = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == c) {
      res.push_back(cur);
      cur = "";
    } else cur += s[i];
  }
  res.push_back(cur);
  return res;
}

pair<int, char> getValue(string s) {
  int val = 0;
  char c = ' ';
  string nbr = "";
  for (int i = 0; i < s.size() - 1; i++) {
    nbr += s[i];
  }
  c = s[s.size() - 1];
  val = stoi(nbr);
  return { val, c };
}

int main() {
  string s;
  bool end = false;
  double dayCalories = 0;
  double fatDayCalories = 0;
  while (getline(cin, s)) {
    if (s == "-") {
      if (end) break;
      cout <<round((fatDayCalories) / dayCalories * 100) << "%" << endl;
      end = true;
      dayCalories = 0;
      fatDayCalories = 0;
      continue;
    } else {
      end = false;
    }
    vector<string> v = split(s, ' ');
    double fatMealPercent = 0;
    double fatMealCalories = 0;
    double othersMealCalories = 0;
    double othersMealPercent = 0;

    for (int i = 0; i < v.size(); i++) {
      pair<int, char> p = getValue(v[i]);
      // FAT
      if (i == 0) {
        if (p.S == 'g') {
          fatMealCalories += p.F * 9;
        } else if (p.S == 'C') {
          fatMealCalories += p.F;
        } else if (p.S == '%') {
          fatMealPercent += p.F;
        }
      }
      // PROTEIN & SUGAR & STARCH
      if (i == 1 || i == 2 || i == 3) {
        if (p.S == 'g') {
          othersMealCalories += p.F * 4;
        } else if (p.S == 'C') {
          othersMealCalories += p.F;
        } else if (p.S == '%') {
          othersMealPercent += p.F;
        }
      }
      // ALCOHOL
      if (i == 4) {
        if (p.S == 'g') {
          othersMealCalories += p.F * 7;
        } else if (p.S == 'C') {
          othersMealCalories += p.F;
        } else if (p.S == '%') {
          othersMealPercent += p.F;
        }
      }
    }
    double totalMealCalories = (double)((othersMealCalories + fatMealCalories) * 100 / (100 - (fatMealPercent + othersMealPercent)));
    if (fatMealPercent) {
      fatDayCalories += fatMealPercent * totalMealCalories / 100;
    } else {
      fatDayCalories += fatMealCalories;
    }
    dayCalories += totalMealCalories;

  }
  return 0;
}