#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t, v, e;
vector<int> graph[20002];
int nodecolor[20002];

void dfs(int x, int color) {
	nodecolor[x] = color;
	for (int i = 0; i < graph[x].size(); i++) {
		int next = graph[x][i];
		if (!nodecolor[next])
			dfs(next, 3 - color);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i = 1; i <= v; i++)
			if (nodecolor[i] == 0)
				dfs(i, 1);

		bool ans = true;
		for (int i = 1; i <= v; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				int next = graph[i][j];
				if (nodecolor[i] == nodecolor[next])
					ans = false;
			}
		}

		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";

		for (int i = 0; i < 20002; i++)
			graph[i].clear();
		memset(nodecolor, 0, sizeof(nodecolor));
	}
	return 0;
}
