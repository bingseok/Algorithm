#include <bits/stdc++.h>
using namespace std;
int arr[10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int sum = 0;
  for (int i = 0; i < 9; i++) {
    cin >> arr[i];
  } 
  sort(arr, arr + 9);

  for (int i = 0; i < 9; i++) sum += arr[i];
  sum -= 100;

  for (int i = 0; i < 8; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (arr[i] + arr[j] == sum) {
        for (int k = 0; k < 9; k++) {
          if (k == i || k == j) continue;
          cout << arr[k] << '\n';
        }          
        return 0;
      }
    }
  }
}