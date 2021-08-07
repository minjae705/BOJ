#include <iostream>
using namespace std;

int n;
int inorder[100001], postorder[100001], index[100001];

void preorder(int inbegin, int inend, int postbegin, int postend) {
	if (inbegin > inend || postbegin > postend)
		return;
  
	int root = postorder[postend];
	cout << root << ' ';
  
	preorder(inbegin, index[root] - 1, postbegin, postbegin + index[root] - inbegin - 1);
	preorder(index[root] + 1, inend, postbegin + index[root] - inbegin, postend - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
		index[inorder[i]] = i;
	}
	for (int i = 0; i < n; i++)
		cin >> postorder[i];
  
	preorder(0, n - 1, 0, n - 1);
	cout << '\n';
	return 0;
}
