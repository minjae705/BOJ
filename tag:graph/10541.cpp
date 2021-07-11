#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t, n, ans;
vector<int> graph[1001];
bool visited[1001];

void dfs(int x) {
	visited[x] = 1;
	int next = graph[x][0];
	if (!visited[next])
		dfs(next);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		memset(graph, 0, sizeof(graph));
		memset(visited, false, sizeof(visited));
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			graph[i].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
