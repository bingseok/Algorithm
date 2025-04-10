#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[1002][1002];
int dist[1002][1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;

  for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);

  queue<pair<int, int>> Q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 1) {
        Q.push({i, j});
        dist[i][j] = 0;
      }
      if (board[i][j] == -1) dist[i][j] = 0;
    }
  }

  int ans = 0;
  while (!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny] == -1 || dist[nx][ny] != -1) continue;
      Q.push({nx, ny});
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
    }
  }

  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dist[i][j] == -1) {
        cout << -1;
        return 0;
      }
      mx = max(mx, dist[i][j]);
    }
  }

  cout << mx;
}