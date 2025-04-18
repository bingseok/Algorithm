#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m;
  cin >> m;
  while (m--) {
    list<char> L;
    auto cursor = L.end();
    
    string s;
    cin >> s;
    for (auto c : s) {
      if (c == '<') {
        if (cursor != L.begin()) cursor--;
      }
      else if (c == '>') {
        if (cursor != L.end()) cursor++;
      }
      else if (c == '-') {
        if (cursor != L.begin()) {
          cursor--;
          cursor = L.erase(cursor);
        }
      }
      else {
        L.insert(cursor, c);
      }
    }

    for (auto i : L) cout << i;
    cout << '\n';
  }
}