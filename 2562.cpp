#include <bits/stdc++.h>
using namespace std;
int arr[10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i <= 9; i++) cin >> arr[i];

  int max = arr[1], idx = 1;
  for (int i = 2; i <= 9; i++) {
    if (arr[i] > max) {
      max = arr[i];
      idx = i;
    }
  }

  cout << max << '\n' << idx;
}