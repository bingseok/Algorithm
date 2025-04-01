#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<char> st;
  string s;
  cin >> s;
  int sum = 0; // 총 막대기 조각의 수
  int num = 0; // 막대기의 수
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      num++;
    }
    else { // s[i] == ')'
      if (s[i-1] == '(') { // 레이저일 경우
        num--;
        sum += num;
      }
      else { // 막대기의 끝인 경우
        sum++;
        num--;
      } 
    }
  }

  cout << sum;
}