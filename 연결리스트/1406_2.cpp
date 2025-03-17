#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  list<char> L;
  string in;
  cin >> in;
  for (auto c : in) L.push_back(c);
  auto it = L.end();

  int m;
  cin >> m;
  while (m--) {
    char cmd;
    cin >> cmd;
    if (cmd == 'L') {
      if (it != L.begin()) it--;
    }
    else if (cmd == 'D') {
      if (it != L.end()) it++;
    }
    else if (cmd == 'B') {
      if (it != L.begin()) {
        it--;
        it = L.erase(it);
      }
    }
    else if (cmd == 'P') {
      char t;
      cin >> t;
      L.insert(it, t);
    }
  }

  for (auto i : L) cout << i;
  
}