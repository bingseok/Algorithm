#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n-1; i++) {
    for (int j = 0; j < i; j++) cout << '*';
    for (int k = 0; k < 2 * (n - i); k++) cout << ' ';
    for (int l = 0; l < i; l++) cout << '*';
    cout << '\n';
  }

  for (int i = 0; i < 2 * n; i++) cout << '*';
  cout << '\n';

  for (int i = n - 1; i >= 1; i--) {
    for (int j = 0; j < i; j++) cout << '*';
    for (int k = 0; k < 2 * (n - i); k++) cout << ' ';
    for (int l = 0; l < i; l++) cout << '*';
    cout << '\n';
  }
}