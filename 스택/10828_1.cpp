#include <bits/stdc++.h>
using namespace std;

const int MX = 10005;
int dat[MX];
int pos = 0;

void push(int x) {
  dat[pos++] = x;
}

void pop() {
  pos--;
}

int top() {
  return dat[pos-1];
}

int empty() {
  return pos == 0;
}

int size() {
  return pos;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  while (n--) {
    string cmd;
    cin >> cmd;
    if (cmd == "push") {
      int t;
      cin >> t;
      push(t);
    }
    else if (cmd == "pop") {
      if (empty()) cout << -1 << '\n';
      else {
        cout << top() << '\n';
        pop();
      }
    }
    else if (cmd == "size") {
      cout << pos << '\n';
    }
    else if (cmd == "empty") {
      cout << empty() << '\n';
    }
    else if (cmd == "top") {
      if (empty()) cout << -1 << '\n';
      else cout << top() << '\n';
    }
  }
}