#include <bits/stdc++.h>
using namespace std;
int arr[6];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; i++) cin >> arr[i];
  sort(arr, arr + 5);

  int sum = 0;
  for (int i = 0; i < 5; i++) sum += arr[i];
  sum /= 5;

  cout << sum << '\n' << arr[2];
}