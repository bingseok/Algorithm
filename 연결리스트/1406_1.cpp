#include <bits/stdc++.h>
using namespace std;

const int MX = 600005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(char c, int addr) {
  dat[unused] = c;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];

  if (nxt[addr] != -1) pre[nxt[addr]] = unused;
  nxt[addr] = unused;
  unused++;
}

void erase(int addr) {
  if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
  nxt[pre[addr]] = nxt[addr];
}

void traversal() {
  int cur = nxt[0];
  while (cur != -1) {
    cout << dat[cur];
    cur = nxt[cur];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  string in;
  cin >> in;
  int cursor = 0;
  for (auto c : in) {
    insert(c, cursor);
    cursor++;
  }

  int m;
  cin >> m;
  while (m--) {
    char cmd;
    cin >> cmd;
    if (cmd == 'L') {
      if (pre[cursor] != -1) cursor = pre[cursor];
    }
    else if (cmd == 'D') {
      if (nxt[cursor] != -1) cursor = nxt[cursor];
    }
    else if (cmd == 'B') {
      if (pre[cursor] != -1) {
        erase(cursor);
        cursor = pre[cursor];
      }
    }
    else if (cmd == 'P') {
      char t;
      cin >> t;
      insert(t, cursor);
      cursor = nxt[cursor];
    }
  }

  traversal();
}