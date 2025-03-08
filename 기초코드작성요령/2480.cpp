#include <bits/stdc++.h>
using namespace std;
int arr[4];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int b;
  for (int i = 0; i < 3; i++) cin >> arr[i];
  sort(arr, arr + 3);

  // 같은 눈 3개
  if (arr[0] == arr[2])
    b = 10000 + arr[0]*1000;
  else if (arr[1] == arr[0] || arr[1] == arr[2])
    b = 1000 + arr[1]*100;
  else b = arr[2]*100;

  cout << b;
}