#include <bits/stdc++.h>
using namespace std;

int t, n;
string p, arr;
deque<int> dq;

void parse_arr(string arr, int n) {
  int cur = 0;
  for (int i = 1; i + 1 < arr.size(); i++) {
    if (arr[i] != ',')
      cur = cur * 10 + (arr[i] - '0');
    else {
      dq.push_back(cur);
      cur = 0;
    }
  }
  if (cur != 0) dq.push_back(cur);
}

void print_arr(deque<int> dq) {
  cout << '[';
  for (int i = 0; i < dq.size(); i++) {
    cout << dq[i];
    if (i + 1 != dq.size()) cout << ",";
  }
  cout << "]\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while (t--) {
    bool rev = false; // 뒤집으면 true
    bool err = false; // empty일 때 pop
    cin >> p;
    cin >> n;
    cin >> arr;
    parse_arr(arr, n);
    for (auto c : p) {
      if (c == 'R') rev = !rev;
      else if (c == 'D') {
        if (dq.empty()) {
          err = true;
          break;
        }
        if (rev) dq.pop_back();
        else dq.pop_front();
      }
    }
    if (err) cout << "error\n";
    else {
      if (rev) reverse(dq.begin(), dq.end());
      print_arr(dq);
    }
    dq.clear();
  }
}