#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  int ans = 0;
  while (t--) {
    cin >> s;
    stack<char> st;
    bool isValid = true;
    for (auto c : s) {
      if (!st.empty() && st.top() == c) st.pop();
      else st.push(c);
    }
    if (st.empty()) ans++;
  }
  cout << ans;
}