#include <bits/stdc++.h>
using namespace std;

int t, n, rev = 1, err = -1; // rev가 -1이면 역방향, 1이면 정방향
string p, input;
deque<int> dq;

void add_deque(string input, int n) {
  if (input.size() == 2) return;
  for (int i = 1; i < input.size(); i++) {
    int res = 0;
    while (input[i] != ',' && input[i] != ']') {
      res += res * 10 + (input[i] - '0');
      i++;
    }
    dq.push_back(res);
  }
}

void print_deque() {
  cout << '[';
  for (int i = 0; i < dq.size(); i++) {
    cout << dq[i];
    if (i != dq.size() - 1) cout << ',';
  }
  cout << "]\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while (t--) {
    cin >> p;
    cin >> n;
    cin >> input;
    add_deque(input, n);
    for (auto c : p) {
      if (c == 'R') rev *= -1;
      if (c == 'D') {
        if (dq.empty()) {
          err = 1;
          break;
        }
        if (rev == -1) {
          dq.pop_back();
        } else dq.pop_front();        
      }
    }
    if (err == 1) cout << "error\n";
    else {
      if(rev == -1) reverse(dq.begin(), dq.end());
      print_deque();
    }
    rev = 1; err = -1;
    dq.clear();
  }
}