#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<int> s; // [ ] ( ) -4 -3 -2 -1
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '[') s.push(-4);
		if (str[i] == '(') s.push(-2);
		if (str[i] == ']') {
			int tmp = 0;
			while (1) {
				if (s.empty()) {
					cout << 0;
					return 0;
				}
				int ttmp = s.top();
				s.pop();
				if (ttmp > 0)
					tmp += ttmp;
				if (ttmp == -4) {
					if (!tmp)
						tmp = 1;
					s.push(tmp * 3);
					break;
				}
				if (ttmp == -2) {
					cout << 0;
					return 0;
				}
			}
		}
		if (str[i] == ')') {
			int tmp = 0;
			while (1) {
				if (s.empty()) {
					cout << 0;
					return 0;
				}
				int ttmp = s.top();
				s.pop();
				if (ttmp > 0)
					tmp += ttmp;
				if (ttmp == -2) {
					if (!tmp)
						tmp = 1;
					s.push(tmp * 2);
					break;
				}
				if (ttmp == -4) {
					cout << 0;
					return 0;
				}
			}
		}
	}
	int t = 0;
	while (!s.empty()) {
		if (s.top() < 0) {
			cout << 0;
			return 0;
		}
		t += s.top();
		s.pop();
	}
	cout << t;
	return 0;
}
