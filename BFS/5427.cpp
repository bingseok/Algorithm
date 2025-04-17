#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int t, w, h;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[1002];
int dist1[1002][1002]; // 불의 이동 거리
int dist2[1002][1002]; // 상근이의 이동 거리

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while (t--) {
    cin >> w >> h;

    queue<pair<int, int>> Q1; // 불의 큐
    queue<pair<int, int>> Q2; // 상근이의 큐

    for (int i = 0; i < h; i++) {
      fill(dist1[i], dist1[i] + w, -1);
      fill(dist2[i], dist2[i] + w, -1);
      cin >> board[i];
    }
    
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (board[i][j] == '*') {
          Q1.push({i, j});
          dist1[i][j] = 0;
        }
        if (board[i][j] == '@') {
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
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (board[nx][ny] == '#' || dist1[nx][ny] != -1) continue;
        Q1.push({nx, ny});
        dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
      }
    }

    bool isSuccess = false;
    // 상근이의 BFS
    while (!Q2.empty()) {
      auto cur = Q2.front(); Q2.pop();
      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
          // 빌딩 밖으로 탈출하는 경우
          cout << dist2[cur.X][cur.Y] + 1 << '\n';
          isSuccess = true;
          break;
        }
        if (board[nx][ny] == '#' || dist2[nx][ny] != -1) continue;
        if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
        Q2.push({nx, ny});
        dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
      }
    }

    if (!isSuccess) cout << "IMPOSSIBLE" << '\n';
  }
}