#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	while (1) {
		stack<char> stk;
		string str;
		bool flag = true;
		getline(cin, str);
		if (str.length() == 1 && str[0] == '.')
			break;
    
		for (int i = 0; i < str.length();i++) {
			if (str[i] == '(')
				stk.push('(');
			
      else if(str[i] == '[')
				stk.push('[');
			
      else if (str[i] == ')') {
				if (!stk.empty() && stk.top() == '(')
					stk.pop();
				else {
					flag = false;
					break;
				}
			}
			
      else if (str[i] == ']') {
				if (!stk.empty() && stk.top() == '[')
					stk.pop();
				else {
					flag = false;
					break;
				}
			}
		}
    
		if (flag && stk.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}
