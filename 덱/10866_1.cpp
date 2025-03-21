#include <bits/stdc++.h>
using namespace std;

const int MX = 10005;
int dat[2*MX+1];
int head = MX, tail = MX;
int n;

void push_front(int x) {
  dat[--head] = x;
}

void push_back(int x) {
  dat[tail++] = x;
}

void pop_front() {
  head++;
}

void pop_back() {
  tail--;
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
    string op;
    cin >> op;
    if (op == "push_front") {
      int x; cin >> x;
      push_front(x);
    }
    else if (op == "push_back") {
      int x; cin >> x;
      push_back(x);
    }
    else if (op == "pop_front") {
      if (head == tail) cout << -1 << '\n';
      else {
        cout << front() << '\n';
        pop_front();
      }
    }
    else if (op == "pop_back") {
      if (head == tail) cout << -1 << '\n';
      else {
        cout << back() << '\n';
        pop_back();
      }
    }
    else if (op == "size") {
      cout << tail-head << '\n';
    }
    else if (op == "empty") {
      if (head == tail) cout << 1 << '\n';
      else cout << 0 << '\n';
    }
    else if (op == "front") {
      if (head == tail) cout << -1 << '\n';
      else cout << front() << '\n';
    }
    else if (op == "back") {
      if (head == tail) cout << -1 << '\n';
      else cout << back() << '\n';
    }
  }
}
