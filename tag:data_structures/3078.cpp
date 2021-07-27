#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> q[21];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    string name;
    int len;
    long long ans=0;
    
    for(int i=1; i<=n; i++){
        cin >> name;
        len = name.length();
        while(!q[len].empty() && i - q[len].front() > k)
            q[len].pop();
        ans += q[len].size();
        q[len].push(i);
    }
    
    cout << ans;
    return 0;
}
