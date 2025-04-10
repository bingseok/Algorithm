#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int board[502][502];
bool vis[502][502];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++)
      cin >> board[i][j];

  int cnt = 0; // 그림의 개수
  int mx = 0; // 그림의 최대값
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 0 || vis[i][j]) continue;
      cnt++;
      queue<pair<int, int>> Q;
      Q.push({i, j});
      vis[i][j] = 1;
      
      int size = 0;
      while (!Q.empty()) {
        auto cur = Q.front(); Q.pop(); size++;
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (board[nx][ny] == 0 || vis[nx][ny]) continue;
          Q.push({nx, ny});
          vis[nx][ny] = 1;
        }
      }

      mx = max(mx, size);
    }
  }

  cout << cnt << '\n' << mx;
}