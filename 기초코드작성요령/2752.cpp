#include <bits/stdc++.h>
using namespace std;
int arr[10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 3; i++) cin >> arr[i];
  sort(arr, arr + 3);
  for (int i = 0; i < 3; i++) cout << arr[i] << ' ';

}