#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int ans = 0;
  while (n--) {
    string s;
    cin >> s;
    stack<char> st;
    bool isValid = true;
    for (auto c : s) {
      if (!st.empty() && st.top() == c) st.pop();
      else st.push(c);
    }
    if (!st.empty()) isValid = false;
    if (isValid) ans++;
  }
  cout << ans;
}