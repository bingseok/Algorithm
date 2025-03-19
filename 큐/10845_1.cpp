#include <bits/stdc++.h>
using namespace std;

const int MX = 10005;
int dat[MX];
int head = 0, tail = 0;
int n;
string cmd;

void push(int x) {
  dat[tail++] = x;
}

void pop() {
  head++;
}

int size() {
  return tail-head;
}

bool empty() {
  return tail==head;
}

int front() {
  return dat[head];
}

int back() {
  return dat[tail-1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while (n--) {
    cin >> cmd;
    if (cmd == "push") {
      int x; cin >> x;
      push(x);
    } 
    else if (cmd == "pop") {
      if (empty()) cout << "-1\n";
      else {
        cout << front() << '\n';
        pop();
      }
    }
    else if (cmd == "size") {
      cout << size() << '\n';
    }
    else if (cmd == "empty") {
      cout << empty() << '\n';
    }
    else if (cmd == "front") {
      if (empty()) cout << "-1\n";
      else cout << front() << '\n';
    }
    else if (cmd == "back") {
      if (empty()) cout << "-1\n";
      else cout << back() << '\n';
    }
  }
}