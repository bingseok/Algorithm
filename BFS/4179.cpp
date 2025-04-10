#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int r, c;
string board[1002];
int dist1[1002][1002]; // 불의 이동거리
int dist2[1002][1002]; // 지훈이의 이동거리
queue<pair<int, int>> Q1; // 불의 큐
queue<pair<int, int>> Q2; // 지훈이의 큐
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    fill(dist1[i], dist1[i] + c, -1);
    fill(dist2[i], dist2[i] + c, -1);
  }

  for (int i = 0; i < r; i++)
    cin >> board[i];
  
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (board[i][j] == 'F') {
        Q1.push({i, j});
        dist1[i][j] = 0;
      }
      if (board[i][j] == 'J') {
        Q2.push({i, j});
        dist2[i][j] = 0;
      }
    }
  }

  // 불의 BFS
  while (!Q1.empty()) {
    auto cur = Q1.front(); Q1.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if (board[nx][ny] == '#' || dist1[nx][ny] != -1) continue;
      Q1.push({nx, ny});
      dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
    }
  }

  // 지훈이의 BFS
  while (!Q2.empty()) {
    auto cur = Q2.front(); Q2.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
        cout << dist2[cur.X][cur.Y] + 1;
        return 0;
      }
      if (board[nx][ny] == '#') continue;
      if (dist2[nx][ny] != -1 || dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
      Q2.push({nx, ny});
      dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
    }
  }

  cout << "IMPOSSIBLE";
}