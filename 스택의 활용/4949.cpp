#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(true) {
    string s;
    getline(cin, s);
    if (s == ".") break;
    stack<char> st;
    bool isValid = true;
    for (auto c : s) {
      if (c == '(') st.push(c);
      else if (c == '[') st.push(c);
      else if (c == ')') {
        if (st.empty() || st.top() != '(') {
          isValid = false;
          break;
        }
        st.pop();
      }
      else if (c == ']') {
        if (st.empty() || st.top() != '[') {
          isValid = false;
          break;
        }
        st.pop();
      }
    }
    if (!st.empty()) isValid = false;
    if (isValid) cout << "yes\n";
    else cout << "no\n";
  }
}