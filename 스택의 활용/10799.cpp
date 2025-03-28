#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  stack<char> st;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') st.push(s[i]); // 막대의 개수
    else if (s[i] == ')') {
      if (s[i-1] == '(') {// 레이저 일 경우
        st.pop();
        ans += st.size();
      }
      else {
        st.pop();
        ans++;
      }
    }
  }
  cout << ans;
}