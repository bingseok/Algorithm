#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
string board[1001];
int dist1[1001][1001]; // 불의 이동 거리
int dist2[1001][1001]; // 지훈이의 이동거리
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int r, c;
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    cin >> board[i];
    fill(dist1[i], dist1[i] + c, -1);
    fill(dist2[i], dist2[i] + c, -1);
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (board[i][j] == 'F') {
        dist1[i][j] = 0;
        q1.push({i, j});
      }   
      else if (board[i][j] == 'J') {
        dist2[i][j] = 0;
        q2.push({i, j});
      }   
    }
  }

  // 불의 BFS
  while (!q1.empty()) {
    auto cur = q1.front(); q1.pop();
    for (int dir = 0; dir < 4; dir++) {
      int x = cur.X + dx[dir];
      int y = cur.Y + dy[dir];
      if (x < 0 || x >= r || y < 0 || y >= c) continue;
      if (board[x][y] == '#' || dist1[x][y] >= 0) continue;
      dist1[x][y] = dist1[cur.X][cur.Y] + 1;
      q1.push({x, y});
    }
  }


  // 지훈이의 BFS
  while (!q2.empty()) {
    auto cur = q2.front(); q2.pop();
    for (int dir = 0; dir < 4; dir++) {
      int x = cur.X + dx[dir];
      int y = cur.Y + dy[dir];
      if (x < 0 || x >= r || y < 0 || y >= c) continue;
      if (board[x][y] == '#' || dist2[x][y] >= 0) continue;
      dist2[x][y] = dist2[cur.X][cur.Y] + 1;
      if (dist1[x][y] <= dist2[x][y]) dist2[x][y] = -1;
      else q2.push({x, y});
    }
  }

  int ans = -1 ;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (board[i][j] == '#') continue;
      ans = max(ans, dist2[i][j]);
    }
  }

  cout << ans + 1;
}