#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> s;
#define X first
#define Y second
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  s.push({100000001, 0});
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int top;
    cin >> top;
    while (s.top().X < top) s.pop();
    cout << s.top().Y << ' ';
    s.push({top, i});
  }
}