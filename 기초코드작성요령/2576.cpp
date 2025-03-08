#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x, res = 0, min = 100;

  for (int i = 0; i < 7; i++) {
    cin >> x;

    if (x & 1) {
      res += x;
      
      if (x < min) min = x;
    }
  }

  if (res == 0) cout << -1;
  else cout << res << '\n' << min;
}