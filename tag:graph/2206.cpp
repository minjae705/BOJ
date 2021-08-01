#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;
#define Tuple tuple<int, int, int, int>
int n, m, nowx, nowy, nowb, nowd, nxtx, nxty;
int map[1001][1001];
bool visited[1001][1001][2]; //[][][0] 안부수고 이동 [][][1] 부수고 이동
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
queue<Tuple> q; // i j broken distance
string s;

bool isSafe(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < m);
}

void bfs(int i, int j) {
	q.push({ i,j,0,1 });
	visited[i][j][0] = 1;

	while (!q.empty()) {
		Tuple now = q.front();
		tie(nowx, nowy, nowb, nowd) = now;
		q.pop();

		if (nowx == n - 1 && nowy == m - 1) 
			return;
		
		for (int k = 0; k < 4; k++) {
			nxtx = nowx + dx[k];
			nxty = nowy + dy[k];

			if (!isSafe(nxtx, nxty))
				continue;
			if (!nowb && map[nxtx][nxty]) {
				visited[nxtx][nxty][1] = 1;
				q.push({ nxtx,nxty,1,nowd + 1 });
			}
			if (!map[nxtx][nxty] && !visited[nxtx][nxty][nowb]) {
				visited[nxtx][nxty][nowb] = 1;
				q.push({ nxtx,nxty,nowb,nowd + 1 });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}
	bfs(0, 0);
	if (n == 1 && m == 1)
		cout << 1;
	else if (nowx == n - 1 && nowy == m - 1)
		cout << nowd;
	else
		cout << -1;
}
