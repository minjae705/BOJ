#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int func(int p, int n) {
	int cnt = 0, loop = 1;
	while (1) {
		if (n / pow(p, loop) > 0) {
			cnt += n / pow(p, loop);
			loop++;
		}
		else
			break;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	cout << min(func(2, n) - func(2, m) - func(2, n - m), func(5, n) - func(5, m) - func(5, n - m));
}
