#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for (int i = 0; i < 3; i++) {
    int cnt = 0;
    for (int j = 0; j < 4; j++) {
      int t;
      cin >> t;
      if (t == 1) cnt++;
    }
    if (cnt == 4) cout << 'E';
    else if (cnt == 3) cout << 'A';
    else if (cnt == 2) cout << 'B';
    else if (cnt == 1) cout << 'C';
    else if (cnt == 0) cout << 'D';
  }
}