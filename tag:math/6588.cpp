#include <iostream>
using namespace std;

bool a[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 2; i <= 1000000; i++) {
		a[i] = true;
	}
	a[1] = false;

	for (int i = 2; i*i <= 1000000; i++) {
		if (a[i] == true) {
			for (int j = i + i; j <= 1000000; j += i)
				a[j] = false;
		}
	}

	while (1) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		for (int i = n; i > 0; i--) {
			if (a[i] && a[n - i]) {
				cout << n << " = " << n - i << " + " << i << '\n';
				break;
			}
		}
	}
	return 0;
}
