#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int sc;
  cin >> sc;
  if (sc >= 90 && sc <= 100) cout << 'A';
  else if (sc >= 80) cout << 'B';
  else if (sc >= 70) cout << 'C';
  else if (sc >= 60) cout << 'D';
  else cout << 'F';
}