#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int sum = 0;
  while (n--) {
    string s;
    cin >> s;
    stack<char> st;
    for (auto c : s) {
      if (!st.empty() && st.top() == c) st.pop();
      else st.push(c);
    }
    if (st.empty()) sum++;
  }
  cout << sum;
}