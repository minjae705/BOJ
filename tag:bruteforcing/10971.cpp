#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int w[11][11];
vector<int> v;
int ans = 98765432;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> w[i][j];
    for(int i=0;i<n;i++)
        v.push_back(i);
    
    do{
        int cost = 0;
        bool flag = true;
        for(int i=0;i<n-1;i++){
            if(w[v[i]][v[i+1]]==0){
                flag = false;
                break;
            }
            cost += w[v[i]][v[i+1]];
        }
        if(w[v[n-1]][v[0]]==0)
            flag = false;
        else
            cost += w[v[n-1]][v[0]];
        
        if(flag)
            ans = min(ans, cost);
    }while(next_permutation(v.begin(), v.end()));
    
    cout << ans;
    return 0;
}
