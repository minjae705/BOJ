#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, ans;
bool vis[1001];
int adj[1001][1001];
queue<int> q;


void dfs(int x) {
	vis[x] = 1;
	for (int i = 1; i <= n; i++) {
		if (adj[x][i] && !vis[i]) {
			vis[i] = 1;
			dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			ans += 1;
		}
	}
	cout << ans;
	return 0;
}
