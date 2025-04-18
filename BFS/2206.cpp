#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[1002];
// 0 : 벽을 부시지 않은 이동 거리
// 1 : 벽을 한 번 부수고 난 후의 이동 거리
int dist[1002][1002][2];
int n, m;
queue<tuple<int, int, int>> Q;

int bfs() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      dist[i][j][0] = dist[i][j][1] = -1;
  }

  Q.push({0, 0, 0});
  dist[0][0][0] = 0;

  while (!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    int x, y, broken;
    tie(x, y, broken) = cur;
    if (x == n-1 && y == m-1) return dist[x][y][broken] + 1;
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
        Q.push({nx, ny, broken});
        dist[nx][ny][broken] = dist[x][y][broken] + 1;
      }
      if (board[nx][ny] == '1' && !broken && dist[nx][ny][1] == -1) {
        Q.push({nx, ny, 1});
        dist[nx][ny][1] = dist[x][y][broken] + 1;
      }
    }
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> board[i];
  cout << bfs();
}