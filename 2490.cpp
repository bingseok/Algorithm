#include <bits/stdc++.h>
using namespace std;
string s = "DCBAE";

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 3; i++) {
    int res = 0;
    for (int j = 0; j < 4; j++) {
      int t;
      cin >> t;
      res += t;
    }
    cout << s[res] << '\n';
  }
}