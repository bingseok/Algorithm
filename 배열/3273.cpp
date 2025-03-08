#include <bits/stdc++.h>
using namespace std;
int freq[2000001];
int arr[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    freq[arr[i]] = 1;
  }

  int x, cnt = 0;
  cin >> x;

  for (int i = 0; i < n; i++) {
    if (freq[x-arr[i]]) cnt++;
  }

  cout << cnt / 2;
}