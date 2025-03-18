#include <bits/stdc++.h>
using namespace std;
int freq[10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  while (n > 0) {
    freq[n%10]++;
    n/=10;
  }

  freq[9] = (freq[6] + freq[9] + 1) / 2;
  freq[6] = 0;
  cout << *max_element(freq, freq + 10);
}