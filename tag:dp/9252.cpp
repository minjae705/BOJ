#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int l1 = s1.length(), l2 = s2.length();
	int ans = -1;
	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';
	string ansstr = "";
	while (l1 != 0 && l2 != 0) {
		if (dp[l1][l2] == dp[l1 - 1][l2])
			l1 -= 1;
		else if (dp[l1][l2] == dp[l1][l2 - 1])
			l2 -= 1;
		else {
			ansstr += s1[l1 - 1];
			l1 -= 1;
			l2 -= 1;
		}
	}
	reverse(ansstr.begin(), ansstr.end());
	cout << ansstr;
	return 0;
}
