#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
deque<int> dq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) dq.push_back(i);

  while (m--) {
    int x;
    cin >> x;
    int idx; // 덱에서 x가 위치한 인덱스
    for (int i = 0; i < dq.size(); i++) {
      if (dq[i] == x) idx = i;
    }
    int pre = idx;
    int nxt = dq.size() - idx - 1;
    if (pre <= nxt) {
      while (dq.front() != x) {
        dq.push_back(dq.front());
        dq.pop_front();
        cnt++;
      }
      dq.pop_front();
    }
    else {
      while (dq.front() != x) {
        dq.push_front(dq.back());
        dq.pop_back();
        cnt++;
      }
      dq.pop_front();
    }
  }

  cout << cnt;
}