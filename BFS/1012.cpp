#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int t, m, n, k, x, y;
int board[52][52];
bool vis[52][52];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while (t--) {
    cin >> m >> n >> k;
    int cnt = 0;
    while (k--) {
      cin >> x >> y;
      board[x][y] = 1;
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!board[i][j] || vis[i][j]) continue;
        cnt++;
        
        queue<pair<int, int>> Q;
        Q.push({i, j});
        vis[i][j] = 1;
        
        while (!Q.empty()) {
          auto cur = Q.front(); Q.pop();
          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (!board[nx][ny] || vis[nx][ny]) continue;
            Q.push({nx, ny});
            vis[nx][ny] = 1;
          }
        }
      }
    }

    cout << cnt << '\n';
  }
}