#include <bits/stdc++.h>
using namespace std;

const int MX = 5005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num) {
  dat[unused] = num;
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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  int n, k;
  cin >> n >> k;

  int cursor = 0;
  for (int i = 1; i <= n; i++) {
    insert(cursor, i);
    cursor++;
  }

  nxt[n] = 1;
  pre[1] = n;

  cursor = 0;
  cout << '<';
  while (n--) {
    for (int i = 0; i < k; i++) {
      cursor = nxt[cursor];
    }

    cout << dat[cursor];
    erase(cursor);
    if (n != 0) cout << ", ";
  }
  cout << '>';
}