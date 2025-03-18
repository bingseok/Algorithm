#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  vector<int> V, ans;
  for (int i = 1; i <= N; i++) V.push_back(i);

  for (int i = 0; ans.size() < N; i++) {
    if (i % K == K - 1) ans.push_back(V[i]);
    else V.push_back(V[i]);
  }

  cout << "<";
  for (int i = 0; i < N; i++) {
    if (i == N-1) cout << ans[i];
    else cout << ans[i] << ", ";
  }
  cout << ">";
}