#include <bits/stdc++.h>
using namespace std;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int board[102][102][102]; // 높이, 세로, 가로로 순으로
int dist[102][102][102];
int m, n, h;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n >> h;
  for (int i = 0; i < h; i++) 
    for (int j = 0; j < n; j++) 
      for (int k = 0; k < m; k++) 
        cin >> board[i][j][k];
      

  queue<tuple<int, int, int>> Q;

  // board가 1, -1이면 dist는 0
  // board가 0이면 dist는 -1
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (board[i][j][k] == 1) Q.push({i, j, k});
        if (board[i][j][k] == 0) dist[i][j][k] = -1;
      }
    }
  }

  while (!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    int z, x, y; // z : 높이, x : 세로, y : 가로
    tie(z, x, y) = cur;
    for (int dir = 0; dir < 12; dir++) {
      int nz = z + dz[dir];
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nz][nx][ny] == -1 || dist[nz][nx][ny] >= 0) continue;
      Q.push({nz, nx, ny});
      dist[nz][nx][ny] = dist[z][x][y] + 1;
    }
  }

  int mx = 0;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (dist[i][j][k] == -1) {
          cout << -1;
          return 0;
        }
        mx = max(mx, dist[i][j][k]);
      }
    }
  }

  cout << mx;
}