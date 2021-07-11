#include <iostream>
#define MOD 1000000007
using namespace std;

long long int dp[1551][1551];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
        for(int j=1;j<=i;j++)
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
    }
    long long int ans=0;
    for(int i=0;i<n;i++){
        int j=n-i-1;
        if((i+j*2)%3!=1) continue;
        ans = (ans+dp[n-1][i])%MOD;
    }
    cout << ans;
}
