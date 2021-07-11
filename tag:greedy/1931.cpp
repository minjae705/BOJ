#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <pair<int, int>> v;
int main() {
	int n, s, e;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		v.push_back(make_pair(e,s));
	}
	sort(v.begin(), v.end());
  
	int ans, time;
	ans = 1;
	time = v[0].first;
	for (int i = 1; i < n;i++) {
		if (v[i].second >= time) {
			time = v[i].first;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
