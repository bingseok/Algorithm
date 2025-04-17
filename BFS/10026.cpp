#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[102];
bool vis[102][102];
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> board[i];

  // 적록색맹이 아닌 사람이 봤을 때때 구역의 개수
  queue<pair<int, int>> Q1;
  int cnt1 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (vis[i][j]) continue;
      Q1.push({i, j});
      vis[i][j] = 1;
      cnt1++;
      while (!Q1.empty()) {
        auto cur = Q1.front(); Q1.pop();
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (vis[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;
          Q1.push({nx, ny});
          vis[nx][ny] = 1;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);

  // 적록색맹인 사람이 봤을 때 구역의 개수
  queue<pair<int, int>> Q2;
  int cnt2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (vis[i][j]) continue;
      Q2.push({i, j});
      vis[i][j] = 1;
      cnt2++;
      while (!Q2.empty()) {
        auto cur = Q2.front(); Q2.pop();
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (vis[nx][ny]) continue;
          if (board[cur.X][cur.Y] == 'B') {
            if (board[nx][ny] != board[cur.X][cur.Y]) continue;
          }
          else {
            if (board[nx][ny] == 'B') continue;
          }
          Q2.push({nx, ny});
          vis[nx][ny] = 1;
        }
      }
    }

  }

  cout << cnt1 << ' ' << cnt2;
}