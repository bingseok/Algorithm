#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    string s;
    getline(cin, s);
    if (s == ".") break;
    stack<char> st;
    bool no = false;
    for (auto c : s) {
      if (c == '(' || c == '[') st.push(c);
      else if (c == ')') {
        if (st.empty() || st.top() != '(') no = true;
        else st.pop();
      }
      else if (c == ']') {
        if (st.empty() || st.top() != '[') no = true;
        else st.pop();
      }
    }
    if (!st.empty()) no = true;
    
    if (no) cout << "no\n";
    else cout << "yes\n";
  }
}