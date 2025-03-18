#include <bits/stdc++.h>
using namespace std;
string ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<int> s;
  int n;
  cin >> n;
  int pos = 1; // 다음에 push할 원소
  while (n--) {
    int x;
    cin >> x;
    for (; pos <= x; pos++) {
      s.push(pos);
      ans += "+\n";
    }
    if (s.top() != x) {
      cout << "NO";
      return 0;
    }
    s.pop();
    ans += "-\n";
  }

  cout << ans;
}

3 4