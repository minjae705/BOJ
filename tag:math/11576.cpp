#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> org;
stack<int> chg;
int main() {
	int a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		int tmp;
		cin >> tmp;
		org.push_back(tmp);
	}

	int p = pow(a, n - 1);
	int ten = 0;
	for (int i = 0; i < n;i++) {
		ten += org[i] * p;
		p /= a;
	}
	while (ten > 0) {
		chg.push(ten % b);
		ten /= b;
	}
	while (!chg.empty()) {
		cout << chg.top() << ' ';
		chg.pop();
	}
	return 0;
}
