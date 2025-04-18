#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dist[302][302];
int t, l;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while (t--) {
    cin >> l;
    int curX, curY, distX, distY;
    cin >> curX >> curY >> distX >> distY;
    for (int i = 0; i < l; i++) fill(dist[i], dist[i] + l, -1);
    queue<pair<int, int>> Q;
    Q.push({curX, curY});
    dist[curX][curY] = 0;
    while (dist[distX][distY] == -1) {
      auto cur = Q.front(); Q.pop();
      for (int dir = 0; dir < 8; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
        if (dist[nx][ny] != -1) continue;
        Q.push({nx, ny});
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      }
    }
    
    cout << dist[distX][distY] << '\n';
  }
}