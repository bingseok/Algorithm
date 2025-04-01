#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  stack<char> st;
  int sum = 0; // 계속해서 더해질 값
  int num = 1; // 곱해질 값
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      st.push(s[i]);
      num *= 2;
    }
    else if (s[i] == '[') {
      st.push(s[i]);
      num *= 3;
    }
    else if (s[i] == ')') {
      if (st.empty() || st.top() != '(') {
        cout << 0;
        return 0;
      }
      if (s[i-1] == '(') sum += num;
      st.pop();
      num /= 2;
    }
    else if (s[i] == ']') {
      if (st.empty() || st.top() != '[') {
        cout << 0;
        return 0;
      }
      if (s[i-1] == '[') sum += num;
      st.pop();
      num /= 3;
    }
  }

  if (!st.empty()) cout << 0;
  else cout << sum;
}