#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long a, b;
  cin >> a >> b;
  
  if (a == b) cout << 0 << '\n';
  else
    cout << abs(a-b) - 1 << '\n';

  for (long long i = min(a, b) + 1; i < max(a, b); i++) {
    cout << i << ' ';
  }
}