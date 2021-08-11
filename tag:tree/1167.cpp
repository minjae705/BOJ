#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n, target, diameter = -98765432;
vector<pair<int,int>> v[100001];
bool visited[100001];
 void dfs(int x, int s) {
	visited[x] = 1;
	if (diameter < s) {
		diameter = s;
		target = x;
	}
	for (auto m : v[x]) {
		int next = m.first;
		int nextval = m.second;
		if (!visited[next])
			dfs(next, s + nextval);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  
	cin >> n;
	for (int i = 0; i < n; i++) {
		int r;
		cin >> r;
		while (1) {
			int l, d;
			cin >> l;
			if (l == -1)
				break;
			cin >> d;
			v[r].push_back({ l,d });
		}
	}
  
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(target, 0);
	cout << diameter;
	return 0;
}
